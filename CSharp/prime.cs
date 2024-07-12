using System;

namespace prime {

   class primal {

      static int get_prime2(int mynumber)
      {
      int mood, mylim;
      
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
         
         while (mylim > mood) {
            if ((mynumber % mood) == 0) {
               return(-1);
            }
            mylim = mynumber / mood;
            mood += 2;
         }
      
         return(mynumber);
      }
      
      static void do_primes2(int max)
      {
      int count;
      int x, y;
      
         x = 2;
         count = 0;
         while (count < max) {
            y = get_prime2(x);
            if (y > 0) {
               count += 1;
               Console.Write("{0} -- Prime found: {1}\n", count, y);
            }
            x++;
         }
         return;
      }
      
      static void Main(string[] args)
      {
         do_primes2(100);
      }
   }
}
