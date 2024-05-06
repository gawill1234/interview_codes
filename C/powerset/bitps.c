#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int bitshift_powerset(int numelements)
{
   double areyoukidding;
   unsigned long bits;
   int loc, count;
   unsigned long shiftit;

   if (numelements > (sizeof(unsigned long) * 8)) {
      printf("%d is too big for this.\n", numelements);
      fflush(stdout);
      return(1);
   }

   //
   //   Bit magic.  numelements could be 32.  If it is, you'd shift off
   //   the end of the word so numelement - 1.  Then subtract 1 to turn
   //   the remainder into all 1's.  But that then limits you to 31 bits.
   //   So, multiply by 2 (or left shift 1) and add 1.
   //
   //shiftit = ((((1 << (numelements - 1)) - 1) * 2) + 1);
   shiftit = ((((1 << (numelements - 1)) - 1) << 1) + 1);

   count = 1;

   areyoukidding = pow(2, numelements);

   if (areyoukidding > 2000000.0) {
      printf("NO.  I am not printing %.0f sets.\n", areyoukidding);
      fflush(stdout);
      return(1);
   } else {
      printf("printing %.0f sets.\n", areyoukidding);
      fflush(stdout);
   }

   while (shiftit > 0 ) {
      loc = 0;
      bits = shiftit;
      printf("%u: ", count);
      while ( bits > 0 ) {
         if ( bits & 0x1 ) {
            printf("%u ", loc);
         }
         bits >>= 1;
         loc += 1;
      }
      printf("\n");
      fflush(stdout);
      shiftit--;
      count += 1;
   }

   return(0);
}

int main(int argc, char **argv)
{
   if (argc < 2) {
      printf("Need a numeric argument.\n");
      fflush(stdout);
      exit(1);
   }
   exit(bitshift_powerset(atoi(argv[1])));
}

