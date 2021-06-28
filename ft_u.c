/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:02:31 by psleziak          #+#    #+#             */
/*   Updated: 2021/05/31 19:59:02 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(unsigned int n)
{
	int				i;
	unsigned int	z;
	char			x;
	char			*itoa_buffer;

	if (n == 0)
		return (ft_strdup("0"));
	z = n;
	i = 0;
	while (z > 0)
	{
		z = z / 10;
		i++;
	}	
	itoa_buffer = (char *)malloc((i + 1) * sizeof(char));
	if (itoa_buffer == 0)
		return (0);
	itoa_buffer[i] = '\0';
	while (i--)
	{	
		x = (n % 10 + '0');
		itoa_buffer[i] = x;
		n = n / 10;
	}
	return (itoa_buffer);
}

void	ft_u(struct s_format *p, va_list sptr, int *q)
{
	int				i;
	int				y;
	unsigned int	u;
	char			*z;

	u = va_arg(sptr, unsigned int);
	if (u == 0 && p->precision == 0 && p->width == 0)
		return ;
	z = ft_itoa_u(u);
	y = ft_strlen(z);
	if (!p->minus)
		ft_width_d(p, y, q, u);
	if (p->precision > y)
		ft_precision_2(p, y, q);
	if (p->precision == 0 && u == 0)
		y = 0;
	i = -1;
	while (++i < y)
		ft_write(z[i], q, p);
	if (p->minus)
		ft_width_d(p, y, q, u);
	free(z);
}
