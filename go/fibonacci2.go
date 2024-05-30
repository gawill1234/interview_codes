// Fibonacci Series python language
//
//   Illustrate one of the other ways
//   of initializing variables in go.
//   go lets you type at initialization
//   if you init by using ":=".
//
package main

import ("fmt";"os")

func main() {

   first := 0
   second := 1
   next := 0
   n := 30
   c := 0
 
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
