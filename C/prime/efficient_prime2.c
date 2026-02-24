#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define DOMAX 100000

float elapsed(struct timeval st, struct timeval et) {
float elapsed_time = 0.0;

   elapsed_time = (et.tv_sec + (et.tv_usec/1000000.0)) - (st.tv_sec + (st.tv_usec/1000000.0));
   return(elapsed_time);
}

double get_prime2(int mynumber)
{
int mood;
float mylim;

   if (mynumber == 1)
      return(-1);

   /* 
    *   Lets just accept that we know 2 and 3 are prime numbers
    */
   if (mynumber <= 3)
      return(mynumber);

   mood = 2;
   mylim = sqrt(mynumber);
   
   while (mood <= mylim) {
      if ((mynumber % mood) == 0) {
         return(-1);
      }
      mood += 1;
   }

   return(mynumber);
}

int do_primes2(int max)
{
int count;
int x, y;
struct timeval st, et;
float bmin;


   x = 2;
   count = 0;
   gettimeofday(&st, NULL);
   while (count < max) {
      y = get_prime2(x);
      if (y > 0) {
         count += 1;
         printf("Prime found(efficient):   %d\n", y);
      }
      x++;
   }

   gettimeofday(&et, NULL);
   bmin = elapsed(st, et);
   printf("   Other data:  count: %d,  time: %f\n", count, bmin);

   return(0);
};

int main()
{
   do_primes2(DOMAX);
}
