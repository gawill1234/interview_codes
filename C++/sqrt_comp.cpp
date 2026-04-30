#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>

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
 *  parameter (.0000000001).
 *
 *  If you want to see the effects of compiler optimization,
 *  try these various compiler options (g++/gcc).
 *
 *  
 *  standard compile.  Subtract the odds (subto) and heron_d2
 *  will take noticably more time.
 *     g++ -o sqnopt sqrt_comp.cpp
 *
 *  Optimized compiles.  The most notable changes will be the subto
 *  runtimes for larger numbers.  Also, division is highly optimized
 *  when constants are involved so can become faster than the multiply
 *  variant of the same code (heron).
 *     g++ -O3 -mavx -floop-parallelize-all -ftree-parallelize-loops=4 \
 *         -o sqopt sqrt_comp.cpp
 *
 *     g++ -O3 -Ofast -mavx -floop-parallelize-all -ftree-parallelize-loops=4 \
 *         -o sqfst sqrt_comp.cpp
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
         orig = 0;
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

       lastx = count;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 50 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       for (tries = 0; tries < 125; tries++) {
          nextx = (((lastx * lastx) + (3 * orig)) * lastx) / (((3 * lastx) * lastx) + orig);
          /*
           *   Since floating point equality rarely
           *   works well, this is a bailout of
           *   "close enough".  6 places of
           *   equality after the decimal point.
           */
          if (fabs((nextx * nextx) - orig) < 0.00000000001) {
             return(nextx);
          }
          lastx = nextx;
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

       lastx = count;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 50 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       for (tries = 0; tries < 125; tries++) {
          nextx = (lastx + (orig / lastx)) / 2.0;
          /*
           *   Since floating point equality rarely
           *   works well, this is a bailout of
           *   "close enough".  6 places of
           *   equality after the decimal point.
           */
          if (fabs((nextx * nextx) - orig) < 0.00000000001) {
             return(nextx);
          }
          lastx = nextx;
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
class Newton {
   public:
      long orig;
      double count;

   Newton(long value) {
      orig = value;
      count = 0.0;

      if (orig < 0) {
         orig =  0;
         std::printf("sqrt() of negative is imaginary.  Not done here.\n");
      }
   }

   /*
    *   Looks a little like guesstherest() but it
    *   also has an actual name.
    */
   double newtonsmethod() {
   double z = 1.0;

      for (int i = 1; i <= 100; i++) {
        z -= ((z * z) - orig) / (z + z);
        if (fabs((z * z) - orig) < 0.00000000001) {
           return(z);
        }
      }
      return(z);
   }


   /*
    *   Find square root using herons method
    */
   double square_root_newton() {

      count = newtonsmethod();
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

       lastx = count;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 50 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       for (tries = 0; tries < 125; tries++) {
          nextx = .5 * (lastx + (orig / lastx));
          /*
           *   Since floating point equality rarely
           *   works well, this is a bailout of
           *   "close enough".  6 places of
           *   equality after the decimal point.
           */
          if (fabs((nextx * nextx) - orig) < 0.00000000001) {
             return(nextx);
          }
          lastx = nextx;
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
/*
 *    This class uses a bitwise calculation of the integer
 *    portion of the square root followed by a binary search
 *    type guess for the floating point portion.
 */
class guessSquareRoot2 {
   public:
      long orig;
      double count;

   guessSquareRoot2(long value) {
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

       starter = 0.5;
       newcount = count + starter;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 75 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       for (tries = 0; tries < 125; tries++) {
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
          if (fabs((newcount * newcount) - orig) < 0.000000000001) {
             return(newcount);
          }
       }

       return(newcount);
   };

   /*
    *   A more efficient way of getting the base (integer)
    *   portion of the sqrt before starting the guess part.
    */
   unsigned long sqroot_base() {
   unsigned long i = 0;
   unsigned long x = orig;
   unsigned long k = 1;

     while (k <= x) {
          k = k << 2;
     }
     k = k >> 2;

     while (k != 0) {
        if (x >= (i + k)) {
           x = x - (i + k);
           i = i + (2 * k);
        }
        i = i / 2;
        k = k / 4;
     }

     return(i);
   }


   double square_root() {

      count = (double)sqroot_base();
      if ((count * count) < orig) {
         count = guesstherest();
      }
      return(count);
   }
};
/**************************************************************/
/**************************************************************/
/*
 *    This class uses a subract the odds calculation of the integer
 *    portion of the square root followed by a binary search
 *    type guess for the floating point portion.
 */
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

       starter = 0.5;
       newcount = count + starter;
       /*
        *   Set the limit of tries to 125.
        *   Experiments showed that 75 is
        *   probably good enough in terms
        *   of quality of results.  Set
        *   to 125 just to give some room.
        */
       for (tries = 0; tries < 125; tries++) {
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
          if (fabs((newcount * newcount) - orig) < 0.000000000001) {
             return(newcount);
          }
       }

       return(newcount);
   };

   /*
    *   implement sqrt().
    *   Uses a combination of subtract
    *   the odds and final guessing.
    *   This guessing method can get the square root on 
    *   its own.  Have not timed that yet.
    */
   double square_root() {
   int i;
   long startval;

      count = 0.0;
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
double mynum, mlibnum, halleynum, heronnum, herond2num, newtonnum, babelnum, guess2num;
double mysquare, sqrtsquare, halleysquare, heronsquare; 
double herond2square, newtonsquare, babelsquare, guess2square;
struct timeval st, et;
float amin, bmin, cmin, dmin, emin, fmin, hmin;
float aavg, bavg, cavg, davg, eavg, favg, havg;
float amax, bmax, cmax, dmax, emax, fmax, hmax;
int i, maxruns;

   aavg = bavg = cavg = davg = eavg = favg = havg = 0.0;
   amax = bmax = cmax = dmax = emax = fmax = hmax = 0.0;
   maxruns = 200;

   if (number < 0) {
      std::printf("sqrt() of negative is imaginary.  Not done here.\n");
      return;
   }

   myTimer timerObj;

   for (i = 0; i < maxruns; i++) {
      timerObj.startTime();
      mlibnum = std::sqrt(number);
      timerObj.endTime();
      bmin = (timerObj.getElapsed() * 1000000);
      bavg += bmin;
      if (bmin > bmax) {
	 bmax = bmin;
      }
  }

   guessSquareRoot myGuess(number);
   for (i = 0; i < maxruns; i++) {
      //guessSquareRoot myGuess(number);
      timerObj.startTime();
      mynum = myGuess.square_root();
      timerObj.endTime();
      amin = (timerObj.getElapsed() * 1000000);
      aavg += amin;
      if (amin > amax) {
	 amax = amin;
      }
   }

   halleySquare myHalley(number);
   for (i = 0; i < maxruns; i++) {
      //halleySquare myHalley(number);
      timerObj.startTime();
      halleynum = myHalley.square_root_halley();
      timerObj.endTime();
      cmin = (timerObj.getElapsed() * 1000000);
      cavg += cmin;
      if (cmin > cmax) {
	 cmax = cmin;
      }
  }

   heronSquareMult myHeron(number);
   for (i = 0; i < maxruns; i++) {
      //heronSquareMult myHeron(number);
      timerObj.startTime();
      heronnum = myHeron.square_root_heron();
      timerObj.endTime();
      dmin = (timerObj.getElapsed() * 1000000);
      davg += dmin;
      if (dmin > dmax) {
	 dmax = dmin;
      }
  }

   heronSquareDivide myHerond2(number);
   for (i = 0; i < maxruns; i++) {
      //heronSquareDivide myHerond2(number);
      timerObj.startTime();
      herond2num = myHerond2.square_root_heron();
      timerObj.endTime();
      emin = (timerObj.getElapsed() * 1000000);
      eavg += emin;
      if (emin > emax) {
	 emax = emin;
      }
  }

   Newton myNewton(number);
   for (i = 0; i < maxruns; i++) {
      //Newton myNewton(number);
      timerObj.startTime();
      newtonnum = myNewton.square_root_newton();
      timerObj.endTime();
      fmin = (timerObj.getElapsed() * 1000000);
      favg += fmin;
      if (fmin > fmax) {
	 fmax = fmin;
      }
  }

   guessSquareRoot2 myGuess2(number);
   for (i = 0; i < maxruns; i++) {
      //guessSquareRoot2 myGuess2(number);
      timerObj.startTime();
      guess2num = myGuess2.square_root();
      timerObj.endTime();
      hmin = (timerObj.getElapsed() * 1000000);
      havg += hmin;
      if (hmin > hmax) {
	 hmax = hmin;
      }
   }

   aavg = (aavg - amax) / (maxruns - 1);
   bavg = (bavg - bmax) / (maxruns - 1);
   cavg = (cavg - cmax) / (maxruns - 1);
   davg = (davg - dmax) / (maxruns - 1);
   eavg = (eavg - emax) / (maxruns - 1);
   favg = (favg - fmax) / (maxruns - 1);
   havg = (havg - hmax) / (maxruns - 1);

   mysquare = mynum * mynum;
   sqrtsquare = mlibnum * mlibnum;
   heronsquare = heronnum * heronnum;
   herond2square = herond2num * herond2num;
   halleysquare = halleynum * halleynum;
   newtonsquare = newtonnum * newtonnum;
   babelsquare = babelnum * babelnum;
   guess2square = guess2num * guess2num;

   std::printf("##################################################\n");
   std::printf("SQUARE ROOT of %ld\n", number);
   std::printf("   sqrt():     %f  (libm sqrt() function value)\n", mlibnum);
   std::printf("   subto:      %f, bitwse():  %f\n",  mynum, guess2num);
   std::printf("   halley():   %f, heron():   %f\n",  halleynum, heronnum);
   std::printf("   heron_d2(): %f, newton():  %f\n\n",  herond2num, newtonnum);

   std::printf("SQUARE OF THE SQUARE ROOT of %ld\n", number);
   std::printf("   sqrt() square:     %f  (libm sqrt() function squared)\n", sqrtsquare);
   std::printf("   subto square:      %f, bitwse() square:  %f\n", mysquare, guess2square);
   std::printf("   halley square:     %f, heron() square:   %f\n", halleysquare, heronsquare);
   std::printf("   heron_d2() square: %f, newton() square:  %f\n\n", herond2square, newtonsquare);

   std::printf("Runtime is average of %d repeats:\n", maxruns);
   std::printf("   sqrt()             calc time:  %f microseconds(libm sqrt() time)\n", bavg);
   std::printf("   subto()            calc time:  %f microseconds\n", aavg);
   std::printf("   bitwse()           calc time:  %f microseconds\n", havg);
   std::printf("   halley()           calc time:  %f microseconds\n", cavg);
   std::printf("   heron()/multiply   calc time:  %f microseconds\n", davg);
   std::printf("   heron_d2()/divide  calc time:  %f microseconds\n", eavg);
   std::printf("   newton             calc time:  %f microseconds\n", favg);
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

   return(0);
}
