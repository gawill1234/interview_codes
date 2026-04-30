#include <stdio.h>

void minmax(int x, int y) {

   int min = (y ^ (x ^ y) & -(x < y));
   int max = (x ^ (x ^ y) & -(x < y));

   printf("Values are:  %d and %d\n", x, y);

   printf("Minimum => %d\n", min);
   printf("Maximum => %d\n\n", max);

   return;
}

int main()
{
   //  2 positives
   minmax(10, 20);

   //  2 negatives
   minmax(-2, -9);

   //  positive, negative
   minmax(7, -9);

   //  negative, positive
   minmax(-2, 5);

   //  Same but for sign
   minmax(-100, 100);

   //  Actually the same, positive
   minmax(100, 100);

   //  Actually the same, negative
   minmax(-100, -100);

   //  Actually the same, zero
   minmax(0, 0);

   return 0;
}
