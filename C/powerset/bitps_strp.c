#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int bitshift_powerset(char zz[], int numelements)
{
   unsigned long bits;
   int loc;
   unsigned long shiftit;

   shiftit = ((((1 << (numelements - 1)) - 1) << 1) + 1);

   while (shiftit > 0 ) {
      loc = 0;
      bits = shiftit;
      while ( bits > 0 ) {
         if ( bits & 0x1 ) {
            //printf("%u ", loc);
            printf("%c ", zz[loc]);
         }
         bits >>= 1;
         loc += 1;
      }
      printf("\n");
      fflush(stdout);
      shiftit--;
   }

   return(0);
}

int main(int argc, char **argv)
{
   int i;
   char zz[256];

   if (argc < 2) {
      printf("Need a numeric argument.\n");
      fflush(stdout);
      exit(1);
   }
   for (i = 0; i < atoi(argv[1]); i++) {
      zz[i] = (char)(i + (int)'A');
   }
   exit(bitshift_powerset(zz, atoi(argv[1])));
}

