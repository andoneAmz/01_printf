//#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    ALIGN_NONE,
    ALIGN_LEFT,
    ALIGN_ZERO
} t_align;

typedef enum
{
    SIGN_NONE,
    SIGN_PLUS,
    SIGN_SPACE
} t_sign;

typedef enum
{
    MOD_NONE,
    MOD_HH,
    MOD_H,
    MOD_L,
    MOD_LL,
    MOD_J,
    MOD_Z,
    MOD_T,
    MOD_BIGL
} t_modifier;

typedef enum
{
    TYPE_NONE,
    TYPE_INT,
    TYPE_UINT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_POINTER,
    TYPE_OCTAL,
    TYPE_HEX,
    TYPE_HEX_UPPER,
    TYPE_PERCENT
} t_type;

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
    if (*c == '+' || *c == ' ') // '+' show sign for positive numbers ' ' space before positive numbers
    {
        f->sign = *c;
        c++;
    }
    if (*c == '-' || *c == '0') // '-' left align '0' zero padding
    {
        f->align = *c;
        c++;
    }
    n = 0; // %w  minimum number of characters to be printed
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
        f->precision = n; // %.p For integers: Minimum number of digits. For floats: Number of decimal places. For strings: Maximum number of characters
    }


    // modificadores
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
    size_t  l;
    int     u;
    char    *sol;

    l = 1;
    u = 1;

    while (n / b >= u)
    {
        u *= b;
        l++;
    }
    sol = (char *)malloc((l + 1) * sizeof(char));
    if (sol == NULL)
        return (NULL);
    l = 0;
    while (u)
    {
        sol[l] = '0' + n / u;
        n = n % u;
        u = u / b;
        l++;
    }
    sol[l] = '\0';
    return (sol);
}

void print_something(t_format* f, int n)
{
    char* s;
    int l;
    int i;
    int d;
    s = NULL;
    
    s = ft_itoa(n, 10);
    l = 0;
    while (s[l]) l++;

    // cuando estas alinand a al izquierda tiene sentido
    // disminuir el ancho pero cuando se trata del numero
    // de digito no puedes hacer eso

    // aun no está biena justado, ha que considerar
    // si estamos hablando de width o de preciosion
    if (f->sign && n >= 0)
    {
        write(1, &f->sign, 1);
        if (f->align == '-') l++;
    }
    else if (n < 0)
    {
        write(1,"-", 1);
        if (f->align == '-') l++;
    }
    d = 0;
    if (f->align == '0' || f->align == '-')
    {
        d = f->width;
        if (f->precision > d)
            d = f->precision;
    }
    // si tiene 0 o left, mirar el width
    if (f->align == '0' && d)
    {
        i = 0;
        while (i < d - l)
        {
            write(1, "0", 1);
            i++;
        }
        printf("%s", s);
    }
    else if (f->align == '-' && d)
    {
        printf("%s", s);
        i = 0;
        while (i < d - l)
        {
            write(1, " ", 1);
            i++;
        }
    }
    else
    {
        printf("%s", s);
    }

    return;
}
void putchar_times(char *c, int n)
{
    write(1, c, 1);
	if (n > 1)
		putchar_times(c, n - 1);
}
void print_a_string(t_format* f, char *s)
{
    int l;
    int i;
    int min;
    //s = NULL;

    //s = ft_itoa(n, 10);
    l = 0;
    while (s[l]) l++;


    min = 0;
    if (1)
    {
        min = f->width;
        if (f->precision > min)
            min = f->precision;
    }

    if (1)
    {
        if (f->align == '0' || (!f->align && min > l))
        {
            if (f->align == '0')
                putchar_times("0", f->width - l);
            else
                putchar_times(" ", f->width - l);
        }
        if (f->precision == -1)
            write(1, s, l);
        else
            write(1, s, f->precision);
        if (f->align == '-')
        {
            putchar_times(" ", f->width - l);
        }
    }
    return;
}

//%c Imprime un solo carácter.
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

//%s Imprime una string(como se define por defecto en C).
size_t    ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_putstr(char* s)
{
    write(1, s, ft_strlen(s));
}

//%p El puntero void* dado como argumento se imprime en formato hexadecimal
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

