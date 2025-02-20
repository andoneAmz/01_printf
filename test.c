#include <limits.h>  // For INT_MIN, INT_MAX, UINT_MAX
#include <stdio.h>

void ft_printf(const char* format, ...);

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


void test_unsignedintegers() 
{
    printf("\n\n __________________ TESTEANDO LOS ENTEROS __________________");
    printf("\n\n ______ SIN FORMATO DE NINGUN TIPO ______");
       printf("\n>%u|", 227);
    ft_printf("\n %u|", 227);

    printf("\n\n ______ ALINEACIONES ______");
       printf("\n>%-5u|", 227);
    ft_printf("\n %-5u|", 227);
       printf("\n>%05u|", 227);
    ft_printf("\n %05u|", 227);

    printf("\n\n ______ SIGNOS Y ALINEACIONES ______");
       printf("\n>%+-5u|", 227);
    ft_printf("\n %+-5u|", 227);
       printf("\n>%+05u|", 227);
    ft_printf("\n %+05u|", 227);

    printf("\n\n ______ SIGNOS Y ALINEACIONES, un numero más gordo ______");
       printf("\n>%+-5u|", 546373);
    ft_printf("\n %+-5u|", 546373);
       printf("\n>%+05u|", 546373);
    ft_printf("\n %+05u|", 546373);
   
    printf("\n\n ______ SIGNOS Y ALINEACIONES, UN NUMERO NEGATIVO ______");
       printf("\n>%+-5u|", -546373);
    ft_printf("\n %+-5u|", -546373);
       printf("\n>%+05u|", -546373);
    ft_printf("\n %+05u|", -546373);

    printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-5.3u|", 546373);
    ft_printf("\n %+-5.3u|", 546373);
       printf("\n>%+05.7u|", 546373);   
    ft_printf("\n %+05.7u|", 546373);
       printf("\n>%+5.7u|", 546373);   
    ft_printf("\n %+5.7u|", 546373);
    
    printf("\n\n ______ WIDTH AND PRECISION ______");
       printf("\n>%+-9.3u|", 546373);
    ft_printf("\n %+-9.3u|", 546373);
       printf("\n>%+09.7u|", 546373);   
    ft_printf("\n %+09.7u|", 546373);
       printf("\n>%+9.7u|", 546373);   
    ft_printf("\n %+9.7u|", 546373);
    
        unsigned int max = INT_MAX + 6;
    
    printf("\n\n ______ BIG BIG NUMBERS ______");
       printf("\n>%+-9.3u|", max);
    ft_printf("\n %+-9.3u|", max);
       printf("\n>%+09.7u|", max);   
    ft_printf("\n %+09.7u|", max);
       printf("\n>%+9.7u|", max);   
    ft_printf("\n %+9.7u|", max);
    
    printf("\n\n ______ esto no tiene por que ssalir bien ______");
       printf("\n>%+-9.3d|", -max);
    ft_printf("\n %+-9.3d|", -max);
       printf("\n>%+09.7d|", -max);   
    ft_printf("\n %+09.7d|", -max);
       printf("\n>%+9.7d|", -max);   
    ft_printf("\n %+9.7d|", -max);  

    
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
    ft_printf("\n %+5.7i|", 546373);
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

void test_integer_limits() 
{
	   printf("Testing limit values for %%d, %%i and %%u:\n");
	ft_printf("Testing limit values for %%d, %%i and %%u:\n");
	int min = INT_MIN;
	int max = INT_MAX;
	unsigned int umax = UINT_MAX;

	// Basic Limits
	   printf(">Min int: %d %i\n", min, min);
	ft_printf(" Min int: %d %i\n", min, min);
	   printf(">Max int: %d %i\n", max, max);
	ft_printf(" Max int: %d %i\n", max, max);
	   printf(">Zero: %d %i %u\n", 0, 0, 0);
	ft_printf(" Zero: %d %i %u\n", 0, 0, 0);
	   printf(">Max unsigned: %u\n", umax);
	ft_printf(" Max unsigned: %u\n", umax);

	// Flags
	   printf(">Plus flag: %+d %+i\n", max, min);
	ft_printf(" Plus flag: %+d %+i\n", max, min);
	   printf(">Space flag: % d % i\n", max, min);
	ft_printf(" Space flag: % d % i\n", max, min);
	   printf(">Zero padding: %020d %020i %020u\n", max, min, umax);
	ft_printf(" Zero padding: %020d %020i %020u\n", max, min, umax);
	   printf(">Left align: %-20d %-20i %-20u\n", max, min, umax);
	ft_printf(" Left align: %-20d %-20i %-20u\n", max, min, umax);

	// Width and Precision
	   printf(">Width 10: %10d %10i %10u\n", max, min, umax);
	ft_printf(" Width 10: %10d %10i %10u\n", max, min, umax);
	   printf(">Precision .5: %.5d %.5i %.5u\n", max, min, umax);
	ft_printf(" Precision .5: %.5d %.5i %.5u\n", max, min, umax);
	   printf(">Width 10, Precision .5: %10.5d %10.5i %10.5u\n", max, min, umax);
	ft_printf(" Width 10, Precision .5: %10.5d %10.5i %10.5u\n", max, min, umax);

	// Combination Tests
	   printf(">Plus & zero padding: %+020d %+020i\n", max, min);
	ft_printf(" Plus & zero padding: %+020d %+020i\n", max, min);
	   printf(">Left align & width: %-10d %-10i %-10u\n", max, min, umax);
	ft_printf(" Left align & width: %-10d %-10i %-10u\n", max, min, umax);
	   printf(">Precision & zero padding: %020.5d %020.5i %020.5u\n", max, min, umax);
	ft_printf(" Precision & zero padding: %020.5d %020.5i %020.5u\n", max, min, umax);
	   printf(">All flags combined: %+020.5d %+020.5i %020.5u\n", max, min, umax);
	ft_printf(" All flags combined: %+020.5d %+020.5i %020.5u\n", max, min, umax);
    
    printf("Limit tests complete.\n");
}

void test_char_formats()
{
    printf("Testing %%c with different modifiers:\n");

    char ch = 'A';

    // Basic character
    ft_printf("Basic character: %c\n", ch);

    // Width
       printf(">Width 5: %5c\n", ch);  // Right-aligned
    ft_printf(" Width 5: %5c\n", ch);  // Right-aligned
       printf(">Left align, width 5: %-5c\n", ch);  // Left-aligned
    ft_printf(" Left align, width 5: %-5c\n", ch);  // Left-aligned

    // Flags (only '-' works)
       printf(">Zero padding (ignored for %%c): %05c\n", ch);  // Should be ignored
    ft_printf(" Zero padding (ignored for %%c): %05c\n", ch);  // Should be ignored

    // Multiple characters to test alignment
       printf(">Multiple: |%5c|%5c|%5c|\n", 'X', 'Y', 'Z');
    ft_printf(" Multiple: |%5c|%5c|%5c|\n", 'X', 'Y', 'Z');
       printf(">Left-align: |%-5c|%-5c|%-5c|\n", 'X', 'Y', 'Z');
    ft_printf(" Left-align: |%-5c|%-5c|%-5c|\n", 'X', 'Y', 'Z');

    printf("Character format tests complete.\n");
}


int	main()
{
	
	test_integer_limits();
	test_integers();
	test_strings();
	test_hexas();
	test_pointers();
	test_unsignedintegers();
	test_char_formats();
	return 1;
}
