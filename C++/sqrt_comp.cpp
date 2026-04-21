#include <cstdio>
#include <iostream>
#include <cmath>

#include <sys/time.h>

using namespace std;

/*
 *  Does square roots using 4 different ways
 *    math sqrt() function
 *    subtract the odds paired with final guessing
 *    herons method using multiplication
 *    herons method using division instead
 *    halleys method
 *
 *  Gets run times for each.  Prints values and run times.
 *  All of them use the same precision level as a quit
 *  parameter (.0000001).
 */

/**************************************************************/
class myTimer {
   public:
      float elapsed_time;
      struct timeval st, et;

   myTimer() {
      elapsed_time = 0.0;
   }

   void elapsed() {

      elapsed_time = (et.tv_sec + (et.tv_usec/1000000.0)) - (st.tv_sec + (st.tv_usec/1000000.0));
      return;
   }

   void startTime() {
      gettimeofday(&st, NULL);
   }

   void endTime() {
      gettimeofday(&et, NULL);
   }

   float getElapsed() {
      elapsed();
      return(elapsed_time);
   }
};
/**************************************************************/

/**************************************************************/
class halleySquare{
   public:
      long orig;
      double count;

   halleySquare(long value) {
      orig = value;
      count = orig / 2.0;

      if (orig < 0) {
         orig =  0;
         std::printf("sqrt() of negative is imaginary.  Not done here.\n");
      }
   }
   /*
    *   Looks a little like guesstherest() but it
    *   has an actual name.
    */
   double halleysmethod() {
   double lastx, nextx;
   int tries;

       tries = 0;
       lastx = count;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 50 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       while (tries < 125) {
          nextx = lastx * (lastx * lastx + 3 * orig) / (3 * lastx * lastx + orig);
          /*
           *   Since floating point equality rarely
           *   works well, this is a bailout of
           *   "close enough".  6 places of
           *   equality after the decimal point.
           */
          if (fabs((nextx * nextx) - orig) < 0.0000000001) {
             return(nextx);
          }
          lastx = nextx;
          tries += 1;
       }

       return(nextx);
   }

   /*
    *   Find square root using halleys method
    */
   double square_root_halley() {

      count = halleysmethod();
      return(count);
   }
};
/**************************************************************/


/**************************************************************/
/*
 *   Looks a little like guesstherest() but it
 *   also has an actual name.
 *
 *   this is herons method, but it uses divide by 2 instead
 *   of multiply by .5.  It is here only to show the performance
 *   difference a divide and a multiply.
 *   division operations can take 10 to 20 cycles.
 *   multiply generally takes 2 or 3 cycles, so faster.
 *
 *   other than that one operation, the two herons method
 *   routines are identical.  So you can see just how much
 *   division adds vs multiplication.
 */
class heronSquareDivide {
   public:
      long orig;
      double count;

   heronSquareDivide(long value) {
      orig = value;
      count = orig / 2.0;

      if (orig < 0) {
         orig =  0;
         std::printf("sqrt() of negative is imaginary.  Not done here.\n");
      }
   }

