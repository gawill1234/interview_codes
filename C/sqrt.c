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
float guesstherest(long orig, float count) {
float newcount, starter;
int tries;

    tries = 0;
    starter = 0.5;
    newcount = count + starter;
    /*
     *   Set the limit of tries to 100.
     *   Seems as good as anything else.
     */
    while (tries < 100) {
       tries += 1;
       if ((newcount * newcount) > orig) {
          starter = starter / 2.0;
          newcount = newcount - starter;
       } else if ((newcount * newcount) < orig) {
          starter = starter + (starter / 2.0);
          newcount = newcount + starter;
       } else {
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
float square_root(long orig) {
int i;
long startval;
float count;

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
float mynum, mlibnum, mysquare, sqrtsquare;

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
}
