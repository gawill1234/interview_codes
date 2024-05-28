#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void printarray(int *myarray, int arrsz) {
int i;

   printf("Array: ");
   for (i = 0; i < arrsz; i++) {
      printf(" %d", myarray[i]);
   }
   printf("\n");

   return;
}

int divisor(int shift, int arrsz) 
{ 
int temp;

   while (arrsz > 0) {
      if (arrsz == 0) {
         return shift; 
      } else {
         temp = shift;
         shift = arrsz;
         arrsz = temp % arrsz;
      }
   }
   return(shift);
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
int j;

   j = start + shift;
   if (j > (arrsz - 1)) {
      j = j - arrsz;
   }

   return(j);
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
   printf("Supplied shift: %d\n", shift);
   shift = getrealshift(arrsz, shift);
   printf("Actual shift  : %d\n", shift);

   for (i = 0; i < arrsz; i++) {
      j = secondpos(i, arrsz, shift);
      newarray[j] = myarray[i];
   }

   return(newarray);
}

/*
 *   The hard way.  Rotate the array
 *   "in place".  This one is in place,
 *   but it takes "longer" since it can
 *   only go so far through the array at a
 *   time.  So things get moved more
 *   than once.  If the array size is a prime
 *   number size, the shift is always one at
 *   a time.
 *   The divisor thing is a sort of performance
 *   improvement.  If you want it easier, rotate
 *   can always be 1 and it will work just fine.
 *   Shift is to the right.
 */
void rotate2(int *myarray, int arrsz, int shift) {
int i, j, a, temp, rotate;

   printf("Supplied shift: %d\n", shift);
   shift = getrealshift(arrsz, shift);
   printf("Actual shift  : %d\n", shift);
   rotate = divisor(shift, arrsz); 
   printf("shift:  %d,   rotate: %d\n", shift, rotate);

   for (i = 0; i < (arrsz - shift); i++) {
      temp = myarray[i];
      j = i;
      while (1) {
         a = secondpos(j, arrsz, rotate);
         if (a == i)
            break;
         myarray[j] = myarray[a];
         j = a;
      }
      myarray[j] = temp;
   }

   return;
}

/*
 *   Need to reinitialize the array for
 *   the inplace rotation.
 */
void reinit(int *myarray, int arrsz) {
int i;

   for (i = 0; i < arrsz; i++) {
      myarray[i] = i;
   }
}

int main() {
int myarray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int *newarray;
int arrsz, shift;

   arrsz = sizeof(myarray) / sizeof(myarray[0]);

   shift = 5;
   printf("shift: %d,  rotate()\n", shift);
   newarray = rotate(myarray, arrsz, shift);
   printarray(myarray, arrsz);
   printarray(newarray, arrsz);
   free(newarray);
   printf("\n\n");

   printf("shift: %d,  rotate2()\n", shift);
   reinit(myarray, arrsz);
   printarray(myarray, arrsz);
   rotate2(myarray, arrsz, shift);
   printarray(myarray, arrsz);
   printf("\n\n");

   shift = 31;
   reinit(myarray, arrsz);
   printf("shift: %d,  rotate()\n", shift);
   newarray = rotate(myarray, arrsz, shift);
   printarray(myarray, arrsz);
   printarray(newarray, arrsz);
   free(newarray);
   printf("\n\n");

   reinit(myarray, arrsz);
   printf("shift: %d,  rotate2()\n", shift);
   printarray(myarray, arrsz);
   rotate2(myarray, arrsz, shift);
   printarray(myarray, arrsz);
   printf("\n\n");

   shift = -2;
   reinit(myarray, arrsz);
   printf("shift: %d,  rotate()\n", shift);
   newarray = rotate(myarray, arrsz, shift);
   printarray(myarray, arrsz);
   printarray(newarray, arrsz);
   free(newarray);
   printf("\n\n");

   reinit(myarray, arrsz);
   printf("shift: %d,  rotate2()\n", shift);
   printarray(myarray, arrsz);
   rotate2(myarray, arrsz, shift);
   printarray(myarray, arrsz);
   printf("\n\n");

   fflush(stdout);
}
