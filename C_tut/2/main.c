#include <stdio.h>

//
#define newline putchar('\n')

//
int main()
{
  /*   En C, toute variable doit être déclarée et de préférence initialisée.
       Il existe plusieurs types:
       
		    Type           |  Storage size            |   Value range
		    -----------------------------------------------------------------------------------------------
		    char           |  1 byte                  |  -128 to 127 or 0 to 255
		    unsigned char  |  1 byte                  |  0 to 255
		    signed char    |  1 byte                  |  -128 to 127
		    int            |  2 or 4 bytes            |  -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
		    unsigned int   |  2 or 4 bytes            |  0 to 65,535 or 0 to 4,294,967,295
		    short          |  2 bytes                 |  -32,768 to 32,767
		    unsigned short |  2 bytes                 |  0 to 65,535
		    long           |  8 bytes                 |  -9223372036854775808 to 9223372036854775807
		    unsigned long  |  8 bytes                 |  0 to 18446744073709551615   

       Les valeurs immédiates/constantes peuvent être exprimées dans plusieurs bases de numération: 
       base 2 (binaire), base 8 (octale), base 10 (décimale) et base 16 (hexadécimale).

       base  2: {0, 1}
       base  8: {0, 1, 2, 3, 4, 5, 6, 7}
       base 10: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
       base 16: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}      

       Chaque type à un format spécifique qu'il faut indiquer à printf:

       %d %i     Decimal signed integer.
       %o        Octal integer.
       %x %X     Hex integer.
       %u        Unsigned integer.
       %c        Character.
       %s        String. See below.
       %f        double
       %e %E     double.
       %g %G     double.
       %p        pointer.
       %n        Number of characters written by this printf.

       Chacun de ses format peut se voir attribuer un flag:

       -      Left justify.
       0      Field is padded with 0's instead of blanks.
       +     Sign of number always O/P.

       Cas d'usage:

       %#o (Octal) 0 prefix inserted.
       %#x (Hex)   0x prefix added to non-zero values.
       %#X (Hex)   0X prefix added to non-zero values.
       %#e         Always show the decimal point.
       %#E         Always show the decimal point.
       %#f         Always show the decimal point.
       %#g         Always show the decimal point trailing zeros not removed.
       %#G         Always show the decimal point trailing zeros not removed.  
  */

  char c1 = 65, c2 = 'A';
  int a = -1, b = 0xF0000001;
  unsigned short x = 0xAA8F;
  unsigned short y = 0x8F;

  //
  printf("C1: %c %d -  C2: %c %d\n", c1, c1, c2, c2);

  //
  printf("A: %d - B: %d\n", a, b);

  //
  printf("X: %x\n", x);

  //
  printf("Y: 0x%04x\n", y);

  //
  newline;
  
  //
  int number = 5;
  char *pointer = "little";

  //
  printf("Here is a number-%4d-and a-%10s-word.\n", number, pointer);

  //
  printf("---%*d----\n", 6, number);

  //
  newline;
  
  //Cas d'affichage de flottants simple et double précision
  float  f = 2.98182718187626157365761541526541652;
  double g = 1726.18278618536754175145434242541315326341564314632711898101082701;

  //
  printf("f: %f\n", f);
  printf("f: %5.1f\n", f);
  printf("f: %5.2f\n", f);
  printf("f: %5.5f\n", f);
  printf("f: %6.6f\n", f);
  printf("f: %9.50f\n", f);
  printf("f: %10.10g\n", f);
  printf("f: %e\n", f);
  
  //
  newline;
  
  //
  printf("g: %lf\n", g);
  printf("g: %5.1lf\n", g);
  printf("g: %5.2lf\n", g);
  printf("g: %5.5lf\n", g);
  printf("g: %6.6lf\n", g);
  printf("g: %9.20lf\n", g);
  printf("g: %9.50lf\n", g);
  printf("g: %1.3g\n", g);
  printf("g: %1.30e\n", g);
  
  return 0;
}
