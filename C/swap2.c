#include <stdio.h>

void swappit(int a, int b) {

   printf("SWAP,     a: %d, b: %d\n", a, b);

   /*
    * Swap a with b
    */
   a = a + b;
   b = a - b;
   a = a - b;

   printf("SWAPPED,  a: %d, b: %d\n\n", a, b);
   fflush(stdout);

   return;
}

void swappit2(int a, int b) {

   printf("SWAP,     a: %d, b: %d\n", a, b);

   /*
    * Swap a with b
    */
   a ^= b;
   b ^= a;
   a ^= b;

   printf("SWAPPED,  a: %d, b: %d\n\n", a, b);
   fflush(stdout);

   return;
}

int main()
{
   printf("EXOR swap ...\n");

   swappit2(1, 9);
   swappit2(-3, -9);
   swappit2(0, -1);
   swappit2(0, 0);

   printf("Another way to do the swap (+/-) ...\n");

   swappit(1, 9);
   swappit(-3, -9);
   swappit(0, -1);
   swappit(0, 0);

   return 0;
}
