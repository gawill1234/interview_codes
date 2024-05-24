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
 *
 *  So, this is not only a sorter, but it counts the 
 *  number of times a character occurs in a string.
 *
 *  Weird but it works and it's pretty easy once you see
 *  it and it is quick.
 *  A variant of sortastring.c
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

void printcounts(int *myarray) {
int i;

   for (i = 0; i < ARRLEN; i++) {
      if (myarray[i] > 0) {
         printf("     \"%c\": %d\n", (char)i, myarray[i]);
      }
   }
   return;
}

void runnit(char *mystring) {
int myarray[ARRLEN];
char *sortedthing;

   init_array(myarray);
   parse_word_string(mystring, myarray);
   printf("%s\n", mystring);
   printcounts(myarray);

}

int main() {

   runnit("hello");
   runnit("massive flood");
   runnit("Mississippi");
   runnit("smile");
   runnit("limes");
   runnit("slime");
   runnit("Multi space with punctuation!");
   runnit("2468097135");
}
