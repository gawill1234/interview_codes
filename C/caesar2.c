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
 *   This variant sets a translation array to the
 *   ascii table values.  It uses the integer values
 *   to translate a string to something else and back.
 *
 *   This is a variant of the rotate.c program.  Or
 *   what maketran/translate does with python.  Grab
 *   a slice of the "key" string and rotate it and use
 *   that to "encrypt" the message.
 */
void printarray(char *myarray, int arrsz) {
int i;

   printf("Array: ");
   printf("%s\n", myarray);

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
int *rotate(int *myarray, int arrsz, int shift) {
int i, j;
int *newarray;

   newarray = (int *)calloc(arrsz, sizeof(int));
   shift = getrealshift(arrsz, shift);

   for (i = 0; i < arrsz; i++) {
      j = secondpos(i, arrsz, shift);
      newarray[j] = myarray[i];
   }

   return(newarray);
}

char *new_message(int *newarray, char *message, int arrsz) {
char *my_message;
int i, value;

   my_message = (char *)calloc(strlen(message), sizeof(char));

   for  (i = 0; i < arrsz; i++) {
      value = (int)message[i];
      if (value >= 0) {
         my_message[i] = (char)newarray[value];
      }
   }

   return(my_message);
}

/*
 *  The decryption key is the array size
 *  (number of characters in the original array)
 *  minus the encryption key.  So, if 5 was used
 *  to encrypt, and there are 26 elements in the
 *  translation array, the decrypt key will be
 *  26 - 5 = 21.  Then that is used to retranslate
 *  the encrypted value back to what it was
 *  originally.
 */
int decrypt_key(int maxkeys, int crypt_key) {

   return(maxkeys - crypt_key);
}

/*
 *   Make the translation array the whole of the ascii
 *   table.
 */
int *init_basearray(int arrsz) {
int *myarray;
int i;

   myarray = (int *)calloc(arrsz, sizeof(int));
   for (i = 0; i < arrsz; i++) {
      myarray[i] = i;
   }

   return(myarray);
}

int main() {
int *newarray, *myarray;
char *message = "JOB HUNTING IS THE SEVENTH LEVEL OF HELL.";
char *sage, *other;
int arrsz, shift, i, dshift;

   arrsz = 127;
   myarray = init_basearray(arrsz);

   printf("Original string\n");
   printarray(message, strlen(message));
   printf("\n\n");

   /*
    *   Test every legal shift, plus some that seem
    *   not so legal.  Make sure they all work.
    *   So both encrypt and decrypt should work.
    */
   for (i = -2; i < 135; i++) {
      shift = i;
      dshift = decrypt_key(arrsz, shift);
      printf("Shifts provided:  %d, %d\n", shift, dshift);
      printf("Shifts actual  :  %d, %d\n", getrealshift(arrsz, shift), getrealshift(arrsz, dshift));
      newarray = rotate(myarray, arrsz, shift);
      sage = new_message(newarray, message, strlen(message));
      printf("Caesar encrypted string\n");
      printarray(sage, strlen(message));
      free(newarray);
      printf("\n");

      shift = decrypt_key(arrsz, shift);
      newarray = rotate(myarray, arrsz, shift);
      other = new_message(newarray, sage, strlen(message));
      printf("Caesar decrypted string\n");
      printarray(other, strlen(message));
      printf("#####################\n");
      printf("\n");
      free(sage);
      free(other);
      free(newarray);
   }

   fflush(stdout);
}
