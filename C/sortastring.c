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
 *  Weird but it works and it's pretty easy once you see
 *  it and it is quick.
 */

void init_array(int *myarray) {
int i;

   for (i = 0; i < 255; i++) {
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
   for (i = 0; i < 255; i++) {
      if (myarray[i] > 0) {
         for (j = 0; j < myarray[i]; j++) {
            sorted[k] = (char *)i;
            k++;
         }
      }
   }

   return(sorted);
}

int main() {
int myarray[256];
char mystring[32];
char *sortedthing;

   strcpy(mystring, "hello");
   init_array(myarray);
   parse_word_string(mystring, myarray);
   sortedthing = sortedarray(myarray);
   printf("%s\n", mystring);
   printf("%s\n", sortedthing);
   free(sortedthing);

   strcpy(mystring, "massive flood");
   init_array(myarray);
   parse_word_string(mystring, myarray);
   sortedthing = sortedarray(myarray);
   printf("%s\n", mystring);
   printf("%s\n", sortedthing);
   free(sortedthing);

   strcpy(mystring, "Mississippi");
   init_array(myarray);
   parse_word_string(mystring, myarray);
   sortedthing = sortedarray(myarray);
   printf("%s\n", mystring);
   printf("%s\n", sortedthing);
   free(sortedthing);

   strcpy(mystring, "smile");
   init_array(myarray);
   parse_word_string(mystring, myarray);
   sortedthing = sortedarray(myarray);
   printf("%s\n", mystring);
   printf("%s\n", sortedthing);
   free(sortedthing);

   strcpy(mystring, "limes");
   init_array(myarray);
   parse_word_string(mystring, myarray);
   sortedthing = sortedarray(myarray);
   printf("%s\n", mystring);
   printf("%s\n", sortedthing);
   free(sortedthing);

   strcpy(mystring, "slime");
   init_array(myarray);
   parse_word_string(mystring, myarray);
   sortedthing = sortedarray(myarray);
   printf("%s\n", mystring);
   printf("%s\n", sortedthing);
   free(sortedthing);
}
