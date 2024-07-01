#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <ctype.h>

typedef int boolean;
#define FALSE 0
#define TRUE 1

/*
 *   Time how long it takes to get
 *   a series of prime numbers using
 *   various methods (do-while, while, for).
 */
//
//   Return the elapsed time based on end_time (et)
//   minus start_time (st).
//
float elapsed(struct timeval st, struct timeval et) {
float elapsed_time = 0.0;

   elapsed_time = (et.tv_sec + (et.tv_usec/1000000.0)) - (st.tv_sec + (st.tv_usec/1000000.0));
   return(elapsed_time);
}

boolean get_prime3(int mynumber)
{
   if (mynumber == 1)
      return(FALSE);

   /*
    *   Lets just accept that we know 2 and 3 are prime numbers
    */

   if (mynumber <= 3)
      return(TRUE);

   /*
    *  Any even number greater than 2 is by definition not a
    *  prime number so we will skip them.
    */
   if ((mynumber % 2) == 0)
      return(FALSE);

   /*
    *  Prime is odd.  So ignore evens.
    *  Only odd * odd can yield an odd number.
    *  So increment divisor by 2, not 1.
    */
   for (int x = 3; (x * x) <= mynumber; x += 2) {
      if ((mynumber % x) == 0) {
         return(FALSE);
      }
   }

   return(TRUE);
}

boolean get_prime1(int mynumber)
{
int mood;

   if (mynumber == 1)
      return(FALSE);

   /* 
    *   Lets just accept that we know 2 and 3 are prime numbers
    */

   if (mynumber <= 3)
      return(TRUE);

   /*
    *  Any even number greater than 2 is by definition not a
    *  prime number so we will skip them.
    */
   if ((mynumber % 2) == 0)
      return(FALSE);

   mood = 1;
   do {
      mood += 2;
      if ((mynumber % mood) == 0) {
         return(FALSE);
      }
   } while ((mood * mood) <= mynumber);

   return(TRUE);
}

boolean get_prime2(int mynumber)
{
int mood;

   if (mynumber == 1)
      return(FALSE);

   /* 
    *   Lets just accept that we know 2 and 3 are prime numbers
    */

   if (mynumber <= 3)
      return(TRUE);

   /*
    *  Any even number greater than 2 is by definition not a
    *  prime number so we will skip them.
    */
   if ((mynumber % 2) == 0)
      return(FALSE);

   mood = 3;
   while ((mood * mood) <= mynumber) {
      if ((mynumber % mood) == 0) {
         return(FALSE);
      }
      mood += 2;
   }

   return(TRUE);
}

int do_primes1(int max)
{
int count;
int x, y;


   x = 2;
   count = 0;
   while (count < max) {
      if (get_prime1(x) == TRUE) {
         count += 1;
         // printf("Prime found(do_primes1):   %d,    count: %d\n", x, count);
      }
      x++;
   }
   return(0);
};

int do_primes2(int max)
{
int count;
int x, y;


   x = 2;
   count = 0;
   while (count < max) {
      if (get_prime2(x) == TRUE) {
         count += 1;
         //printf("Prime found(do_primes2):   %d,    count: %d\n", x, count);
      }
      x++;
   }
   return(0);
};

int do_primes3(int max)
{
int count;
int x, y;


   x = 2;
   count = 0;
   while (count < max) {
      if (get_prime3(x) == TRUE) {
         count += 1;
         //printf("Prime found(do_primes3):   %d,    count: %d\n", x, count);
      }
      x++;
   }
   return(0);
};

int main()
{
struct timeval st, et;
float amin, bmin, cmin;

   for (int z = 0; z < 10; z++) {
      /*
       *   Get prime with while loop
       */
      gettimeofday(&st, NULL);
      do_primes2(100000);
      gettimeofday(&et, NULL);
      amin = (elapsed(st, et) * 1000000);
      printf("get_prime2() Primes time:  %f microseconds\n", amin);

      /*
       *   Get prime with for loop
       */
      gettimeofday(&st, NULL);
      do_primes3(100000);
      gettimeofday(&et, NULL);
      bmin = (elapsed(st, et) * 1000000);
      printf("get_prime3() Primes time:  %f microseconds\n", bmin);

      /*
       *   Get prime with do-while loop
       */
      gettimeofday(&st, NULL);
      do_primes1(100000);
      gettimeofday(&et, NULL);
      cmin = (elapsed(st, et) * 1000000);
      printf("get_prime1() Primes time:  %f microseconds\n", cmin);

      if ((amin < bmin) && (amin < cmin)) {
         printf("get_prime2 Prime faster\n");
      } else if ((bmin < amin) && (bmin < cmin)) {
         printf("get_prime3 Prime faster\n");
      } else if ((cmin < amin) && (cmin < bmin)) {
         printf("get_prime1 Prime faster\n");
      } else {
         printf("Mixed bag\n");
      }
   }
}
