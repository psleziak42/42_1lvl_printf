/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:51:27 by psleziak          #+#    #+#             */
/*   Updated: 2021/05/31 22:03:37 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width_s(struct s_format *p, int y, int *q)
{
	int	i;

	i = -1;
	y = p->width - y;
	while (++i < y)
	{
		if (!p->zero)
			ft_write(' ', q, p);
		else
			ft_write('0', q, p);
	}
}

void	ft_s(struct s_format *p, va_list sptr, int *q)
{
	int		i;
	int		y;
	char	*z;
	char	*temp;

	temp = va_arg(sptr, char *);
	if (temp == NULL)
		z = "(null)";
	else
		z = temp;
	y = ft_strlen(z);
	if (p->precision > -1 && p->precision < y)
		y = p->precision;
	i = -1;
	if (!p->minus)
		ft_width_s(p, y, q);
	while (++i < y)
		ft_write(z[i], q, p);
	if (p->minus)
		ft_width_s(p, y, q);
}
