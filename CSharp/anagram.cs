using System;

namespace anagram {
   class Anagram {
      
      /*
       *  Ok, I admit this one is a bit weird.  It sorts
       *  all the letters in an array by counting the each
       *  of the letters in the array.  I.e., For the word
       *  "mississippi" it would create and array that said
       *  of "i", there are 4.  m is 1, p is 2 and s is 4.
       *  then it build a new array based off of those counts.
       *  Which yields "iiiimppssss".
       *
       *  This is a variant of sortastring.c with the code
       *  added to show if two strings are anagrams of each
       *  other.
       */
      
      static int ARRLEN = 256;
      
      static void init_array(int[] myarray) {
      int i;
      
         for (i = 0; i < ARRLEN; i++) {
            myarray[i] = 0;
         }
      
         return;
      }
      
      static void parse_word_string(char[] mystring, int[] myarray) {
      int len, i;
      
         len = mystring.Length;
         for (i = 0; i < len; i++) {
            myarray[(int)Char.ToLower(mystring[i])]++;
         }
      
         return;
      }
      
      static char[] sortedarray(int[] myarray) {
      char[] sorted;
      int i, j, k;
      
         sorted = new char[32];
      
         k = j = 0;
         for (i = 0; i < ARRLEN; i++) {
            if (myarray[i] > 0) {
               for (j = 0; j < myarray[i]; j++) {
                  sorted[k] = (char)i;
                  k++;
               }
            }
         }
      
         return(sorted);
      }
      
      static string runnit(char[] mystring) {
      int[] myarray = new int[ARRLEN];
      char[] sortedthing;
      
         init_array(myarray);
         parse_word_string(mystring, myarray);
         sortedthing = sortedarray(myarray);
      
         return(string.Join("", sortedthing));
      
      }
      
      static void isanagram(string mystring, string mystring2) {
      string sorted1, sorted2;
      
         sorted1 = runnit(mystring.ToCharArray());
         sorted2 = runnit(mystring2.ToCharArray());
         Console.Write("{0}: {1}\n", mystring, sorted1);
         Console.Write("{0}: {1}\n", mystring2, sorted2);
      
         if (sorted1 == sorted2) {
            Console.Write("They are ANAGRAMS\n");
         } else {
            Console.Write("They are NOT ANAGRAMS\n");
         }
         Console.Write("\n");
      
         return;
      }
      
      static void Main(string[] args) {
      
         isanagram("hello", "smile");
         /*
          *   A string of digits is still a string
          *   so could be an anagram of each other.
          */
         isanagram("2468097135", "0246813579");
         isanagram("limes", "smile");
         isanagram("miles", "smile");
         isanagram("slime", "limes");
      
         isanagram("stab", "bats");
         isanagram("Mississippi", "Michigan");
         isanagram("dog", "God");
         isanagram("traps", "strap");
         isanagram("parts", "strap");
      
         isanagram("abcdefghi", "jklmnop");
         isanagram("abcdefghi", "fghabcdei");
      }
   }
}
