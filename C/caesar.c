#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
 *   Does the caesar cypher, but written in
 *   C.  Creates the caesar transposition array,
 *   does the encrypt, create the decrypt array,
 *   then doe the actual decrypt.  Uses the same
 *   original string, but does the work with two
 *   different encryption offsets.
 *
 *   This particular variant is very simple.  Only
 *   uses uppercase letters and ignores spaces.  But,
 *   it could be done with the whole ascii set if you
 *   wanted.
 *
 *   This is a variant of the rotate.c program.  Or
 *   what maketran/translate does with python.  Grab
 *   a slice of the "key" string and rotate it and use
 *   that to "encrypt" the message.
 */
void printarray(char *myarray, int arrsz) {
int i;

   printf("Array: ");
   for (i = 0; i < arrsz; i++) {
      printf(" %c", myarray[i]);
   }
   printf("\n");

   return;
}

/*
 *   Allows the use of any value as the shift.
 *   Negative, larger than the array, whatever,
 *   this will put the shift to a number that
 *   makes sense.
 */
int getrealshift(int arrsz, int shift) {

   if (shift < 0) {
      shift = shift * (-1);
      shift = arrsz - (shift % arrsz);
   } else {
      shift = shift % arrsz;
   }

   return(shift);
}

/*
 *  Given a value and a shift, locate where
 *  the second value should go within the 
 *  array.
 */
int secondpos(int start, int arrsz, int shift) {
int newpos;

   newpos = start + shift;
   if (newpos > (arrsz - 1)) {
      newpos = newpos - arrsz;
   }

   return(newpos);
}

/*
 *   Uses a second array to store the values
 *   in the new positions and returns it.
 *   The easy way ...
 *   While you need a second array, this one is
 *   done is one pass through the original array.
 *   Everything goes to the right position on the
 *   first (single) pass.
 *   Shift is to the right.
 */
char *rotate(char *myarray, int arrsz, int shift) {
int i, j;
char *newarray;

   newarray = (char *)calloc(arrsz, sizeof(char));
   shift = getrealshift(arrsz, shift);

   for (i = 0; i < arrsz; i++) {
      j = secondpos(i, arrsz, shift);
      newarray[j] = myarray[i];
   }

   return(newarray);
}

char *new_message(char *newarray, char *message, int arrsz) {
char *my_message;
int i, value;

   my_message = (char *)calloc(strlen(message), sizeof(char));

   for  (i = 0; i < arrsz; i++) {
      value = (int)message[i] - 65;\
      if (value >= 0) {
         my_message[i] = newarray[value];
      }
   }

   return(my_message);
}

int decrypt_key(int maxkeys, int crypt_key) {

   return(maxkeys - crypt_key);
}

int main() {
char myarray[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', \
                  'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char *newarray;
char *message = "HELLO THERE DUDE";
char *sage, *other;
int arrsz, shift;

   arrsz = sizeof(myarray) / sizeof(myarray[0]);
   printf("Original string\n");
   printarray(message, strlen(message));
   printf("\n\n");

   shift = 5;
   newarray = rotate(myarray, arrsz, shift);
   sage = new_message(newarray, message, strlen(message));
   printf("Caesar encrypted string\n");
   printarray(sage, strlen(message));
   free(newarray);
   printf("\n");

   shift = decrypt_key(26, shift);
   newarray = rotate(myarray, arrsz, shift);
   other = new_message(newarray, sage, strlen(message));
   printf("Caesar decrypted string\n");
   printarray(other, strlen(message));
   printf("\n");
   free(sage);
   free(other);
   free(newarray);

   shift = -2;
   newarray = rotate(myarray, arrsz, shift);
   sage = new_message(newarray, message, strlen(message));
   printf("Caesar encrypted string\n");
   printarray(sage, strlen(message));
   printf("\n");
   free(newarray);

   shift = decrypt_key(26, shift);
   newarray = rotate(myarray, arrsz, shift);
   other = new_message(newarray, sage, strlen(message));
   printf("Caesar decrypted string\n");
   printarray(other, strlen(message));
   printf("\n");
   free(sage);
   free(other);
   free(newarray);

   fflush(stdout);
}
