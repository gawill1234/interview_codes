package main
  
import ("fmt"; "os")
 
/*
 *   Swap the value of 2 variables
 *   in place with no additional
 *   variables.
 */

func swappit(a int, b int) {

   fmt.Printf("SWAP,    a: %d, b: %d\n", a, b)
  
   /*
    *   Code to swap 'a' and 'b' 
    */
   a = a + b
   b = a - b
   a = a - b
  
   fmt.Printf("SWAPPED, a: %d, b: %d\n\n", a, b)

   return
}
func main() {

   swappit(9, 23)
   swappit(32, 7)
   swappit(1, 2)
   swappit(-3, 7)
  
   os.Exit(0)
}
