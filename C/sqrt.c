#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

float elapsed(struct timeval st, struct timeval et) {
float elapsed_time = 0.0;

   elapsed_time = (et.tv_sec + (et.tv_usec/1000000.0)) - (st.tv_sec + (st.tv_usec/1000000.0));
   return(elapsed_time);
}

/*
 *   Yes, guess the rest.  We know
 *   the integer part of the value.
 *   Now guess the the rest.  Start by
 *   adding .5 and adjusting by half of
 *   the value up or down depending on
 *   if the value times itself is greater
 *   than what we are looking for.
 */
double guesstherest(long orig, double count) {
double newcount, starter;
int tries;

    tries = 0;
    starter = 0.5;
    newcount = count + starter;
    /*
     *   Set the limit of tries to 75.
     *   Experiments showed that 50 is
     *   probably good enough in terms
     *   of quality of results.  Set
     *   to 75 just to give some room.
     */
    while (tries < 75) {
       tries += 1;
       if ((newcount * newcount) > orig) {
          starter = starter / 2.0;
          newcount = newcount - starter;
       } else if ((newcount * newcount) < orig) {
          /*
           *  This addition of "more" can be done
           *  in different ways.  But, this is the
           *  one that broke the while loop in the
           *  lowest number of attempts on a consistent
           *  basis.
           */
          starter = starter + (starter / 2.0);
          newcount = newcount + starter;
       } else {
          return(newcount);
       }
       /*
        *   Since floating point equality rarely
        *   works well, this is a bailout of
        *   "close enough".  6 places of 
        *   equality after the decimal point.
        */
       if (fabs((newcount * newcount) - orig) < 0.0000001) {
          return(newcount);
       }
    }

    return(newcount);
}

/*
 *   implement sqrt().
 *   Uses a combination of subtract
 *   the odds and final guessing.
 */
double square_root(long orig) {
int i;
long startval;
double count;

   if (orig < 0) {
      printf("sqrt() of negative is imaginary.  Not done here.\n");
      return(NAN);
   }

   startval = orig;
   count = 0;
   i = 1;
   while (orig > 0) {
      orig = orig - i;
      i += 2;
      if (orig < 0) {
          count = guesstherest(startval, count);
      } else {
          count += 1.0;
      }
   }
   return(count);
}

void doit(long number) {
double mynum, mlibnum, mysquare, sqrtsquare;
struct timeval st, et;
float amin, bmin;

   gettimeofday(&st, NULL);
   mynum = square_root(number);
   gettimeofday(&et, NULL);
   amin = (elapsed(st, et) * 1000000);

   gettimeofday(&st, NULL);
   mlibnum = sqrt(number);
   gettimeofday(&et, NULL);
   bmin = (elapsed(st, et) * 1000000);

   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n", mysquare, sqrtsquare);
   printf("square_root() calc time:  %f microseconds\n", amin);
   printf("sqrt()        calc time:  %f microseconds\n\n", bmin);

   return;
}

/*
 *  Run the programs idea of sqrt() and
 *  compare it to the mathlib sqrt() to
 *  see how we did.
 */
int main() {
long number;

   number = 16;
   doit(number);

   number = 25;
   doit(number);

   number = 20;
   doit(number);

   number = 24;
   doit(number);

   number = 39;
   doit(number);

   number = 97;
   doit(number);

   number = 101;
   doit(number);

   number = 2048;
   doit(number);

   number = -113;
   doit(number);

   number = 101101101;
   doit(number);

   number = 7919;
   doit(number);

   printf("And finally, the root of all evil ...\n");
   number = 666;
   doit(number);
}
