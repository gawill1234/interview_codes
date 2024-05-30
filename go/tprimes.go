package main

import ("fmt")

func get_prime2(mynumber int) int {
var mood int

   if (mynumber == 1) {
      return -1
   }

   /* 
    *   Lets just accept that we know 2 and 3 are prime numbers
    */

   if (mynumber <= 3) {
      return mynumber
   }

   /*
    *  Any even number greater than 2 is by definition not a
    *  prime number so we will skip them.
    */
   if ((mynumber % 2) == 0) {
      return -1
   }

   mood = 3
   for ((mood * mood) <= mynumber) {
      if ((mynumber % mood) == 0) {
         return -1
      }
      mood += 2
   }

   return mynumber
}

func do_primes2(max int) int {
var x, y, count int

   x = 2
   count = 0

   for (count < max) {
      y = get_prime2(x)
      if (y > 0) {
         count++
         fmt.Printf("Prime found:   %d,    count: %d\n", y, count)
      }
      x++
   }
   return 0
}

func main() {

   do_primes2(100);
}
