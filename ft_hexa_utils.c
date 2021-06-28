/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:03:02 by psleziak          #+#    #+#             */
/*   Updated: 2021/05/31 20:21:38 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putchar(int i, char a)
{
	if (a == 'x' || a == 'p' || a == 'X')
	{
		if (i >= 10 && i <= 15 && (a == 'x' || a == 'p'))
		{
			i = i + 87;
			write(1, &i, 1);
		}
		else if (i >= 10 && i <= 15 && a == 'X')
		{
			i = i + 55;
			write(1, &i, 1);
		}
		else
		{
			i = i + '0';
			write(1, &i, 1);
		}
	}	
}

int	ft_hexa_l(unsigned long int i, int *l)
{
	if (i != 0)
	{
		(*l)++;
		ft_hexa_l(i / 16, l);
	}
	return (*l);
}

int	ft_hexa_p(unsigned long int i, char a, int *q)
{
	if (i != 0)
	{
		ft_hexa_p(i / 16, a, q);
		ft_putchar(i % 16, a);
		(*q)++;
	}
	return (*q);
}
