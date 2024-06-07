#include <stdio.h>
#include <math.h>

#define PI 3.1415926

/*
 *   area using radius squared
 *   by multiplying by itself
 */
float areaofcircle(float r) {

   return(PI * (r * r));
}

/*
 *   area using radius squared
 *   by using pow() function.
 *   Only reason math.h is included.
 */
float areaofcircle2(float r) {

   return(PI * pow(r, 2));
}

/*
 *   area using radius squared
 *   by using pow() function.
 *   Only reason math.h is included.
 */
float circumferenceofcircle(float r) {

   return(2 * PI * r);
}

int main() {
float a;

   a = 3.0;
   printf("(mult) Circle radius: %f, Circle area  : %f\n", a, areaofcircle(a));
   printf("(pow)  Circle radius: %f, Circle area  : %f\n", a, areaofcircle2(a));
   printf("Circle circumference: %f, circumference: %f\n", a, circumferenceofcircle(a));
   printf("\n");
   a = 8.25;
   printf("(mult) Circle radius: %f, Circle area  : %f\n", a, areaofcircle(a));
   printf("(pow)  Circle radius: %f, Circle area  : %f\n", a, areaofcircle2(a));
   printf("Circle circumference: %f, circumference: %f\n", a, circumferenceofcircle(a));
   printf("\n");
   a = 3.1415926;
   printf("(mult) Circle radius: %f, Circle area  : %f\n", a, areaofcircle(a));
   printf("(pow)  Circle radius: %f, Circle area  : %f\n", a, areaofcircle2(a));
   printf("Circle circumference: %f, circumference: %f\n", a, circumferenceofcircle(a));
   printf("\n");
   a = 2.1;
   printf("(mult) Circle radius: %f, Circle area  : %f\n", a, areaofcircle(a));
   printf("(pow)  Circle radius: %f, Circle area  : %f\n", a, areaofcircle2(a));
   printf("Circle circumference: %f, circumference: %f\n", a, circumferenceofcircle(a));
   printf("\n");
   a = 1.0;
   printf("(mult) Circle radius: %f, Circle area  : %f\n", a, areaofcircle(a));
   printf("(pow)  Circle radius: %f, Circle area  : %f\n", a, areaofcircle2(a));
   printf("Circle circumference: %f, circumference: %f\n", a, circumferenceofcircle(a));
}
