#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/*
 *  Run the programs idea of sqrt() and
 *  compare it to the mathlib sqrt() to
 *  see how we did.
 */
int main() {
long number;
double mynum, mlibnum, mysquare, sqrtsquare;

   number = 16;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = 25;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = 20;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = 24;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = 39;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = 101;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = 2048;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = -113;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = 101101101;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   number = 7919;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);

   printf("And finally, the root of all evil ...\n");
   number = 666;
   mynum = square_root(number);
   mlibnum = sqrt(number);
   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   printf("square root of %ld, program: %f, sqrt(): %f\n", number, mynum, mlibnum);
   printf("             program square: %f, sqrt() square: %f\n\n", mysquare, sqrtsquare);
}
