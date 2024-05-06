/*
   This program illustrates many of the questions which are used as
   interview questions at FORE(and other places) to help determine
   competency in the C programming language.  The items which are
   in this program are:

      function pointers
      check alignment of (void *)
      num bits(many different ones)
         mask and shift
         value & (value - 1)
         value % 2      (2 different)
         table look up  (2 different, both good 0 to 255, not just 127)
      number odd or even
         value % 2
         value & 01
      string reverse(in place with one temp variable, 3 different)
      is a machine big endian or little endian(how to determine)
      sentence reverse(words interchanged, not letters within words)

   Others which are not here yet:
      detecting a cycle in a linked list
      inserting an item in a linked list
      remove an item from a linked list
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <ctype.h>

//
//   Return the elapsed time based on end_time (et)
//   minus start_time (st).
//
float elapsed(struct timeval st, struct timeval et) {
float elapsed_time = 0.0;

   elapsed_time = (et.tv_sec + (et.tv_usec/1000000.0)) - (st.tv_sec + (st.tv_usec/1000000.0));
   return(elapsed_time);
}

double get_prime2(int mynumber)
{
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

   /*
    *  Prime is odd.  So ignore evens.
    *  Only odd * odd can yield an odd number.
    *  So increment divisor by 2, not 1.
    */
   for (int x = 3; (x * x) <= mynumber; x += 2) {
      if ((mynumber % x) == 0) {
         return(-1);
      }
   }
   
   return(mynumber);
}

int do_primes2(int max)
{
int count;
int x, y;


   x = 2;
   count = 0;
   while (count < max) {
      y = get_prime2(x);
      if (y > 0) {
         count += 1;
         printf("Prime found(efficient):   %d,    count: %d\n", y, count);
      }
      x++;
   }
   return(0);
};

int main()
{
struct timeval st, et;

   gettimeofday(&st, NULL);
   do_primes2(1000);
   gettimeofday(&et, NULL);
   printf("Primes time:  %f microseconds\n", (elapsed(st, et) * 1000000));
}
