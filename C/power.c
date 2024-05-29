#include <stdio.h>
#include <stdlib.h>

/*
 *   implement power() without
 *   recursion.
 */
long power(long base, long exp) {
long total, i;

   total = 1;
   for (i = 0; i < exp; i++) {
      total = total * base;
   }
   return(total);
}

int main() {
long base, exp;

    base = 2;
    exp = 3;
    printf("%ld to power %ld is %ld\n", base, exp, power(base, exp));
    base = 5;
    exp = 4;
    printf("%ld to power %ld is %ld\n", base, exp, power(base, exp));
    base = 8;
    exp = 0;
    printf("%ld to power %ld is %ld\n", base, exp, power(base, exp));
    base = 10;
    exp = 1;
    printf("%ld to power %ld is %ld\n", base, exp, power(base, exp));
    base = 12;
    exp = 2;
    printf("%ld to power %ld is %ld\n", base, exp, power(base, exp));
    base = 25;
    exp = 8;
    printf("%ld to power %ld is %ld\n", base, exp, power(base, exp));
}
