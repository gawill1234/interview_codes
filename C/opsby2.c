#include <stdio.h>

/*
 *   Program to show why you should be careful when
 *   trying to divide by 2 by right shifting.  Works
 *   with unsigned integers.  It does it with signed.
 *   But, due to different ways of rounding, the right
 *   shift of a signed value may be different than when
 *   you actuall use math (divide).  Be carefull ...
 */
void divideby2() {
int x, y, z;
unsigned int a, b, c;
float h, i, j;

   x = (-3 / 2);
   y = (-3 * .5);
   z = (-3 >> 1);

   printf("Negative Integer divide:\n");
   printf("(-3 / 2): %d  ||  (-3 * .5): %d  ||  (-3 >> 1): %d\n\n", x, y, z);

   a = (3 / 2);
   b = (3 * .5);
   c = (3 >> 1);

   printf("unsigned divide:\n");
   printf("(3 / 2): %d  ||  (3 * .5): %d  ||  (3 >> 1): %d\n\n", a, b, c);

   h = (-3.0 / 2.0);
   i = (-3.0 * .5);
#ifdef DOSHIFT
   j = (-3.0 >> 1.0);
   printf("Negative float divide (shows shift not possible):\n");
   printf("(-3.0 / 2.0): %f  ||  (-3.0 * .5): %f  ||  (-3.0 >> 1.0): %f\n\n", h, i, j);
#else
   printf("Negative float divide (shows shift not possible):\n");
   printf("(-3.0 / 2.0): %f  ||  (-3.0 * .5): %f  ||  (-3.0 >> 1.0): compile error\n\n", h, i);
#endif
}

void multiplyby2() {
int x, y, z;
unsigned int a, b, c;
float h, i, j;

   x = (-3 * 2);
   y = (-3 / .5);
   z = (-3 << 1);

   printf("Negative Integer multiply:\n");
   printf("(-3 * 2): %d  ||  (-3 / .5): %d  ||  (-3 << 1): %d\n\n", x, y, z);

   a = (3 * 2);
   b = (3 / .5);
   c = (3 << 1);

   printf("unsigned multiply:\n");
   printf("(3 * 2): %d  ||  (3 / .5): %d  ||  (3 << 1): %d\n\n", a, b, c);

   h = (-3.0 * 2.0);
   i = (-3.0 / .5);
#ifdef DOSHIFT
   j = (-3.0 << 1.0);
   printf("Negative float multiply (shows shift not possible):\n");
   printf("(-3.0 * 2.0): %f  ||  (-3.0 / .5): %f  ||  (-3.0 << 1.0): %f\n\n", h, i, j);
#else
   printf("Negative float multiply (shows shift not possible):\n");
   printf("(-3.0 * 2.0): %f  ||  (-3.0 / .5): %f  ||  (-3.0 << 1.0): compile error\n\n", h, i);
#endif

}

int main() {

   printf("===============\n");
   printf("MULTIPLY BY 2 IN VARIOUS WAYS:\n");
   multiplyby2();

   printf("===============\n");

   printf("\nDIVIDE BY 2 IN VARIOUS WAYS:\n");
   divideby2();

   printf("===============\n");

   printf("To see the compiler error do: \n");
   printf("  gcc -DDOSHIFT opsby2.c\n");

}
