/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:56:31 by psleziak          #+#    #+#             */
/*   Updated: 2021/05/31 22:21:23 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precision_d(struct s_format *p, int y, int *q, int *i)
{
	int	a;

	a = -1;
	if (p->sign)
	{
		y--;
		if (p->width - p->precision - 1 < 0 || p->minus)
		{
			ft_write('-', q, p);
			p->minus_d = 1;
			*i = 0;
		}
	}
	y = p->precision - y;
	while (++a < y)
		ft_write('0', q, p);
}

void	ft_d(struct s_format *p, va_list sptr, int *q)
{
	int		i;
	int		y;
	int		d;
	char	*z;

	i = -1;
	d = va_arg(sptr, int);
	if (d < 0)
		p->sign = 1;
	if (d == 0 && p->precision == 0 && p->width == 0)
		return ;
	z = ft_itoa(d);
	y = ft_strlen(z);
	if (!p->minus)
		ft_width_d(p, y, q, d);
	ft_precision_d(p, y, q, &i);
	if (p->precision == 0 && d == 0)
		y = 0;
	if (d < 0 && p->minus_d)
		i = 0;
	while (++i < y)
		ft_write(z[i], q, p);
	if (p->minus)
		ft_width_d(p, y, q, d);
	free(z);
}
