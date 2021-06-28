/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:47:58 by psleziak          #+#    #+#             */
/*   Updated: 2021/05/31 19:57:41 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(struct s_format *p, va_list sptr, int *q, char s)
{
	char	d;
	int		y;

	if (s == 'c')
		d = va_arg(sptr, int);
	y = 1;
	if (p->width > 0 && p->minus == 0)
		ft_width_d(p, y, q, d);
	if (s == '%')
		ft_write('%', q, p);
	else
		ft_write(d, q, p);
	if (p->width > 0 && p->minus > 0)
		ft_width_d(p, y, q, d);
}
