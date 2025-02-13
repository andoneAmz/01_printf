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
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_format
{
	char    align;      // defaut, left, zero padding
	char    sign;       // default, +, blankspace
	int     width;      // Field width
	int     precision;  // Precision for floats/strings
	int     alt_format; // Alternate format (#)
	char    mod;       // Length modifier (h, l, etc.)
	char    type;       // Format specifier (d, s, x, etc.)
} t_format;

int ft_log(int base, int n)
{
	int i;

	i = 0;
	while (n / base)
	{
		n /= base;
		i++;
	}
	return (i);
}

int ft_pow(int base, int exp)
{
	int i;
	int sol;

	sol = 1;
	i = 0;
	while (i < exp)
	{
		sol *= base;
		i++;
	}
	return (sol);
}
int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

size_t    ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_putchar(char c)
{
	printf("%c", c);
    //write(1, &c, 1);
}

void    ft_putstr(char *s)
{
	printf("%s", s);
    //write(1, s, ft_strlen(s));
}

void    ft_putstrlen(char *s, size_t n)
{
	size_t i;
	i = 0;
	while(i < n)
	{
		ft_putchar(s[i]);
		i++;
	}
    //write(1, s, ft_strlen(s));
}

void putchar_times(char c, int n)
{
	if (!n)
		return;
	printf("%c", c);
    //write(1, c, 1);
	putchar_times(c, n - 1);
}

int is_format_valid(t_format *f)
{

    return 1;
}

void format_print(t_format* f)
{
    if (!f->sign)
        printf("- nothing ");
    else if (f->sign == '+')
        printf("- positive sign ");
    else if (f->sign == ' ')
        printf("- space ");
    
    if (!f->align)
        printf("- default alineation ");
    else if (f->align == '-')
        printf("- align to the left ");
    else if (f->align == '0')
        printf("- zero padding / align to the right ");

    printf("- %d width ", f->width);

    printf("- %d precision", f->precision);

    if (f->type == 'd' || f->type == 'i')
        printf(" - ENTERO!");
    else if (f->type == 's')
        printf(" - STRING!");
    else if (f->type == 'f')
        printf(" - FLOAT!");
    else if (f->type == 'p')
        printf(" - POINTER!");
}

void    format_initialize(t_format* f)
{
    f->align = 0;
    f->sign = 0;
    f->width = 0;
    f->precision = -1;
    f->alt_format = 0;
    f->mod = 0;
    f->type = 0;
}

int parse_format(char **s, t_format* f)
{
	char* c; 
	int n;

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


    // modifiers
    {}

    //format_print(f);
    if (*c == 'd' || *c == 'i' || *c == 's' || *c == 'f' || *c == 'p')
        f->type = *c;
    // '#' alternative format for %x, %o, %f, %g

    if (c[0] == '#')
    {

    }
    *s = c;

    return 1;
}

char* ft_itoa(int n, int b)
{
	size_t 	l;
	int	u;
	char	*sol;

	l = ft_log(b, n) + 1;
	sol = (char *)malloc((l + 1) * sizeof(char));
	if (sol == NULL)
		return (NULL);
	u = ft_pow(b, l - 1);
	l = 0;
	while (u)
	{
		if (n / u <= 9)
			sol[l] = '0' + n / u;
		else
			sol[l] = 'a' + (n / u) - 10;
		n = n % u;
		u = u / b;
		l++;
	}
	sol[l] = '\0';
	return (sol);
}

// (%p)
void print_pointer(t_format* f, void* p)
{
	char* str;
	int l;
	int z;
	int b;
	int s;

	// MODIFICAR PARA COGER LO BUENOS
	str = ft_itoa(p, 16);
	l = ft_strlen(str);
	b = 0;
	z = 0;
	s = 0;

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


	putchar_times('0', z);
	ft_putstr(str);
	if (f->align == '-')
		putchar_times(' ', b);
}

