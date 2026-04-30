#include <stdio.h>

int main() {
   int x, y, z;
   unsigned int a, b, c;
   float h, i, j;

   printf("Multiplication by 2 in various forms:\n\n");

   x = -3 * 2;
   y = -3 << 1;
   z = -3 / .5;

   printf("Negative signed integer(rounding result)\n");
   printf("x(-3 * 2)   y(-3 << 1)   z(-3 / .5)\n");
   printf("=========   ==========   ==========\n");
   printf("  %d          %d         %d\n\n", x, y, z);

   x = 3 * 2;
   y = 3 << 1;
   z = 3 / .5;

   printf("Positive signed integer(rounding result)\n");
   printf("x(3 * 2)   y(3 << 1)   z(3 / .5)\n");
   printf("========   =========   ==========\n");
   printf("   %d           %d          %d\n\n", x, y, z);

   a = 3 * 2;
   b = 3 << 1;
   c = 3 / .5;

   printf("Unsigned integer(rounding result)\n");
   printf("a(3 * 2)   b(3 << 1)   c(3 / .5)\n");
   printf("========   =========   ==========\n");
   printf("   %d           %d          %d\n\n", a, b, c);

   a = 4 * 2;
   b = 4 << 1;
   c = 4 / .5;

   printf("Unsigned integer(whole result)\n");
   printf("a(4 * 2)   b(4 << 1)   c(4 / .5)\n");
   printf("========   =========   ==========\n");
   printf("   %d           %d          %d\n\n", a, b, c);

   h = 3.0 * 2.0;
#ifdef DOSHIFT
   i = 3.0 << 1.0;
   i = 3.0 << 1;
#endif
   j = 3.0 / .5;

   printf("Float, just to show that shifting is wrong!\n");
   printf("h(3 * 2)   i(3 << 1)       j(3 / .5)\n");
   printf("========   =========       ==========\n");
   printf("   %1.1f    compile error        %1.1f\n\n", h, j);
   printf("Float, recompile with -DDOSHIFT to see error\n");
   printf("  Ex:  gcc -DDOSHIFT multiply.c\n");
}
