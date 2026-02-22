/*
 *   Go version of square root program
 */
package main

import (
    "fmt"
    "os"
    "math"
)

func guesstherest(orig float64, count float64) float64 {
var newcount, starter float64
var tries int

    tries = 0
    starter = 0.5
    newcount = count + starter
    /*
     *   Set the limit of tries to 150.
     *   Experiments showed that 50 is
     *   probably good enough in terms
     *   of quality of results, in C.  Set
     *   to 150 just to give some room.
     */
    for (tries < 150) {
       tries += 1
       if ((newcount * newcount) > orig) {
          starter = starter / 2.0
          newcount = newcount - starter
       } else if ((newcount * newcount) < orig) {
          /*
           *  This addition of "more" can be done
           *  in different ways.  But, this is the
           *  one that broke the while loop in the
           *  lowest number of attempts on a consistent
           *  basis.
           */
          starter = starter + (starter / 2.0)
          newcount = newcount + starter
       } else {
          return(newcount)
       }
       /*
        *   Since floating point equality rarely
        *   works well, this is a bailout of
        *   "close enough".  8(ish) places of
        *   equality after the decimal point.
        */
       if (math.Abs((newcount * newcount) - orig) < 0.00000001) {
          return(newcount)
       }
    }

    return(newcount)
}

func square_root(orig float64) float64 {
var count, startval, i float64

   if (orig < 0) {
      fmt.Println("sqrt() of negative is imaginary.  Not done here.\n")
      return(-1.0)
   }

   startval = orig
   count = 0
   i = 1
   for (orig > 0) {
      orig = orig - i
      i += 2.0
      if (orig < 0) {
          count = guesstherest(startval, count)
      } else {
          count += 1.0
      }
   }
   return(count)
}

func main() {
var mine, other float64
var value float64

   
   value = 25
   mine = square_root(value)
   other = math.Sqrt(value)
   fmt.Printf("Root of %f(program)  : %.7f,  %.7f\n", value, mine, mine * mine)
   fmt.Printf("Root of %f(math.Sqrt): %.7f,  %.7f\n\n", value, other, other * other)

   value = 16
   mine = square_root(value)
   other = math.Sqrt(value)
   fmt.Printf("Root of %f(program)  : %.7f,  %.7f\n", value, mine, mine * mine)
   fmt.Printf("Root of %f(math.Sqrt): %.7f,  %.7f\n\n", value, other, other * other)

   value = 30
   mine = square_root(value)
   other = math.Sqrt(value)
   fmt.Printf("Root of %f(program)  : %.7f,  %.7f\n", value, mine, mine * mine)
   fmt.Printf("Root of %f(math.Sqrt): %.7f,  %.7f\n\n", value, other, other * other)

   value = 97
   mine = square_root(value)
   other = math.Sqrt(value)
   fmt.Printf("Root of %f(program)  : %.7f,  %.7f\n", value, mine, mine * mine)
   fmt.Printf("Root of %f(math.Sqrt): %.7f,  %.7f\n\n", value, other, other * other)

   value = 101101101
   mine = square_root(value)
   other = math.Sqrt(value)
   fmt.Printf("Root of %f(program)  : %.7f,  %.7f\n", value, mine, mine * mine)
   fmt.Printf("Root of %f(math.Sqrt): %.7f,  %.7f\n\n", value, other, other * other)

   value = 666
   mine = square_root(value)
   other = math.Sqrt(value)
   fmt.Printf("Root of %f(program)  : %.7f,  %.7f\n", value, mine, mine * mine)
   fmt.Printf("Root of %f(math.Sqrt): %.7f,  %.7f\n\n", value, other, other * other)

   os.Exit(1)
}