// (%d, %u, %o, %x)
void print_integer(t_format* f, int n)
{
	char* str;
	int l;
	int z;
	int b;
	int s;

	if (f->type == 'd' || f->type == 'i')
		str = ft_itoa(abs(n), 10);
	else if (f->type == 'x' || f->type == 'X' || f->type == 'p')
		str = ft_itoa(abs(n), 16);
	l = ft_strlen(str);
	b = 0;
	z = 0;
	s = 0;
	if (((f->type == 'd' || f->type == 'i' || f->type == 'p') && f->sign) || n < 0)
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
	if ((f->type == 'd' || f->type == 'i' || f->type == 'p') && f->sign && n >= 0 )
		ft_putchar(f->sign);
	else if (n < 0)
		ft_putchar('-');
	if (f->type == 'p')
		printf("0x");
	putchar_times('0', z);
	ft_putstr(str);
	if (f->align == '-')
		putchar_times(' ', b);
}

// (%f, %e)
void print_floatingpoint(t_format* f, int n)
{

}

// (%s)
void print_a_string(t_format* f, char *s)
{
    int l;
    int i;

    l = 0;
    while (s[l])
    	l++;
    if (f->precision != -1 && f->precision < l)
          l = f->precision;

	if ((f->align == '0' || !f->align) && f->width > l)
                putchar_times(' ', f->width - l);
	if (f->precision == -1 || f->precision > l)
		ft_putstr(s);
	else 
		ft_putstrlen(s, f->precision); // replace with write
	if (f->align == '-' && f->width - l > 0)
		putchar_times(' ', f->width - l);
}

void    ft_puthex(void *h)
{
    unsigned long long b;
    unsigned long long p0;
    unsigned long long p1;
    int i;

    b = 16 * 16 * 16 * 16 * 16 * 16 * 16;
    p0 = (unsigned long long)h / b;
    p1 = (unsigned long long)h % b;
    while (b)
    {
        i = p0 / b;
        if (i < 10)
            ft_putchar('0' + i);
        else
            ft_putchar('A' + i - 10);
        p0 %= b;
        b /= 16;
    } 
    b = 16 * 16 * 16 * 16 * 16 * 16 * 16;
    while (b)
    {
        i = p1 / b;
        if (i < 10)
            ft_putchar('0' + i);
        else
            ft_putchar('A' + i - 10);
        p1 %= b;
        b /= 16;
    }
}

//%i Imprime un entero en base 10.
void    ft_putint(int n)
{
    int b;

    if (n < 0)
        ft_putchar('-');
    else
        n = -n;
    b = -1;
    while (n / 10 <= b)
        b *= 10;
    while (b)
    {
        ft_putchar('0' + n / b);
        n %= b;
        b /= 10;
    }
}

//%d Imprime un número decimal(base 10).
void    ft_putdec(float f)
{
    ft_putint((int)f);
    ft_putchar('.');
    f = (f - (int)f) * 1000000;
    if (f < 0)
        f = -f;
    ft_putint((int)f);
}

//%x Imprime un número hexadecimal(base 16) en minúsculas.
void    ft_puthex_minnor(void* h)
{
    unsigned int b;
    unsigned int p;
    int i;

    b = 1;
    p = (unsigned int)h;
    while (p / 16 >= b)
        b *= 16;
    while (b)
    {
        i = p / b;
        if (i < 10)
            ft_putchar('0' + i);
        else
            ft_putchar('a' + i - 10);
        p %= b;
        b /= 16;
    }
}

//%X Imprime un número hexadecimal(base 16) en mayúsculas.
void    ft_puthex_upper(void* h)
{
    unsigned int b;
    unsigned int p;
    int i;

    b = 1;
    p = (unsigned int)h;
    while (p / 16 >= b)
        b *= 16;
    while (b)
    {
        i = p / b;
        if (i < 10)
            ft_putchar('0' + i);
        else
            ft_putchar('A' + i - 10);
        p %= b;
        b /= 16;
    }
}

//%% para imprimir el símbolo del porcentaje.
void    ft_putper()
{
    ft_putchar('%');
}