//%u Imprime un número decimal(base 10) sin signo.





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
	


    for (const char* p = format; *p != '\0'; p++)
    {
        if (*p == '%' && *(p + 1) != '\0')
        {
            p++;
            parse_format(&p, &f);

            if (f.type == 'd' || f.type == 'i')
                print_something(&f, va_arg(args, int));
            //ft_putint(va_arg(args, int));
            else if (*p == 'c')
                ft_putchar((char)va_arg(args, int));
            else if (f.type == 's')
                print_a_string(&f, va_arg(args, char*));
                //ft_putstr(va_arg(args, char*));
            else if (*p == 'u')
                ;
            else if (*p == 'p')
                ft_puthex(va_arg(args, void *));
            else if (*p == 'x')
                ft_puthex_minnor(va_arg(args, unsigned int));
            else if (*p == 'X')
                ft_puthex_upper(va_arg(args, unsigned int));
            else
            {
                ft_putper();
                ft_putchar(*p);
            }
        }
        else {
            putchar(*p); // Imprime caracteres normales
        }
    }

    va_end(args);
}

int test_integers()
{
    // %i Imprime un entero en base 10
    printf("\n\n ______ SIN FORMATO DE NINGUN TIPO ______");
    printf("\n>%i|", 227);
    ft_printf("\n %i|", 227);
    printf("\n>%d|", 227);
    ft_printf("\n %d|", 227);

    printf("\n\n ______ ALINEACIONES ______");
    printf("\n>%-5d|", 227);
    ft_printf("\n>%-5d|", 227);
    printf("\n>%-5i|", 227);
    ft_printf("\n>%-5i|", 227);
    printf("\n>%05d|", 227);
    ft_printf("\n>%05d|", 227);
    printf("\n>%05i|", 227);
    ft_printf("\n>%05i|", 227);

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

        printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-5.3d|", 546373);
    ft_printf("\n %+-5.3d|", 546373);
       printf("\n>%+-5.3i|", 546373);
    ft_printf("\n %+-5.3i|", 546373);
       printf("\n>%+05.7d|", 546373);   
    ft_printf("\n %+05.7d|", 546373);   // KO
       printf("\n>%+05.7i|", 546373);
    ft_printf("\n %+05.7i|", 546373);   // KO
}

void test_strings()
{
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
    ft_printf("\n %08.5s|", mystring);
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

int	main()
{
	test_basics();
    //test_integers();
    //test_strings();
    return 1;
    // %u Imprime un número decimal (base 10) sin signo
    printf("\n>%u", 227);
    printf("\n>%u", -227);
    // %x Imprime un número hexadecimal (base 16) en minúsculas
    printf("\n %x", 227);
    printf("\n %x", -227);
    // %X Imprime un número hexadecimal (base 16) en mayúsculas.
    printf("\n %X", 227);
    printf("\n %X", -227);

    printf("\n\n ______ FLAGS AND STUFF ______");
    printf("\n left aligning integers ...");
    printf("\n>%-5d|", 227);
    printf("\n>%-5i|", 227);
    ft_printf("\n %-5d|", 227);
    ft_printf("\n %-512d|", 227);
    ft_printf("\n %-5i|", 227);
    ft_printf("\n %-512i|", 227);

    printf("\n\n ______ PROBAR LOS STRINGS Y TAL ______");
    printf("\n left aligning strings ...");
    printf("\n>%-37s|", "maricarmen");
    ft_printf("\n %-37s|", "maricarmen");
    printf("\n zeropadding strings ...");
    printf("\n>%037s|", "maricarmen");
    ft_printf("\n %037s|", "maricarmen");

    printf("\n\n ______ Y SI JUNTO UN PADDING CON EL SIGNO ______");
    printf("\n>%+037d|", 37);
    printf("\n>% 037d|", 37);
    printf("\n>% 037d|", -37);

    printf("\n>%+-37d|", 37);
    printf("\n>% -37d|", 37);
    printf("\n>% -37d|", -37);

    printf("\n>%+-37d|", 37);
    printf("\n>% -37d|", 37);
    printf("\n>% -37d|", -37);

    printf("\n\n ______ WIDTH AND PRECISION ______");
    printf("\n>-%3.5d|", 37);
    return 0;
}