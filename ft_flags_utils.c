/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfMain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:03:53 by psleziak          #+#    #+#             */
/*   Updated: 2021/06/01 20:08:10 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_check(struct s_format *p)
{
	if (p->width < 0)
	{
		p->minus = 1;
		p->width = -p->width;
	}
	if (p->minus == 1)
		p->zero = 0;
	if (p->precision > -1)
		p->zero = 0;
}

void	ft_letter(char s, struct s_format *p, va_list sptr, int *q)
{
	if (s == 'c' || s == '%')
		ft_c(p, sptr, q, s);
	else if (s == 's')
		ft_s(p, sptr, q);
	else if (s == 'p')
		ft_p(p, sptr, q, s);
	else if (s == 'd' || s == 'i')
		ft_d(p, sptr, q);
	else if (s == 'x' || s == 'X')
		ft_x(p, sptr, q, s);
	else if (s == 'u')
		ft_u(p, sptr, q);
	else
		return ;
}

void	ft_precision(char *s, int *i, struct s_format *p, va_list sptr)
{
	int	sum2;

	sum2 = 0;
	if (s[*i] == '.')
	{
		p->precision = 0;
		(*i)++;
		if (s[*i] == '*')
		{
			p->precision = va_arg(sptr, int);
			(*i)++;
		}
		else
		{
			while (s[*i] >= '0' && s[*i] <= '9')
			{
				sum2 = sum2 * 10 + s[*i] - '0';
				(*i)++;
			}
			p->precision = sum2;
		}
	}
}

void	ft_width(char *s, int *i, struct s_format *p, va_list sptr)
{
	int	sum;
	int	sign;

	sum = 0;
	sign = 1;
	if ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '*')
	{
		if (s[*i] == '*')
		{
			p->width = va_arg(sptr, int);
			(*i)++;
		}
		else
		{
			if (s[*i] == '-')
				sign = -1;
			while (s[*i] >= '0' && s[*i] <= '9')
			{
				sum = sum * 10 + s[*i] - '0';
				(*i)++;
			}
			p->width = sum * sign;
		}
	}
}

void	ft_flags(char *s, int *i, struct s_format *p)
{
	while (s[*i] == '-' || s[*i] == '0')
	{
		if (s[*i] == '-')
		{
			p->minus = 1;
			(*i)++;
		}
		if (s[*i] == '0')
		{
			p->zero = 1;
			(*i)++;
		}
	}
}
