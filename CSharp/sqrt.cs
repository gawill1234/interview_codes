using System;

namespace SqrtApp {
   class MySqrt {
      //
      //   Yes, guess the rest.  We know
      //   the integer part of the value.
      //   Now guess the the rest.  Start by
      //   adding .5 and adjusting by half of
      //   the value up or down depending on
      //   if the value times itself is greater
      //   than what we are looking for.
      //
      static double guesstherest(int orig, double count) {
      double newcount, starter;
      int tries;

          tries = 0;
          starter = 0.5;
          newcount = count + starter;
          //
          //   Set the limit of tries to 100.
          //   Experiments showed that 50 is
          //   probably good enough in terms
          //   of quality of results.  Set
          //   to 100 just to give some room.
          //
          while (tries < 100) {
             tries += 1;
             if ((newcount * newcount) > orig) {
                starter = starter / 2.0;
                newcount = newcount - starter;
             } else if ((newcount * newcount) < orig) {
                //
                //  This addition of "more" can be done
                //  in different ways.  But, this is the
                //  one that broke the while loop in the
                //  lowest number of attempts on a consistent
                //  basis.
                ///
                starter = starter + (starter / 2.0);
                newcount = newcount + starter;
             } else {
                return(newcount);
             }
             //
             //   Since floating point equality rarely
             //   works well, this is a bailout of
             //   "close enough".  15 places of 
             //   equality after the decimal point.
	     //   since CSharp uses double for "everything",
	     //   you need a teeny tiny margin of error.
	     //
	     //   The rounding in other languages, unless you
	     //   specify otherwise, is at about 8 places.
             //
             if (Math.Abs((newcount * newcount) - orig) < 0.0000000000000001) {
                return(newcount);
             }
          }

          return(newcount);
      }

      //
      //   implement sqrt().
      //   Uses a combination of subtract
      //   the odds and final guessing.
      ///
      static double square_root(int orig) {
      int i;
      int startval;
      double count;

         if (orig < 0) {
            Console.WriteLine("sqrt() of negative is imaginary.  Not done here.\n");
            return(Single.NaN);
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

      //
      //  Run the programs idea of sqrt() and
      //  compare it to the mathlib sqrt() to
      //  see how we did.
      ///
      static void Main(string[] args) {
         int number;
         double mynum, mlibnum, mysquare, sqrtsquare;
      
         number = 16;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = 25;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = 20;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = 24;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = 39;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = 101;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = 2048;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = -113;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = 101101101;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare + "\n");
      
         number = 7919;
         mynum = square_root(number);
         mlibnum = Math.Sqrt(number);
         mysquare = mynum * mynum;
         sqrtsquare = mlibnum * mlibnum;
         Console.WriteLine("square root of " + number + ", program: " + mynum + ", sqrt(): " + mlibnum);
         Console.WriteLine("             program square: " + mysquare + ", sqrt() square: " + sqrtsquare);
      }
   }
}
