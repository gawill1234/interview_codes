#include <stdio.h>
#include <stdlib.h>

/*
 *   Binary search of an ordered array.
 *   In principal, easy.
 *   In practice, not so much.
 *   The math for moving the look up
 *   location varies with direction
 *   to move it (up or down) and where
 *   it is now and where it was previously.
 *   Quite the mess.
 *   So, this works.  But I'm not really
 *   sure how good it is.  I haven't looked
 *   for anything to compare it to, yet.
 *   So I put it here.  But no guarantees
 *   as to performance.  But at least it is
 *   working.
 *   Though it does seem to comply with the
 *   expected time complexity for each array
 *   size.
 */

/*
 *  I have set this to 1000.  But it can
 *  be changed to anything you want to try
 *  things out.
 *  It has been tested up to 100000 and for
 *  odd number array size (like 999, 1999, etc)
 */
#define ARRSZ 1024

/*
 *   Initialize the array.
 *   All even numbers between
 *   2 and 2000.
 *   So searching of odds should
 *   fail.
 */
void init_array(int *elemarr) {
int i, j;

   j = 2;
   for (i = 0; i < ARRSZ; i++) {
      elemarr[i] = j;
      j += 2;
   }
   return;
}

/*
 *   Find a new value location to check.
 *   curr is the current location.
 *   last is the previous location.
 *   updown is whether to increase or decrease
 *   arrmax is the max array value.  Not the
 *      max size of the array.  The max we can
 *      currently not exceed.  It changes.
 *      see nmax in find_value()
 */
int find_between(int curr, int last, int updown, int arrmax) {
int newvalue = 0;
int useit;
   
   if (updown == 0) {
      if (curr == last) {
         newvalue = curr / 2;
      } else if (curr < last) {
         newvalue = curr - (((last - curr) + 1) / 2);
      } else {
         newvalue = curr - (((curr - last) + 1) / 2);
      }
   } else {
      useit = (arrmax - curr) + 1;
      if (curr == last) {
         newvalue = curr + (useit / 2);
      } else if (curr < last) {
         newvalue = curr + (((last - curr) + 1) / 2);
      } else {
         newvalue = curr + (useit / 2);
      }
   }

   return(newvalue);
   
}

/*
 *   Do the binary search of the array.
 *   Sounds easy?  Not!  There are odd
 *   considerations in moving the value
 *   for searching.  See above.
 */
int find_value(int value, int *elemarr, int arrsz) {
int start, Found, last, oldstart, nmax, count;

    /*
     *   Set start initial value to middle
     *   of array.  If you don't do the "add 1"
     *   bit, it will actually miss stuff that
     *   is in the array.  Applies to other uses
     *   of "add 1" as well (see above).
     */
    start = (arrsz + 1) / 2;

    last = start;
    nmax = arrsz;
    count = 0;

    Found = 0;

    while (Found == 0) {
       /*
        *  is it equal?  if yes,
        *  we are done.  exit loop.
        */
       if (elemarr[start] == value) {
          Found = 1;
       } else {
          /* 
           *   Save last, see below.
           */
          oldstart = start;

          /*
           *   Is the current value high or low?
           */
          if (elemarr[start] > value) {
             /*
              *   reset nmax, the max useable array
              *   value.  If the current(start) location
              *   is too large, there is no need to ever
              *   go beyond it again.  reset nmax.
              */
             nmax = start;
             start = find_between(start, last, 0, nmax);
          } else {
             start = find_between(start, last, 1, nmax);
          }
          last = oldstart;
       }

       /*
        *   Count the look up attempts.
        */
       count += 1;

       /*
        *   If we break the bounds of the search,
        *   the value is not in the array.
        */
       if ((start >= nmax) || (start < 0)) {
          start = -1;
          break;
       }
    }
    printf("LOOK UPS:  %d    ", count);
    return(start);
}

void dump_array(int *elemarr) {
int i;

   for (i = 0; i < ARRSZ; i++) {
      printf("%d\n", elemarr[i]);
   }
   return;
}

int main() {
int elemarr[ARRSZ];
int loc, i;

   /*
    *   Initialize the array.
    */
   init_array(elemarr);
   // dump_array(elemarr);

   /*
    *   Look for various values in the array.
    */
   for (i = -5; i < ARRSZ; i += 43) {
      printf("SEEKING:  %d,  ", i);
      loc = find_value(i, elemarr, ARRSZ);
      if (loc >= 0) {
         printf("loc:  %d,  value: %d\n", loc, elemarr[loc]);
      } else {
         printf("value:  %d, NOT FOUND\n", i);
      }
   }

   printf("####\n####\n");

   for (i = -8; i < (ARRSZ + 42); i += 17) {
      printf("SEEKING:  %d,  ", i);
      loc = find_value(i, elemarr, ARRSZ);
      if (loc >= 0) {
         printf("loc:  %d,  value: %d\n", loc, elemarr[loc]);
      } else {
         printf("value:  %d, NOT FOUND\n", i);
      }
   }

   printf("####\n####\n");

   for (i = 2; i < (ARRSZ * 2); i += 20) {
      printf("SEEKING:  %d,  ", i);
      loc = find_value(i, elemarr, ARRSZ);
      if (loc >= 0) {
         printf("loc:  %d,  value: %d\n", loc, elemarr[loc]);
      } else {
         printf("value:  %d, NOT FOUND\n", i);
      }
   }

   exit(0);
}
