/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:32:50 by psleziak          #+#    #+#             */
/*   Updated: 2021/05/31 19:58:35 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_other_y(unsigned int u, long int *y, struct s_format *p)
{
	if (u == 0)
		*y = 3;
	if (p->precision == 0)
		*y = 2;
}

void	ft_p(struct s_format *p, va_list sptr, int *q, char s)
{
	unsigned long int	u;
	long int			y;
	int					l;

	l = 0;
	u = va_arg(sptr, unsigned long int);
	if (u != 0)
		y = ft_hexa_l(u, &l) + 2;
	ft_other_y(u, &y, p);
	if (p->width > y && p->minus == 0)
		ft_width_d(p, y, q, u);
	write (1, "0x", 2);
	*q = *q + 2;
	if (u == 0 && p->precision == 0)
		return ;
	while (p->precision - l - 2 > 0)
		ft_write('0', q, p);
	if (u > 0)
		ft_hexa_p(u, s, q);
	else
		ft_write('0', q, p);
	if (p->width > y && p->minus > 0)
		ft_width_d(p, y, q, u);
}
