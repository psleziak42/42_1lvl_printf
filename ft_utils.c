/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:56:03 by psleziak          #+#    #+#             */
/*   Updated: 2021/06/01 20:10:27 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_2(struct s_format *p, int y, int *q)
{
	int	i;

	i = -1;
	if (p->sign)
	{
		y--;
		if (p->width - p->precision - 1 < 0)
			ft_write('-', q, p);
	}
	y = p->precision - y;
	while (++i < y)
		ft_write('0', q, p);
}

int	ft_width_minus(struct s_format *p, int y, int new_y, int *q)
{
	int	i;

	if (new_y <= 0)
	{
		if (p->precision == -1 && !p->minus_d)
			ft_write('-', q, p);
		return (new_y);
	}
	if (p->zero)
		ft_write('-', q, p);
	i = -1;
	if (p->precision - y + 1 > 0)
		new_y--;
	while (++i < new_y)
	{
		if (p->zero)
			ft_write('0', q, p);
		else
			ft_write(' ', q, p);
	}
	if (!p->zero && !p->minus)
		ft_write('-', q, p);
	return (new_y);
}

void	ft_width_d(struct s_format *p, int y, int *q, int d)
{
	int	i;
	int	new_y;

	new_y = 0;
	if (p->width == p->precision)
		return ;
	if (p->precision == 0 && d == 0)
		new_y = p->width;
	else if (p->precision > y)
		new_y = p->width - p->precision;
	else if (p->precision <= y)
		new_y = p->width - y;
	if (p->sign)
		ft_width_minus(p, y, new_y, q);
	if (new_y <= 0 || p->sign)
		return ;
	i = -1;
	while (++i < new_y)
	{
		if (p->zero)
			ft_write('0', q, p);
		else
			ft_write(' ', q, p);
	}
}

void	ft_write(char c, int *q, struct s_format *p)
{
	write(1, &c, 1);
	(*q)++;
	if (c == '-')
		p->minus_d = 1;
}

void	ft_struct_inicializer(struct s_format *p)
{
	p->minus = 0;
	p->zero = 0;
	p->width = 0;
	p->dot = 0;
	p->precision = -1;
	p->sign = 0;
	p->minus_d = 0;
	p->letter = 0;
}
