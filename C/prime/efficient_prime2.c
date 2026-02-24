#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DOMAX 100000

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
time_t etime, stime;


   x = 2;
   count = 0;
   stime = (int)time((time_t *)NULL);
   while (count < max) {
      y = get_prime2(x);
      if (y > 0) {
         count += 1;
         printf("Prime found(efficient):   %d\n", y);
      }
      x++;
   }

   etime = (int)time((time_t *)NULL);
   printf("   Other data:  count: %d,  time: %ld\n", count, etime - stime);
   stime = (int)time((time_t *)NULL);

   return(0);
};

int main()
{
   do_primes2(DOMAX);
}
