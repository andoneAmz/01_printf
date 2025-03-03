/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamezque <aamezque@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:19:41 by aamezque          #+#    #+#             */
/*   Updated: 2025/02/03 12:19:45 by aamezque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_log(unsigned int base, int n)
{
	int	i;

	i = 0;
	while (n / base)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	ft_pow(int base, int exp)
{
	int	i;
	int	sol;

	sol = 1;
	i = 0;
	while (i < exp)
	{
		sol *= base;
		i++;
	}
	return (sol);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	printf("%c", c); //write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	printf("%s", s); //write(1, s, ft_strlen(s));
}

int	is_instr(char c, char *str) 
{
	while (*str && c != *str)
		str++;
	return (c == *str);
}

void	ft_putstrlen(char *s, size_t n)
{
	size_t	i;
	i = 0;
	while (i < n)
	{
		ft_putchar(s[i]);
		i++;
	}
    //write(1, s, ft_strlen(s));
}

void	putchar_times(char c, int n)
{
	if (n <= 0)
		return ;
	printf("%c", c);
    //write(1, c, 1);
	putchar_times(c, n - 1);
}

int	format_isvalid(t_format *f)
{
	if (!f->type)
		return (0);
    return (1);
}

char *format_malloc(t_format *f, size_t size)
{
	if (f->buffer_size >= size)
		return (f->buffer);
	free(f->buffer);
	f->buffer = malloc(size);
	if (f->buffer == NULL)
	{
		f->buffer_size = 0;
		return (NULL);
	}
	f->buffer_size = size;
	return (f->buffer);
}

void	format_initialize(t_format *f)
{
		printf("this worked");
	f->align = 0;
	f->sign = 0;
	f->width = 0;
	f->precision = -1;
	f->alt_format = 0;
	f->length = 0;
	f->type = 0;
	if (f->buffer == NULL)
		format_malloc(f, 1024);

}

int	parse_format(char **s, t_format *f)
{
	char	*c; 
	int		n;

	c = *s;
	format_initialize(f);
	if (*c == '+' || *c == ' ')
	{
		f->sign = *c;
		c++;
	}
	if (*c == '-' || *c == '0')
	{
		f->align = *c;
		c++;
	}
	n = 0;
	while (*c >= '0' && *c <= '9')
	{
		n = n * 10 + (*c - '0');
		c++;
	}
	f->width = n; 
	if (*c == '.')
	{
		c++;
		n = 0;
		while (*c >= '0' && *c <= '9')
		{
			n = n * 10 + (*c - '0');
  			c++;
		}   
		f->precision = n;
	}
	if (*c == '#')
	{
		f->alt_format = *c;
		c++;
	}
	while (is_instr(*c, "hlLz"))
	{
		f->length += *c;
		c++;
	}
	if (is_instr(*c, "diupxXcs"))
		f->type = *c;
	if (format_isvalid(f))
		*s = c;
	return (1);
}



void ft_uitoa(unsigned int n, int b, char *buff)
{
	size_t	l;
	int		u;
	char	*sol;

	l = ft_log(b, n) + 1;
	u = ft_pow(b, l - 1);
	l = 0;
	while (u)
	{
		if (n / u <= 9)
			buff[l] = '0' + n / u;
		else
			buff[l] = 'a' + (n / u) - 10;
		n = n % u;
		u = u / b;
		l++;
	}
	sol[l] = '\0';
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
char	*str_merge(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*sol;

	l1 = 0;
	if (s1 != NULL)
		l1 = ft_strlen(s1);
	l2 = 0;
	if (s2 != NULL)
		l2 = ft_strlen(s2);
	sol = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!sol)
		return (NULL);
	if (l1)
		ft_memcpy((void *)sol, (void *)s1, l1);
	if (l2)
		ft_memcpy((void *)&sol[l1], (void *)s2, l2);
	sol[l1 + l2] = '\0';
	free(s1);
	free(s2);
	return (sol);
}

void	ft_print_number(t_format *f)
{
	char	*str;
	int		l;
	int		z;
	int		b;
	int		s;

	str = f->buffer;
	l = ft_strlen(str);
	b = 0;
	z = 0;
	s = 0;
	if ((is_instr(f->type, "dip") && f->sign) /*|| n < 0*/)
		s++;
	if(f->type == 'p')
		s += 2;
	if (f->precision > l)
		z = f->precision - l;
	if (f->width > z + l)
		b = f->width - (z + l + s);
	if (f->align == '0' && f->precision == -1)
	{
		z = b;
		b = 0;
	}
	if (f->align != '-')
		putchar_times(' ', b);
	if (is_instr(f->type, "dip") && f->sign /*&& n >= 0*/)
		ft_putchar(f->sign);
	else if (is_instr(f->type, "dip") /*&& n < 0*/)
		ft_putchar('-');
	if (f->type == 'p' || (f->type == 'x' && f->alt_format))
		printf("0x");
	else if (f->type == 'X' && f->alt_format)
		printf("0X");
	putchar_times('0', z);
	ft_putstr(str);
	if (f->align == '-')
		putchar_times(' ', b);
}

void	ft_print_chr(t_format *f, int c)
{
    int	l;

    l = 1;
	if (f->align == '0' || !f->align)
		putchar_times(' ', f->width - l);
	ft_putchar(c);
	if (f->align == '-')
		putchar_times(' ', f->width - l);
}

void	ft_print_str(t_format *f, char *s)
{
    int	l;

    l = 0;
    while (s[l])
		l++;
    if (f->precision != -1 && f->precision < l)
		l = f->precision;
	if (f->align == '0' || !f->align)
		putchar_times(' ', f->width - l);
	if (f->precision == -1 || f->precision > l)
		ft_putstr(s);
	else
		ft_putstrlen(s, f->precision); // replace with write
	if (f->align == '-')
		putchar_times(' ', f->width - l);
}

void parse_argument(t_format *f, va_list args)
{
	char type = f->type;
	unsigned long int p;
	size_t len;
	
	if (type == 'd' || type == 'i' || type == 'u')
		ft_uitoa(va_arg(args, int), 10, f->buffer);
	else if (type == 'x' || type == 'X')
		ft_uitoa(va_arg(args, unsigned int), 16, f->buffer);
	else if (type == 'p')
	{
		p = va_arg(args, void *);
		if (p > 32 * 32)
			ft_uitoa(p / (32 * 32), 16, f->buffer);
		len = ft_strlen(f->buffer);
		ft_uitoa(p % (32 * 32), 16, f->buffer[len]);
	}
	else if (type == 'c')
		f->buffer[0] = va_arg(args, int);
	else if (type == 's')
	{
		if (f->buffer != NULL)
			free(f->buffer);
		f->buffer = va_arg(args, char *);
		f->buffer_size = ft_strlen(f->buffer) + 1;
		printf("%zu",f->buffer_size);
	}
}

void	ft_printf(const char *format, ...)
{
	va_list		args;
	static t_format	f = {0, 0, 0, 0, 0, 0, 0, 0, NULL};
	const char	*p;

	va_start(args, format);
	p = format;
	printf("dfgasfdsf");
	while (*p != '\0')
	{
		if (*p == '%' && *(p + 1) != '\0')
		{
			p++;
			parse_format(&p, &f);
			parse_argument(&f, args);
			if (is_instr(f.type, "diupxX"))
				ft_print_number(&f);
			else if (f.type == 'c')
				ft_print_chr(&f, f.buffer);
			else if (f.type == 's')
				ft_print_str(&f, f.buffer);
			else
				ft_putchar(*p);
		}
		else
			ft_putchar(*p);
		p++;
	}
	va_end(args);
}
