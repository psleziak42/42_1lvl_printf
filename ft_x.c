/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:54:41 by psleziak          #+#    #+#             */
/*   Updated: 2021/06/01 20:10:52 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x(struct s_format *p, va_list sptr, int *q, char s)
{
	int				y;
	int				l;
	unsigned int	x;

	l = 0;
	x = va_arg(sptr, unsigned long int);
	y = ft_hexa_l(x, &l);
	if (x == 0 && p->precision == 0 && p->width == 0)
		return ;
	if (x == 0)
		y = 1;
	if (!p->minus)
		ft_width_d(p, y, q, x);
	if (p->precision > y)
		ft_precision_2(p, y, q);
	if (x > 0)
		ft_hexa_p(x, s, q);
	else if (p->precision != 0)
		ft_write('0', q, p);
	if (p->minus)
		ft_width_d(p, y, q, x);
}
