package main

import (
    "fmt"
)

func factorial(n int) {
var factorial uint64 = 1

   // show error if the user enters a negative integer
   if (n < 0) {
      fmt.Printf("Error! Factorial of a negative number doesn't exist.")
   } else {
      for i := 1; i <= n; i++ {
         factorial = factorial * uint64(i)
      }
      fmt.Printf("Factorial of %d = %d\n", n, factorial)
   }

   return
}

func factorial2(n uint64) {
var total uint64 = 1
var mynumber uint64

   mynumber = n

   for (mynumber > 1) {
      total = total * mynumber
      mynumber -= 1
   }
   fmt.Printf("Factorial of %d = %d\n", n, total)

   return
}

func main() {

   factorial(5)
   factorial(11)
   factorial(17)
   factorial(8)
   factorial(7)
   fmt.Printf("\n\n")
   factorial2(5)
   factorial2(11)
   factorial2(17)
   factorial2(8)
   factorial2(7)
}
