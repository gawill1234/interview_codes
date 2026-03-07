#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

#include <ctype.h>

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

#define ARRLEN 256

class aWord {
   public:
      int myarray[ARRLEN];
      char *sorted, *origword;

      /*  Constructor  */
      aWord(std::string mystring) {
   
         origword = (char *)calloc(32, 1);
         strcpy(origword, mystring.c_str());

         init_array();
         parse_word_string();
         sortedarray();
   
         return;
   
      }

      /*  Destructor  */
      ~aWord() {
   
         std::printf("Obliterate the allocated memory ...\n");

         free(sorted);
         free(origword);
         return;
   
      }

      char *getOrigWord() {
         return(origword);
      }

      char *getSortWord() {
         return(sorted);
      }

   private:
   
      void init_array() {
      int i;
   
         for (i = 0; i < ARRLEN; i++) {
            myarray[i] = 0;
         }
   
         return;
      }
   
      void parse_word_string() {
      int len, i;
      
         len = strlen(origword);
         for (i = 0; i < len; i++) {
            myarray[(unsigned int)tolower(origword[i])]++;
         }
   
         return;
      }
   
      void sortedarray() {
      unsigned int i, j, k;
   
         sorted = (char *)calloc(32, 1);
   
         k = j = 0;
         for (i = 0; i < ARRLEN; i++) {
            if (myarray[i] > 0) {
               for (j = 0; j < myarray[i]; j++) {
                  sorted[k] = (char)i;
                  k++;
               }
            }
         }
   
         return;
      }
};
   
   
void isanagram(std::string mystring, std::string mystring2) {
char *sorted1, *sorted2;

   aWord word1(mystring);
   aWord word2(mystring2);
   std::printf("%s:  %s\n", word1.getOrigWord(), word1.getSortWord());
   std::printf("%s:  %s\n", word2.getOrigWord(), word2.getSortWord());

   if (strcmp(word1.getSortWord(), word2.getSortWord()) == 0) {
      std::printf("They are ANAGRAMS\n");
   } else {
      std::printf("They are NOT ANAGRAMS\n");
   }
   std::printf("\n");
   fflush(stdout);

   return;
}
   
int main() {

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

   exit(0);
}
