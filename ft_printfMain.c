/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfMain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:03:53 by psleziak          #+#    #+#             */
/*   Updated: 2021/06/01 20:11:42 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int				i;
	int				q;
	va_list			sptr;
	struct s_format	pointer;

	i = -1;
	q = 0;
	va_start(sptr, s);
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_struct_inicializer(&pointer);
			ft_flags((char *)s, &i, &pointer);
			ft_width((char *)s, &i, &pointer, sptr);
			ft_precision((char *)s, &i, &pointer, sptr);
			ft_flag_check(&pointer);
			ft_letter(s[i], &pointer, sptr, &q);
		}	
		else
			ft_write(s[i], &q, &pointer);
	}	
	va_end(sptr);
	return (q);
}

int main()
{
	ft_printf("Mam na imie %s, mam %d lat, a w hexadecimal to %X", "Przemek", 28, 28);
	return 0;
}
