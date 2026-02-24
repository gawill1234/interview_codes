#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

/*
 *  Does square roots using 4 different ways
 *    math sqrt() function
 *    subtract the odds paired with final guessing
 *    herons method
 *    halleys method
 *
 *  Gets run times for each.  Prints values and run times.
 *  All of them use the same precision level as a quit
 *  parameter (.0000001).
 */

float elapsed(struct timeval st, struct timeval et) {
float elapsed_time = 0.0;

   elapsed_time = (et.tv_sec + (et.tv_usec/1000000.0)) - (st.tv_sec + (st.tv_usec/1000000.0));
   return(elapsed_time);
}

/*
 *   Looks a little like guesstherest() but it
 *   has an actual name.
 */
double halleysmethod(long orig, double count) {
double lastx, nextx;
int tries;

    tries = 0;
    lastx = count;
    /*
     *   Set the limit of tries to 75.
     *   Experiments showed that 50 is
     *   probably good enough in terms
     *   of quality of results.  Set
     *   to 75 just to give some room.
     */
    while (tries < 75) {
       nextx = lastx * (lastx * lastx + 3 * orig) / (3 * lastx * lastx + orig);
       /*
        *   Since floating point equality rarely
        *   works well, this is a bailout of
        *   "close enough".  6 places of
        *   equality after the decimal point.
        */
       if (fabs((nextx * nextx) - orig) < 0.00000001) {
          return(nextx);
       }
       lastx = nextx;
       tries += 1;
    }

    return(nextx);
}

/*
 *   Looks a little like guesstherest() but it
 *   also has an actual name.
 */
double heronsmethod(long orig, double count) {
double lastx, nextx;
int tries;

    tries = 0;
    lastx = count;
    /*
     *   Set the limit of tries to 75.
     *   Experiments showed that 50 is
     *   probably good enough in terms
     *   of quality of results.  Set
     *   to 75 just to give some room.
     */
    while (tries < 75) {
       nextx = .5 * (lastx + (orig / lastx));
       /*
        *   Since floating point equality rarely
        *   works well, this is a bailout of
        *   "close enough".  6 places of
        *   equality after the decimal point.
        */
       if (fabs((nextx * nextx) - orig) < 0.00000001) {
          return(nextx);
       }
       lastx = nextx;
       tries += 1;
    }

    return(nextx);
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
       if (fabs((newcount * newcount) - orig) < 0.00000001) {
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

/*
 *   Find square root using herons method
 */
double square_root_heron(long orig) {
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
   count = heronsmethod(startval, (orig / 2));
   return(count);
}

/*
 *   Find square root using halleys method
 */
double square_root_halley(long orig) {
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
   count = halleysmethod(startval, (orig / 2));
   return(count);
}


void doit(long number) {
double mynum, mlibnum, halleynum, heronnum;
double mysquare, sqrtsquare, halleysquare, heronsquare;
struct timeval st, et;
float amin, bmin, cmin, dmin;
float aavg, bavg, cavg, davg;
int i;

   aavg = bavg = cavg = davg = 0.0;

   for (i = 0; i < 50; i++) {
      gettimeofday(&st, NULL);
      mynum = square_root(number);
      gettimeofday(&et, NULL);
      amin = (elapsed(st, et) * 1000000);
      aavg += amin;
   }

   for (i = 0; i < 50; i++) {
      gettimeofday(&st, NULL);
      mlibnum = sqrt(number);
      gettimeofday(&et, NULL);
      bmin = (elapsed(st, et) * 1000000);
      bavg += bmin;
  }

   for (i = 0; i < 50; i++) {
      gettimeofday(&st, NULL);
      halleynum = square_root_halley(number);
      gettimeofday(&et, NULL);
      cmin = (elapsed(st, et) * 1000000);
      cavg += cmin;
  }

   for (i = 0; i < 50; i++) {
      gettimeofday(&st, NULL);
      heronnum = square_root_heron(number);
      gettimeofday(&et, NULL);
      dmin = (elapsed(st, et) * 1000000);
      davg += dmin;
  }

   aavg = aavg / 50.0;
   bavg = bavg / 50.0;
   cavg = cavg / 50.0;
   davg = davg / 50.0;

   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   heronsquare = heronnum * heronnum;
   halleysquare = halleynum * halleynum;
   printf("square root of %ld, guess:    %f, sqrt():  %f\n", number, mynum, mlibnum);
   printf("square root of %ld, halley(): %f, heron(): %f\n", number, halleynum, heronnum);
   printf("             guess square:  %f, sqrt() square:  %f\n", mysquare, sqrtsquare);
   printf("             halley square: %f, heron() square: %f\n", halleysquare, heronsquare);
   printf("Runtime is average of 50 repeats:\n");
   printf("   guess()      calc time:  %f microseconds\n", aavg);
   printf("   sqrt()       calc time:  %f microseconds\n", bavg);
   printf("   halley()     calc time:  %f microseconds\n", cavg);
   printf("   heron()      calc time:  %f microseconds\n\n", davg);

   return;
}

/*
 *  Run the programs idea of sqrt() and
 *  compare it to the mathlib sqrt() to
 *  see how we did.
 */
int main() {
long number;
struct timeval st, et;
float fmin;

   gettimeofday(&st, NULL);

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

   number = 113;
   doit(number);

   number = 101101101;
   doit(number);

   number = 9109876549;
   doit(number);

   number = 7919;
   doit(number);

   printf("And finally, the root of all evil ...\n");
   number = 666;
   doit(number);

   gettimeofday(&et, NULL);
   fmin = (elapsed(st, et) * 1000000);
   printf("Overall run time:  %f microseconds\n", fmin);
}
