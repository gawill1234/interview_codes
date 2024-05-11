#include <stdio.h>
#include <stdlib.h>

int maxelem(int *elemarr, int arrsz) {
int i, curmax;

   /*
    *  Sorry, there is nothing fancy or tricky
    *  about finding the largest element in an
    *  array.  You have to look at all of the 
    *  elements.  This uses an integer array.
    *  Loop starts at 1 because you initialize
    *  curmax with 0.
    */
   curmax = elemarr[0];
   for (i = 1; i < arrsz; i++) {
      if (elemarr[i] > curmax) {
         curmax = elemarr[i];
      }
   }

   return(curmax);
}

int main() {
int elemarr[] = {401, 1, 99, 3, 5, 8, 462, 102, 4, 199, 301, 14, 87, 71, 5, 9, 200, 151, 88, 400};
int arrmax;

   /*
    *  As long as the array is in scope, you can get its
    *  size/length as below.  If you pass the array to 
    *  another function, this method is no longer possible.
    *  you'll have to pass the length of the array along 
    *  with the array.
    *
    *  size/length here mean "number of elements"
    */
   arrmax = maxelem(elemarr, sizeof(elemarr) / sizeof(elemarr[0]));

   printf("Max element: %d\n", arrmax);
   fflush(stdout);
}