void ft_printf(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	t_format f;
	const char* p;

	p = format;
    while (*p != '\0')
    {
        if (*p == '%' && *(p + 1) != '\0')
        {
			p++;
            parse_format(&p, &f);
            if (f.type == 'd' || f.type == 'i')
                print_integer(&f, va_arg(args, int));
            //ft_putint(va_arg(args, int));
            else if (*p == 'c')
                ft_putchar((char)va_arg(args, int));
            else if (f.type == 's')
                print_a_string(&f, va_arg(args, char*));
                //ft_putstr(va_arg(args, char*));
            else if (*p == 'u')
                ;
            else if (*p == 'p')
                print_integer(&f, va_arg(args, void *));
            else if (*p == 'x')
                print_integer(&f, va_arg(args, unsigned int));
            else if (*p == 'X')
                print_integer(&f, va_arg(args, unsigned int));
            else
            {
                ft_putper();
                ft_putchar(*p);
            }
        }
        else {
            putchar(*p); // Imprime caracteres normales
        }
        p++;
    }
	va_end(args);
}

int test_pointers()
{

	void *p0 =     malloc(3);
    printf("\n\n __________________ TESTEANDO LOS PUNTEROS __________________");
    printf("\n\n ______ SIN FORMATO DE NINGUN TIPO ______");
       printf("\n>%p|", p0);
    ft_printf("\n %p|", p0);

    printf("\n\n ______ ALINEACIONES ______");
       printf("\n>%-5p|", p0);
    ft_printf("\n %-5p|", p0);
       printf("\n>%05p|", p0);
    ft_printf("\n %05p|", p0);
	
    printf("\n\n ______ SIGNOS Y ALINEACIONES ______");
       printf("\n>%+-5p|", p0);
    ft_printf("\n %+-5p|", p0);
       printf("\n>%+05p|", p0);
    ft_printf("\n %+05p|", p0);


    printf("\n\n ______ SIGNOS Y ALINEACIONES, un numero más gordo ______");
       printf("\n>%+-5p|", p0);
    ft_printf("\n %+-5p|", p0);
       printf("\n>%+05p|", p0);
    ft_printf("\n %+05p|", p0);

    printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-5.3p|", p0);
    ft_printf("\n %+-5.3p|", p0);
       printf("\n>%+05.10p|", p0);   
    ft_printf("\n %+05.10p|", p0);
       printf("\n>%+5.10p|", p0);   
    ft_printf("\n %+5.10p|", p0); 
    
    printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-15.3p|", p0);
    ft_printf("\n %+-15.3p|", p0);
       printf("\n>%+15.7p|", p0);   
    ft_printf("\n %+15.7p|", p0);
       printf("\n>%+15.10p|", p0);   
    ft_printf("\n %+15.10p|", p0);
}


