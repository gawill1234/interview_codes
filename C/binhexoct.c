#include <stdio.h>
#include <stdlib.h>

/*
 *  Octal constant
 *  Leading '0' makes number 
 *  interpreted as octal
 */
#define OCT 0020

/*
 *  While this will compile, using it
 *  will cause an error.  Something like
 *  invalid digit '8' in octal constant.
 */
#define OCT2 018

/*
 *  Hex constant
 *  Leading '0x' makes number 
 *  interpreted as hexadecimal
 */
#define HEX 0x10

/*
 *  Binary constant
 *  Leading '0b' makes number 
 *  interpreted as binary
 */
#define BIN 0b10000

/*
 *  Some versions of the C compiler
 *  support the "%b" to print binary.
 *  Most don't.  So this will print an
 *  int as a binary.
 */
void printbinary(int num) {
int zing, gotone, i, wordsz;
 
   gotone = 0;
   wordsz = sizeof(int) * 8 - 1;
   for (i = wordsz; i >= 0; i--) {
      zing = ((num >> i) & 1);
      if (zing) {
         printf("1");
         gotone = 1;
      } else {
         if (gotone == 1)
            printf("0");
      }
   }
   printf("\n");

   return;
}

int main() {
int x, y, z;

   /*
    *  Set as octal
    */
   x = 0020;

   /*
    *  Set as hex
    */
   y = 0x10;

   /*
    *  Set as binary
    */
   z = 0b10000;

   /*
    *   Print them all as decimal
    */
   printf("All values as decimal\n");
   printf("OCT %d\n", OCT);
   /*
    *   Uncommenting this line will cause the
    *   bad digit for an octal number error from
    *   setting it above.
    */
   // printf("OCT2 %d\n", OCT2);
   printf("HEX %d\n", HEX);
   printf("BIN %d\n", BIN);

   printf("x   %d\n", x);
   printf("y   %d\n", y);
   printf("z   %d\n", z);

   /*
    *   Print them all as octal
    */
   printf("All values as octal\n");
   printf("OCT %o\n", OCT);
   printf("HEX %o\n", HEX);
   printf("BIN %o\n", BIN);

   printf("x   %o\n", x);
   printf("y   %o\n", y);
   printf("z   %o\n", z);

   /*
    *   Print them all as binary
    */
   printf("All values as binary\n");
   printf("OCT ");
   printbinary(OCT);
   printf("HEX ");
   printbinary(HEX);
   printf("BIN ");
   printbinary(BIN);

   printf("x   ");
   printbinary(x);
   printf("y   ");
   printbinary(y);
   printf("z   ");
   printbinary(z);

   exit(0);
}
