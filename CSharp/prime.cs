using System;

namespace prime {

   class primal {

      static int get_prime2(int mynumber)
      {
      int mood, mylim;
      // int count;
      
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
      
         //Console.WriteLine("Iterations to prime:  %d\n", count);
         return(mynumber);
      }
      
      static int do_primes2(int max)
      {
      int count;
      int x, y;
      
      
         x = 2;
         count = 0;
         while (count < max) {
            y = get_prime2(x);
            if (y > 0) {
               count += 1;
               Console.WriteLine(count + " Prime found: " + y);
               if ((count % 10000) == 0 ) {
                  Console.WriteLine("   Other data:  count: " + count);
               }
            }
            x++;
         }
         return(0);
      }
      
      static void Main(string[] args)
      {
         do_primes2(100);
      }
   }
}