int test_integers()
{
    printf("\n\n __________________ TESTEANDO LOS ENTEROS __________________");
    printf("\n\n ______ SIN FORMATO DE NINGUN TIPO ______");
       printf("\n>%i|", 227);
    ft_printf("\n %i|", 227);
       printf("\n>%d|", 227);
    ft_printf("\n %d|", 227);

    printf("\n\n ______ ALINEACIONES ______");
       printf("\n>%-5d|", 227);
    ft_printf("\n %-5d|", 227);
       printf("\n>%-5i|", 227);
    ft_printf("\n %-5i|", 227);
       printf("\n>%05d|", 227);
    ft_printf("\n %05d|", 227);
       printf("\n>%05i|", 227);
    ft_printf("\n %05i|", 227);

    printf("\n\n ______ SIGNOS Y ALINEACIONES ______");
       printf("\n>%+-5d|", 227);
    ft_printf("\n %+-5d|", 227);
       printf("\n>%+-5i|", 227);
    ft_printf("\n %+-5i|", 227);
       printf("\n>%+05d|", 227);
    ft_printf("\n %+05d|", 227);
       printf("\n>%+05i|", 227);
    ft_printf("\n %+05i|", 227);

    printf("\n\n ______ SIGNOS Y ALINEACIONES, un numero más gordo ______");
       printf("\n>%+-5d|", 546373);
    ft_printf("\n %+-5d|", 546373);
       printf("\n>%+-5i|", 546373);
    ft_printf("\n %+-5i|", 546373);
       printf("\n>%+05d|", 546373);
    ft_printf("\n %+05d|", 546373);
       printf("\n>%+05i|", 546373);
    ft_printf("\n %+05i|", 546373);
    
    printf("\n\n ______ SIGNOS Y ALINEACIONES, UN NUMERO NEGATIVO ______");
       printf("\n>%+-5d|", -546373);
    ft_printf("\n %+-5d|", -546373);
       printf("\n>%+-5i|", -546373);
    ft_printf("\n %+-5i|", -546373);
       printf("\n>%+05d|", -546373);
    ft_printf("\n %+05d|", -546373);
       printf("\n>%+05i|", -546373);
    ft_printf("\n %+05i|", -546373);

    printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-5.3d|", 546373);
    ft_printf("\n %+-5.3d|", 546373);
       printf("\n>%+-5.3i|", 546373);
    ft_printf("\n %+-5.3i|", 546373);
       printf("\n>%+05.7d|", 546373);   
    ft_printf("\n %+05.7d|", 546373);
       printf("\n>%+05.7i|", 546373);
    ft_printf("\n %+05.7i|", 546373);
       printf("\n>%+5.7d|", 546373);   
    ft_printf("\n %+5.7d|", 546373);
       printf("\n>%+5.7i|", 546373);
    ft_printf("\n %+5.7i|", 546373);   // KO
    
    printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-9.3d|", 546373);
    ft_printf("\n %+-9.3d|", 546373);
       printf("\n>%+-9.3i|", 546373);
    ft_printf("\n %+-9.3i|", 546373);
       printf("\n>%+09.7d|", 546373);   
    ft_printf("\n %+09.7d|", 546373);
       printf("\n>%+09.7i|", 546373);
    ft_printf("\n %+09.7i|", 546373);
       printf("\n>%+9.7d|", 546373);   
    ft_printf("\n %+9.7d|", 546373);
       printf("\n>%+9.7i|", 546373);
    ft_printf("\n %+9.7i|", 546373);
}

void test_strings()
{
	printf("\n\n __________________ TESTEANDO STRINGSSSSSS __________________");
    char* mystring = "this is a sample string";
    printf("\n\n ______ SIN FORMATO DE NINGUN TIPO ______");
       printf("\n>%s|", mystring);
    ft_printf("\n %s|", mystring);
    printf("\n\n ______ CON WIDTH ______");
       printf("\n>%5s|", mystring);
    ft_printf("\n %5s|", mystring);
       printf("\n>%40s|", mystring);
    ft_printf("\n %40s|", mystring);
    printf("\n\n ______ CON PRECISION ______");
       printf("\n>%.5s|", mystring);
    ft_printf("\n %.5s|", mystring);
       printf("\n>%.40s|", mystring);
    ft_printf("\n %.40s|", mystring);
    printf("\n\n ______ PROBANDO ALINEACIONES ... a izquierda ______");
       printf("\n>%-5s|", mystring);
    ft_printf("\n %-5s|", mystring);
       printf("\n>%-40s|", mystring);
    ft_printf("\n %-40s|", mystring);
    printf("\n\n ______ PROBANDO ALINEACIONES ... a derecha ______");
       printf("\n>%05s|", mystring);
    ft_printf("\n %05s|", mystring);
       printf("\n>%040s|", mystring);
    ft_printf("\n %040s|", mystring);
    printf("\n\n ______ WIDTH y PRECISION ______");
       printf("\n>%08.5s|", mystring);
    ft_printf("\n %08.5s|", mystring);// ko
       printf("\n>%08.40s|", mystring);
    ft_printf("\n %08.40s|", mystring);
       printf("\n>%-8.5s|", mystring);
    ft_printf("\n %-8.5s|", mystring);
       printf("\n>%-8.40s|", mystring);
    ft_printf("\n %-8.40s|", mystring);
       printf("\n>%8.5s|", mystring);
    ft_printf("\n %8.5s|", mystring);
       printf("\n>%8.40s|", mystring);
    ft_printf("\n %8.40s|", mystring);
}