   /*
    *   Looks a little like guesstherest() but it
    *   also has an actual name.
    */
   double heronsmethod() {
   double lastx, nextx;
   int tries;

       tries = 0;
       lastx = count;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 50 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       while (tries < 125) {
          nextx = (lastx + (orig / lastx)) / 2.0;
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
    *   Find square root using herons method
    */
   double square_root_heron() {

      count = heronsmethod();
      return(count);
   }
};
/**************************************************************/

/**************************************************************/
class heronSquareMult {
   public:
      long orig;
      double count;

   heronSquareMult(long value) {
      orig = value;
      count = orig / 2.0;

      if (orig < 0) {
         orig =  0;
         std::printf("sqrt() of negative is imaginary.  Not done here.\n");
      }
   }

   /*
    *   Looks a little like guesstherest() but it
    *   also has an actual name.
    */
   double heronsmethod() {
   double lastx, nextx;
   int tries;

       tries = 0;
       lastx = count;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 50 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       while (tries < 125) {
          nextx = 0.5 * (lastx + (orig / lastx));
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
    *   Find square root using herons method
    */
   double square_root_heron() {

      count = heronsmethod();
      return(count);
   }
};
/**************************************************************/

/**************************************************************/
class guessSquareRoot {
   public:
      long orig;
      double count;

   guessSquareRoot(long value) {
      count = 0.0;
      orig = value;

      if (orig < 0) {
         orig =  0;
         std::printf("sqrt() of negative is imaginary.  Not done here.\n");
      }
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
   double guesstherest() {
   double newcount, starter;
   int tries;

       tries = 0;
       starter = 0.5;
       newcount = count + starter;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 75 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       while (tries < 125) {
          tries += 1;
          if ((newcount * newcount) > orig) {
             starter = starter * .5;
             newcount = newcount - starter;
          } else if ((newcount * newcount) < orig) {
             /*
              *  This addition of "more" can be done
              *  in different ways.  But, this is the
              *  one that broke the while loop in the
              *  lowest number of attempts on a consistent
              *  basis.
              */
             starter = starter + (starter * .5);
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
          if (fabs((newcount * newcount) - orig) < 0.000000001) {
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
   double square_root() {
   int i;
   long startval;

      startval = orig;
      i = 1;
      while (startval > 0) {
         startval = startval - i;
         i += 2;
         if (startval < 0) {
             count = guesstherest();
         } else {
             count += 1.0;
         }
      }
      return(count);
   }
};
/**************************************************************/

void doit(long number) {
double mynum, mlibnum, halleynum, heronnum, herond2num;
double mysquare, sqrtsquare, halleysquare, heronsquare, herond2square;
struct timeval st, et;
float amin, bmin, cmin, dmin, emin;
float aavg, bavg, cavg, davg, eavg;
int i;

   aavg = bavg = cavg = davg = 0.0;

   if (number < 0) {
      std::printf("sqrt() of negative is imaginary.  Not done here.\n");
      return;
   }

   myTimer timerObj;

   for (i = 0; i < 50; i++) {
      guessSquareRoot myGuess(number);
      timerObj.startTime();
      mynum = myGuess.square_root();
      timerObj.endTime();
      amin = (timerObj.getElapsed() * 1000000);
      aavg += amin;
   }

   for (i = 0; i < 50; i++) {
      timerObj.startTime();
      mlibnum = std::sqrt(number);
      timerObj.endTime();
      bmin = (timerObj.getElapsed() * 1000000);
      bavg += bmin;
  }

   for (i = 0; i < 50; i++) {
      halleySquare myHalley(number);
      timerObj.startTime();
      halleynum = myHalley.square_root_halley();
      timerObj.endTime();
      cmin = (timerObj.getElapsed() * 1000000);
      cavg += cmin;
  }

   for (i = 0; i < 50; i++) {
      heronSquareMult myHeron(number);
      timerObj.startTime();
      heronnum = myHeron.square_root_heron();
      timerObj.endTime();
      dmin = (timerObj.getElapsed() * 1000000);
      davg += dmin;
  }

   for (i = 0; i < 50; i++) {
      heronSquareDivide myHerond2(number);
      timerObj.startTime();
      herond2num = myHerond2.square_root_heron();
      timerObj.endTime();
      emin = (timerObj.getElapsed() * 1000000);
      eavg += emin;
  }

   aavg = aavg / 50.0;
   bavg = bavg / 50.0;
   cavg = cavg / 50.0;
   davg = davg / 50.0;
   eavg = eavg / 50.0;

   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   heronsquare = heronnum * heronnum;
   herond2square = herond2num * herond2num;
   halleysquare = halleynum * halleynum;

   std::printf("##################################################\n");
   std::printf("SQUARE ROOT of %ld\n", number);
   std::printf("   guess:      %f, sqrt():  %f\n",  mynum, mlibnum);
   std::printf("   halley():   %f, heron(): %f\n",  halleynum, heronnum);
   std::printf("   heron_d2(): %f\n",  herond2num);
   std::printf("   guess square:      %f, sqrt() square:    %f\n", mysquare, sqrtsquare);
   std::printf("   halley square:     %f, heron() square:   %f\n", halleysquare, heronsquare);
   std::printf("   heron_d2() square: %f\n", herond2square);
   std::printf("Runtime is average of 50 repeats:\n");
   std::printf("   guess()             calc time:  %f microseconds\n", aavg);
   std::printf("   sqrt()              calc time:  %f microseconds\n", bavg);
   std::printf("   halley()            calc time:  %f microseconds\n", cavg);
   std::printf("   heron()/multiply    calc time:  %f microseconds\n", davg);
   std::printf("   heron_d2()/divide   calc time:  %f microseconds\n", eavg);
   std::printf("##################################################\n\n");

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
myTimer localTime;

   localTime.startTime();

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

   std::printf("And finally, the root of all evil ...\n");
   number = 666;
   doit(number);

   localTime.endTime();
   fmin = (localTime.getElapsed() * 1000000);
   std::printf("Overall run time:  %f microseconds\n", fmin);
}
