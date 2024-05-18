#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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

void init_array(int *myarray) {
int i;

   for (i = 0; i < ARRLEN; i++) {
      myarray[i] = 0;
   }

   return;
}

void parse_word_string(char *mystring, int *myarray) {
int len, i;

   len = strlen(mystring);
   for (i = 0; i < len; i++) {
      myarray[(unsigned int)tolower(mystring[i])]++;
   }

   return;
}

char *sortedarray(int *myarray) {
char *sorted;
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

   return(sorted);
}

char *runnit(char *mystring) {
int myarray[ARRLEN];
char *sortedthing;

   init_array(myarray);
   parse_word_string(mystring, myarray);
   sortedthing = sortedarray(myarray);

   return(sortedthing);

}

void isanagram(char *mystring, char *mystring2) {
char *sorted1, *sorted2;

   sorted1 = runnit(mystring);
   sorted2 = runnit(mystring2);
   printf("%s:  %s\n", mystring, sorted1);
   printf("%s:  %s\n", mystring2, sorted2);

   if (strcmp(sorted1, sorted2) == 0) {
      printf("They are ANAGRAMS\n");
   } else {
      printf("They are NOT ANAGRAMS\n");
   }
   printf("\n");
   fflush(stdout);

   free(sorted1);
   free(sorted2);
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