void test_hexas()
{
    printf("\n\n __________________ TESTEANDO LOS ENTEROS X __________________");
    printf("\n\n ______ SIN FORMATO DE NINGUN TIPO ______");
       printf("\n>%x|", 227);
    ft_printf("\n %x|", 227);
       printf("\n>%X|", 227);
    ft_printf("\n %X|", 227);

    printf("\n\n ______ ALINEACIONES ______");
       printf("\n>%-5x|", 227);
    ft_printf("\n %-5x|", 227);
       printf("\n>%-5X|", 227);
    ft_printf("\n %-5X|", 227);
       printf("\n>%05x|", 227);
    ft_printf("\n %05x|", 227);
       printf("\n>%05X|", 227);
    ft_printf("\n %05X|", 227);

    printf("\n\n ______ SIGNOS Y ALINEACIONES ______");
       printf("\n>%+-5x|", 227);
    ft_printf("\n %+-5x|", 227);
       printf("\n>%+-5X|", 227);
    ft_printf("\n %+-5X|", 227);
       printf("\n>%+05x|", 227);
    ft_printf("\n %+05x|", 227);
       printf("\n>%+05X|", 227);
    ft_printf("\n %+05X|", 227);

    printf("\n\n ______ SIGNOS Y ALINEACIONES, un numero más gordo ______");
       printf("\n>%+-5x|", 5463734);
    ft_printf("\n %+-5x|", 5463734);
       printf("\n>%+-5X|", 5463734);
    ft_printf("\n %+-5X|", 5463734);
       printf("\n>%+05x|", 5463734);
    ft_printf("\n %+05x|", 5463734);
       printf("\n>%+05X|", 5463734);
    ft_printf("\n %+05X|", 5463734);
    
        printf("\n\n ______ SIGNOS Y ALINEACIONES, un numero negativo ______");
       printf("\n>%+-5x|", -5463734);
    ft_printf("\n %+-5x|", -5463734);
       printf("\n>%+-5X|", -5463734);
    ft_printf("\n %+-5X|", -5463734);
       printf("\n>%+05x|", -5463734);
    ft_printf("\n %+05x|", -5463734);
       printf("\n>%+05X|", -5463734);
    ft_printf("\n %+05X|", -5463734);

    printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-5.3x|", 546373);
    ft_printf("\n %+-5.3x|", 546373);
       printf("\n>%+-5.3X|", 546373);
    ft_printf("\n %+-5.3X|", 546373);
       printf("\n>%+05.7x|", 546373);   
    ft_printf("\n %+05.7x|", 546373);
       printf("\n>%+05.7X|", 546373);
    ft_printf("\n %+05.7X|", 546373);
       printf("\n>%+5.7x|", 546373);   
    ft_printf("\n %+5.7x|", 546373);
       printf("\n>%+5.7X|", 546373);
    ft_printf("\n %+5.7X|", 546373);  
    
    printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-8.3x|", 546373);
    ft_printf("\n %+-8.3x|", 546373);
       printf("\n>%+-8.3X|", 546373);
    ft_printf("\n %+-8.3X|", 546373);
       printf("\n>%+08.7x|", 546373);   
    ft_printf("\n %+08.7x|", 546373);
       printf("\n>%+08.7X|", 546373);
    ft_printf("\n %+08.7X|", 546373);
       printf("\n>%+8.7x|", 546373);   
    ft_printf("\n %+8.7x|", 546373);
       printf("\n>%+8.7X|", 546373);
    ft_printf("\n %+8.7X|", 546373);
}

int	main()
{
	/*test_integers();
	test_strings();
	test_hexas();*/
	test_pointers();
	return 1;
}
