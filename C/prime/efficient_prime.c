#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

double get_prime2(int mynumber)
{
int mood, mylim, count;

   if (mynumber == 1)
      return(-1);

   /* 
    *   Lets just accept that we know 2 and 3 are prime numbers
    */

   if (mynumber <= 3)
      return(mynumber);

   /*
    *  Any even number greater than 2 is by definition not a
    *  prime number so we will skip them.
    */
   if ((mynumber % 2) == 0)
      return(-1);

   mood = 3;
   mylim = mynumber;
   
   //count = 0;
   while (mylim > mood) {
      //count += 1;
      if ((mynumber % mood) == 0) {
         return(-1);
      }
      mylim = mynumber / mood;
      mood += 2;
   }

   //printf("Iterations to prime:  %d\n", count);
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
   while (count < 10000) {
      y = get_prime2(x);
      if (y > 0) {
         count += 1;
         printf("Prime found(efficient):   %d\n", y);
         if ((count % 10000) == 0 ) {
            etime = (int)time((time_t *)NULL);
            printf("   Other data:  count: %d,  time: %d\n", count, etime - stime);
            stime = (int)time((time_t *)NULL);
         }
      }
      x++;
   }
   return(0);
};

main()
{
   do_primes2(100);
}
