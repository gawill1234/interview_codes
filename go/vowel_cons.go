//
//   Count vowels and consonants in
//   a string.
//
//   Not sure how good this way is.
//   I am using techniques from other
//   languages to do this in go.  I
//   believe I could do this with 
//   maps as well.  But, still figuring
//   those out.
//
//   But, there are some useful language
//   features demonstrated here.
//
package main

import ("fmt";"os";"strings")

//
//  Convert a string to an array
//  of runes.  This, or bytes, are
//  the only ways to compare letters
//  within a string.
//
//  Go does not have a "char" type as
//  in C.
//
func StringToRuneSlice(s string) []rune {
var r []rune

   for _, runeValue := range s {
      r = append(r, runeValue)
   }

   return r
}

//
//   Do the "in" function as it is
//   in python, sort of.
//
//   In order to pass the array  to
//   this (or any function) you need
//   to pass in a slice.  So for this
//   I pass in a "slice" of the whole
//   array.  So a call would look like
//
//      In(someletter, somearray[:])
//
func In(a rune, b []rune) bool {

   for _, letter := range b {
      if (a == letter) {
         return true
      }
   }
   return false
}

//
//   Count the letters.  Vowels
//   and consonants.  Return them
//   to the caller.
//
//   Go can return multiple values as long
//   as the function is declared that way.
//   I guess someone at Google liked that
//   python feature.
//
func lettercount(s string) (conscount int, vowelcount int) {
var alphabet = [...]rune {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
var vowels = [...]rune {'a', 'e', 'i', 'o', 'u'}

   conscount = 0
   vowelcount = 0
   thing := StringToRuneSlice(strings.ToLower(s))

   for i := 0; i < len(thing); i++ {
      if In(thing[i], alphabet[:]) {
         if In(thing[i], vowels[:]) {
            vowelcount += 1
         } else {
            conscount += 1
         }
      }
   }

   return
}

func main() {
var a, b int
var mystring string

   //
   //   Apparently the string type
   //   in go is self adjusting.
   //
   mystring = "1Mississippi"
   a, b = lettercount(mystring)
   fmt.Printf("%s\n", mystring)
   fmt.Printf("Consonants:  %d,  Vowels:  %d\n\n", a, b)

   mystring = "abcdefghijklmnopqrstuvwxyz"
   a, b = lettercount(mystring)
   fmt.Printf("%s\n", mystring)
   fmt.Printf("Consonants:  %d,  Vowels:  %d\n\n", a, b)

   mystring = "aBcDeFgHiJkLmNoPqRsTuVwXyZ"
   a, b = lettercount(mystring)
   fmt.Printf("%s\n", mystring)
   fmt.Printf("Consonants:  %d,  Vowels:  %d\n\n", a, b)

   mystring = "hello there"
   a, b = lettercount(mystring)
   fmt.Printf("%s\n", mystring)
   fmt.Printf("Consonants:  %d,  Vowels:  %d\n\n", a, b)

   mystring = "squirrels"
   a, b = lettercount(mystring)
   fmt.Printf("%s\n", mystring)
   fmt.Printf("Consonants:  %d,  Vowels:  %d\n\n", a, b)

   mystring = "Chipmunks"
   a, b = lettercount(mystring)
   fmt.Printf("%s\n", mystring)
   fmt.Printf("Consonants:  %d,  Vowels:  %d\n\n", a, b)

   mystring = "1968 Mustang GT 2+2 fastback"
   a, b = lettercount(mystring)
   fmt.Printf("%s\n", mystring)
   fmt.Printf("Consonants:  %d,  Vowels:  %d\n", a, b)
 
   os.Exit(0)
}
