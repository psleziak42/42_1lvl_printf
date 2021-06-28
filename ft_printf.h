/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psleziak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:20:38 by psleziak          #+#    #+#             */
/*   Updated: 2021/06/03 14:20:41 by psleziak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

struct	s_format
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		sign;
	int		minus_d;
	char	letter;
};

int		ft_printf(const char *s, ...);
void	ft_flags(char *s, int *i, struct s_format *p);
void	ft_width(char *s, int *i, struct s_format *p, va_list sptr);
void	ft_precision(char *s, int *i, struct s_format *p, va_list sptr);
void	ft_letter(char s, struct s_format *p, va_list sptr, int *q);
void	ft_flag_check(struct s_format *p);
void	ft_c(struct s_format *p, va_list sptr, int *q, char s);
void	ft_s(struct s_format *p, va_list sptr, int *q);
void	ft_p(struct s_format *p, va_list sptr, int *q, char s);
void	ft_putchar(int i, char a);
int		ft_hexa_l(unsigned long int i, int *l);
int		ft_hexa_p(unsigned long int i, char a, int *q);
void	ft_x(struct s_format *p, va_list sptr, int *q, char s);
void	ft_u(struct s_format *p, va_list sptr, int *q);
void	ft_d(struct s_format *p, va_list sptr, int *q);
void	ft_precision_2(struct s_format *p, int y, int *q);
int		ft_width_minus(struct s_format *p, int y, int new_y, int *q);
void	ft_width_d(struct s_format *p, int y, int *q, int d);
void	ft_write(char c, int *q, struct s_format *p);
void	ft_struct_inicializer(struct s_format *p);

#endif
