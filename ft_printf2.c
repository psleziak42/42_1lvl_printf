#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
//#include<ft_printf.h>
#include<libft.h>

struct	format
{
	int	minus;
	int	zero;
	int 	width;
	int	dot;
	int	precision;
};

void	ft_struct_inicializer(struct format *p)
{
	p->minus = 0;
	p->zero = 0;
	p->width = 0;
	p->dot = 0;
	p->precision = 0;
}

void	ft_putchar(int i, char a)
{
	if (a == 'x' || a == 'p')
	{
		if (i >=10 && i <= 15)
		{
			i = i + 87;
			write(1, &i, 1);
		}
		else
		{
			i = i + '0';
			write(1, &i, 1);
		}
	}
	if (a == 'X')
	{
		if (i >= 10 && i <= 15)
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

void	ft_hexa(unsigned long int i, char a)
{
	if (i != 0)
	{
		ft_hexa(i / 16, a);
		ft_putchar(i % 16, a);
	}
}


void	ft_format(char *s, int *j, struct format *p, va_list sptr)
{
	int i;
	int l;
	
	i = -1;
	l = 0;
	if (s[*j] == 'c')
	{
		if (p->width > 0)
		{
			if (p->minus > 0)
			{
				va_arg(sptr, int);
				while (++i < p->width)
					write(1, " ", 1);
			}
			else
			{
				while (i < p->width - 1)
				{
					write(1, " ", 1);
					i++;
				}
				va_arg(sptr, int);
			}	
		}
		else
			va_arg(sptr, int);
	}
// 0 nie moze byc z .		//s; 0 nie moze byc
// - nie moze byc z 0
// - z . nic nie zmienia
// 10.5 to '     00001'		
//-10.5 to '00001     '
//-10   to '1         '
//010   to '0000000001;
//.5    to '00001'
//

	else if (s[*j] == 'd'|| s[*j] == 'i') 
	{
		int o;
		int y;
		int u;
	//	int x;
		char *z;
		
		o = 0;
		u = va_arg(sptr, int);
		z = ft_itoa(u);
		y = ft_strlen(z);
		if (p->width > 0 && p->precision > 0)
		{
			if (p->zero > 1)
			{
				write(1, "error 0 81", 10);
			//	break;
			}
			if (p->minus > 0)
			{
				i = -1;
				if (y > p->precision)
				{
						while (++i < y)
							write(1, &z[i], 1);
						while (i++ < p->width)
							write(1, " ", 1);
				}
				else // tu tez trzeba dopisac dla precision > width
				{
					if (u < 0)
					{
						write(1, &z[o++], 1);
						while (++i < p->precision - y + 1)  
							write(1, "0", 1);
						i = -1;
						while (++i < y - 1)
							write(1, &z[o++], 1);
						i = -1;
						while(++i < p->width - p->precision)
								write(1, " ", 1);
					}
					else
					{
						while (++i < p->precision - y)  
							write(1, "0", 1);
						i = -1;
						while (++i < y)
							write(1, &z[o++], 1);
						i = -1;
						while(++i < p->width - p->precision)
							write(1, " ", 1);
					}
				}
			}
			else // tu jest do poprawy prawdopodobnie cos
			{
				i = -1;
				if (y > p->precision)
				{
					while (++i < p->width - y) 
						write(1, " ", 1);
					i = -1;
					while (++i < y)
						write(1, &z[i], 1);
				}
				else // y < precision
				{
					if (p->precision > p->width)
					{
						if (u < 0)
							write(1, &z[o++], 1);
						while (++i < p->precision - y + 1)
							write(1, "0", 1);
						i = -1;
						while (++i < y - 1) // dla 1 cyfry nie pasuje
							write(1, &z[o++], 1);
					}
					else
					{
						i = -1;
						while (++i < p->width - y)
							write(1, " ", 1);
						while (++i < p->precision - y)
							write(1, "0", 1);
						i = -1;
						while (++i < y)
							write(1, &z[i], 1);
					}
				}	
			}
		}
		else if (p->width > 0 && p->precision == 0)
		{
			if (p->zero > 0 && p->minus > 0)
			{
				write(1, "error -0 140", 8);
			//	break;
			}
			if (p->zero > 0)
			{
				i = -1;
				while (++i < p->width - y)
					write(1, "0", 1);
				i = -1;
				while (++i < y)
					write(1, &z[i], 1);
			}
			else if (p->minus > 0)
			{
				
				i = -1;
				while (++i < y)
					write(1, &z[i], 1);
				i = -1;
				while (++i < p->width - y)
					write(1, " ", 1);
			}
			else
			{
				i = 0;
				while(i < (p->width - y))
				{
					write(1, " ", 1);
					i++;
				}
					o = 0;
					while(i < p->width)
					{
						write(1, &z[o], 1);
						i++;
						o++;
					}
			}
		}
		else if (p->precision > 0 && p->width == 0)
		{
			if (p->zero > 0)
			{
				write(1, "error 0 161", 11);	
			//	break;
			}
			else
			{
				i = -1;
				if (u < 0)
				{
					write(1, &z[o++], 1);
					while (++i < p->precision - y + 1)
						write(1, "0", 1);
					i = -1;
					while (++i < y - 1)
						write(1, &z[o++], 1);
				}					
				else if (u > 0)	
				{
					while (++i < p->precision - y)
						write(1, " ", 1);
					i = -1;
					while (++i < y)
						write(1, &z[o++], 1);
				}	
			}
		}
		else
		{
			if (u == 0 && p->precision == 0)
				return;
			else
			{
				i = -1;
				while (++i < y)
					write(1, &z[i], 1);
			}
		}
	}
	else if (s[*j] == 'u')
	{
		int y;
		int u;
		char *z;
		
		u = va_arg(sptr, int);
		z = ft_itoa(u);
		y = ft_strlen(z);
	
		if (p->width > 0 && p->precision > 0)
		{
			if (p->zero > 1)
			{
				write(1, "error 0 81", 10);
			//	break;
			}
			if (p->minus > 0)
			{
				if (y > p->precision)
				{
					while (++i < y)
						write(1, &z[i], 1);
					while (i++ < p->width)
						write(1, " ", 1);
				}
				else 
				{
					while (++i < p->precision - y)
						write(1, "0", 1);
					i = -1;
					while (++i < y)
						write(1, &z[i], 1);
					i = -1;
					while(++i < p->width - p->precision)
							write(1, " ", 1);
				}
			}
			else 
			{
				if (p->precision < p->width)
				{
					while (++i < p->width - y) // tu jest blad
						write(1, " ", 1);
				}
				i = -1;
				while (++i < p->precision - y)
					write(1, "0", 1);
				i = 0;
				while (i < y)
					write(1, &z[i++], 1);	
			}
		}
		else if (p->width > 0 && p->precision == 0)
		{
			if (p->zero > 0 && p->minus > 0)
			{
				write(1, "error -0 140", 8);
			//	break;
			}
			if (p->zero > 0)
			{
				while (++i < p->width - y)
					write(1, "0", 1);
				i = -1;
				while (++i < y)
					write(1, &z[i], 1);
			}
			else if (p->minus > 0)
			{
				while (++i < y)
					write(1, &z[i], 1);
				i = -1;
				while (++i < p->width - y)
					write(1, " ", 1);
			}
			else
			{
				while(++i < p->width - y)
					write(1, " ", 1);
				i = -1;
				while(++i < y)
					write(1, &z[i], 1);
			}
		}
		else if (p->precision > 0 && p->width == 0)
		{
			if (p->zero > 0)
			{
				write(1, "error 0 161", 11);	
			//	break;
			}
			while (++i < p->precision - y)
				write(1, "0", 1);
			i = -1;
			while (++i < y)
				write(1, &z[i], 1);
		}
		else
		{
			if (u == 0 && p->precision == 0)
				return;
			while (++i < y)
				write(1, &z[i], 1);
		}
	}
	else if (s[*j] == 'x'|| s[*j] == 'X') // tu bedzie podobny problem jak z 'p' brakuje to jest unsigned long, ale nie jestem pewien 
	{
		int y;
		int u;
		
		u = va_arg(sptr, int);
		y = ft_hexa_l(u, &l);
		if (p->width > 0 && p->precision > 0)
		{
			if (p->zero > 1)
			{
				write(1, "error 0 81", 10);
			//	break;
			}
			if (p->minus > 0)
			{
				i = -1;
				if (y > p->precision)
				{
					ft_hexa(u, s[*j]);
					while(++i < p->width - y)
						write(1, " ", 1);
				}
				else 
				{
					while (++i < p->precision - y) // tutaj trzeba poprawic :)
						write(1, "0", 1);
					ft_hexa(u, s[*j]);
					while(++i < p->width - p->precision)
							write(1, " ", 1);
				}
			}
			else 
			{
				if (y > p->precision)
				{
					while (++i < p->width - y) 
						write(1, " ", 1);
					ft_hexa(u, s[*j]);
				}
				else
				{
					i = -1;
					while (++i < p->width - p->precision)
						write(1, " ", 1);
					i = -1;
					while (++i < p->precision - y)
						write(1, "0", 1);
					ft_hexa(u, s[*j]);			
				}
			}
		}
		else if (p->width > 0 && p->precision == 0)
		{
			if (p->zero > 0 && p->minus > 0)
			{
				write(1, "error -0 140", 8);
			//	break;/
			}
			if (p->zero > 0)
			{
				i = -1;
				while (++i < p->width - y)
					write(1, "0", 1);
				ft_hexa(u, s[*j]);
			}
			else if (p->minus > 0)
			{
				ft_hexa(u, s[*j]);
				while (++i < p->width - y)
					write(1, " ", 1);
			}
			else
			{
				while(++i < p->width - y)
					write(1, " ", 1);
				ft_hexa(u, s[*j]);
			}
		}
		else if (p->precision > 0 && p->width == 0)
		{
			if (p->zero > 0)
			{
				write(1, "error 0 161", 11);	
			//	break;
			}
			else
			{
				while (++i < p->precision - y)
					write(1, "0", 1);
				ft_hexa(u, s[*j]);
			}
		}
		else
		{
			if (u == 0 && p->precision == 0)
				return;
			ft_hexa(u, s[*j]);
		}
	}
//0 nie moze byc z s
//.5 ogranicza dlugosc stringu, jesli jest krotszy od precision to przepisuje sie caly i tyle
//width dodaje puste pola jesli string jest krotszy, jesli dluzszy przepisuje sie caly
//precision ogranicza string, a width uzupelnia brakujace pola pustymi znakami
//- powoduje wyrownianie do lewej
//* powoduje wczytanie argumentu va_arg;
	else if (s[*j] == 's')
	{
		int i;
		int y;
		char *z;

		z = va_arg(sptr, char *);
		y = ft_strlen(z);
		i = -1;
		if (p->zero > 0)
			write(1, "error 's', zero", 15);
		else if (p->precision > 0)
		{
			if (p->minus > 0)
			{
				while (++i < p->precision)
					write(1, &z[i], 1);
				i = -1;
				if (y > p->precision)
				{
					while (++i < p->width - p->precision)
						write(1, " ", 1);
				}
				else
				{
					while (++i < p->width - y)
						write(1, " ", 1);
				}
			}
			else
			{
				if (y > p->precision)
				{
					while (++i < p->width - p->precision)
						write(1, " ", 1);
				}
				else
				{
					while(++i < p->width - y)
						write(1, " ", 1);
				}
				i = -1;
				while (++i < p->precision)
					write(1, &z[i], 1);
			}
		}
		else if (p->width > 0)
		{
			if (p->minus > 0)
			{
				while (++i < y)
					write(1, &z[i], 1);	
				while (i++ < p->width)
					write(1, " ", 1);
			}
			else
			{
				while (++i < p->width - y)
					write(1, " ", 1);
				i = -1;
				while (++i < y)
					write(1, &z[i], 1);
			}
		}
		else
		{
			while (++i < y) // to cover null character //
				write(1, &z[i], 1);
		}
	}
//p 0 i precision = error
//dziala tylko width, gdy wiekszy niz numer to wstawia puste pola
//- dla wiekszedo width od hex numeru to wyrownanie do lewej
	else if (s[*j] == 'p')
	{
		unsigned long int u;
		long int y;
	
		u = va_arg(sptr, unsigned long int);
		y = ft_hexa_l(u, &l);
	//	printf("y = %ld\n", y);

		if (p->precision > 0 || p->zero > 0)
			write(1, "error precision/zero dla p", 26);
		if (p->width > 0)
		{
			if (p->minus > 0)
			{
				write(1, "0x", 2);
				ft_hexa(u, s[*j]);
				while (++i < p->width - 2 - y)
					write(1, " ", 1);
			}
			else
			{
				while (++i < p->width - 2 - y)
					write(1, " ", 1);
				write(1, "0x", 2);
				ft_hexa(u, s[*j]);
			}
		}
		else
		{
			write(1, "0x", 2);
			ft_hexa(u, s[*j]);
		}
	}	
}
			 
void	ft_flags(char *s, int *i, struct format *p, va_list sptr)
{
	int sum;
	sum = 0;
	(*i)++;
	while (!(s[(*i)] >= 'a' && s[(*i)] <= 'z') && !(s[(*i)] == 'X'))
	{
		//printf("d2: %d, ", *i);
		if (s[(*i)] == '-')	
		{
			p->minus = 1;
			(*i)++;
		}
		else if (s[*i] == '0')
		{
			p->zero = 1;
			(*i)++;
		}
		else if ((s[*i] >= '0' && s[(*i)] <= '9') || s[*i] == '*')
		{
			if (s[*i] == '*')
			{
				p->width = va_arg(sptr, int);
				(*i)++;
			}
			else
			{
				while (s[*i] >= '0' && s[(*i)] <= '9')
				{	
					sum = sum*10 + s[(*i)] - 48;
					(*i)++;
				}
				p->width = sum;
			}
		sum = 0;
		}
		else if (s[*i] == '.')
		{
			p->dot = '.';
			(*i)++;
			if (s[*i] == '*')
			{
				p->precision = va_arg(sptr, int);
				(*i)++;
			}
			else
			{
				while (s[*i] >= '0' && s[(*i)] <= '9')
				{
					sum = sum*10 + s[(*i)] - 48;
					(*i)++;
				}
				p->precision = sum;
			}
	//	printf("precision 5?, %d", p->precision);	
	//	(*i)++;	
		}
	}
//	printf("i na koncu2?: %d\n", (*i));
	//return *i;
}

int	ft_printf(const char *s, ...)
{
	int i;
	va_list sptr;
	struct	format	pointer;

	ft_struct_inicializer(&pointer);
	
	i = 0;
	va_start(sptr, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '%')
		{
			i++;
			write(1, &s[i++], 1);
			i++;
			continue;
		}
		if (s[i] == '%')
		{
			//printf("i before flags: %d\n", i);
			ft_flags((char *)s, &i, &pointer, sptr); 
			ft_format((char *)s, &i, &pointer, sptr);
			i++;
		}
		write(1, &s[i], 1);
		i++;			
	}
	va_end(sptr);
	return(i);
}

int main()
{
	int i;
	
	i = -12059;
	int j;
	int k;
	int l;
	int m;
	int n;
	
	i = -12059;
	j = -1;
	k = 12059;
	l = 103;
	m = 103204203;
	
	ft_printf("%10.20d siemanko\n", i);
	printf("%10.20d siemanko\n\n", i);

	ft_printf("sieanko %.0d.\n", 0);
	printf("sieanko %.0d.\n\n", 0);
	ft_printf("sieanko %-i.\n", i);
	printf("sieanko %-i.\n\n", i);

	ft_printf("sieanko %-.*d.\n", 20, j);
	printf("sieanko %-.*d.\n\n", 20, j);
	ft_printf("sieanko %.*i.\n", 20, j);
	printf("sieanko %.*i.\n\n", 20, j);

	ft_printf("sieanko %.*u.\n", 1, k);
	printf("sieanko %.*u.\n\n", 1, k);
	ft_printf("sieanko %*.*u.\n", 10, 2, k);
	printf("sieanko %*.*u.\n\n", 10, 2, k);

	ft_printf("sieanko %-*.*d.\n", 10, 20, l);
	printf("sieanko %-*.*d.\n\n", 10, 20, l);
	ft_printf("sieanko %-*.*i.\n", 10, 20, m);
	printf("sieanko %-*.*i.\n\n", 10, 20, m);
								
	ft_printf("sieanko %*p.\n", 100, &n);
	printf("sieanko %*p.\n\n", 100, &n);
	ft_printf("sieanko %-*p.\n", 10, &n);
	printf("sieanko %-*p.\n\n", 10, &n);
		
	return 0;

}
