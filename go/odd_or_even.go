package main

import (
    "fmt"
    "math"
)

/**********************************************************************/
/*   Odd or even number, by mod 2  */
func odd_or_even(target int) {

   if (math.Abs(float64(target % 2)) == 1) {
      fmt.Printf("odd even(mod 2) %d is an ODD number\n", target)
   } else {
      fmt.Printf("odd even(mod 2) %d is an EVEN number\n", target)
   }

}

/*   Odd or even number, by anding with 01  */
func odd_or_even2(target int) {

   if ((target & 01) == 1) {
      fmt.Printf("odd even(and) %d is an ODD number\n", target)
   } else {
      fmt.Printf("odd even(and) %d is an EVEN number\n", target)
   }

}
/**********************************************************************/

func main() {

   odd_or_even(1)
   odd_or_even(2)
   odd_or_even(-1)
   odd_or_even(-2)
   odd_or_even(107)
   odd_or_even(-107)
   odd_or_even(108)
   odd_or_even(-108)
   fmt.Printf("\n\n")

   odd_or_even2(1)
   odd_or_even2(2)
   odd_or_even2(-1)
   odd_or_even2(-2)
   odd_or_even2(107)
   odd_or_even2(-107)
   odd_or_even2(108)
   odd_or_even2(-108)
}
