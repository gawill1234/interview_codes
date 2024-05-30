// Fibonacci Series python language
package main

import ("fmt";"os")

func main() {
var first int = 0
var second int = 1
var next int = 0
var n int = 30
var c int = 0
 
   fmt.Printf("First %d terms of Fibonacci series are :", n)
 
   for (c < n) {
      if ( c <= 1 ) {
         next = c
      } else {
         next = first + second
         first = second
         second = next
      }
      fmt.Printf("%d\n", next)
      c += 1
   }
 
   os.Exit(0)
}
