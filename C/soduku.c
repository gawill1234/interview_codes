#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR 0
#define OK 1

#define ROWSIZE 9
#define COLSIZE 9

/*
 *  this is a simple solution to the soduku
 *  check.  There are more complex and
 *  quicker solutions.  But this is the easy
 *  one.
 */

unsigned rowcheck(int r, int soduku[ROWSIZE][COLSIZE])
{
int i, myval, values[COLSIZE];

   for (i = 0; i < COLSIZE; i++) {
      values[i] = 0;
   }

   for (i = 0; i < COLSIZE; i++) {
      myval = soduku[r][i];
      if (myval >= 0) {
         if (myval >= COLSIZE) {
            return(ERROR);
         } else {
            values[myval]++;
            if (values[myval] > 1) {
               return(ERROR);
            }
         }
      }
   }

   return(OK);
}

unsigned colcheck(int c, int soduku[ROWSIZE][COLSIZE])
{
int i, myval, values[ROWSIZE];

   for (i = 0; i < ROWSIZE; i++) {
      values[i] = 0;
   }

   for (i = 0; i < ROWSIZE; i++) {
      myval = soduku[i][c];
      if (myval >= 0) {
         if (myval >= ROWSIZE) {
            return(ERROR);
         } else {
            values[myval]++;
            if (values[myval] > 1) {
               return(ERROR);
            }
         }
      }
   }

   return(OK);
}

unsigned square(int startr, int startc, int soduku[ROWSIZE][COLSIZE])
{
int i, j, myval, values[ROWSIZE];

   for (i = 0; i < ROWSIZE; i++) {
      values[i] = 0;
   }

   for (i = startr; i < startr + 3; i++) {
      for (j = startc; j < startc + 3; j++) {
         myval = soduku[i][j];
         if (myval >= 0) {
            if (myval >= ROWSIZE) {
               printf("SQUARE ERROR(MAX):  %d\n", myval);
               return(ERROR);
            } else {
               values[myval]++;
               if (values[myval] > 1) {
                  printf("SQUARE ERROR(DUP):  %d\n", myval);
                  return(ERROR);
               }
            }
         }
      }
   }

   return(OK);
}

int main() {

int i, j, rok, cok, sqok;
//int soduku[ROWSIZE][COLSIZE] = { 
//                   0,  3,  2,  1,  4,  5,  6,  7,  8,
//                   8,  7,  6,  2,  3,  0,  5,  1,  4,
//                  -1,  4, -1, -1,  8,  7, -1, -1, -1,
//                   3, -1, -1, -1, -1, -1, -1,  2, -1,
//                  -1, -1, -1,  4, -1, -1,  1, -1,  3,
//                  -1,  8, -1, -1, -1,  3, -1, -1, -1,
//                  -1, -1, -1, -1, -1, -1, -1, -1, -1,
//                   1,  0,  4, -1,  7, -1, -1, -1, -1,
//                  -1, -1, -1, -1, -1, -1, -1, -1, -1};
int soduku[ROWSIZE][COLSIZE] = { 
                   0,  1,  2,  3,  4,  5,  6,  7,  8,
                   3,  4,  5,  6,  7,  8,  0,  1,  2,
                   6,  7,  8,  0,  1,  2,  3,  4,  5,
                   1,  2,  3,  4,  5,  6,  7,  8,  0,
                   4,  5,  6,  7,  8,  0,  1,  2,  3,
                   7,  8,  0,  1,  2,  3,  4,  5,  6,
                   2,  3,  4,  5,  6,  7,  8,  0,  1,
                   5,  6,  7,  8,  0,  1,  2,  3,  4,
                   8,  0,  1,  2,  3,  4,  5,  6,  7};


   for (i = 0; i < ROWSIZE; i++) {
      rok = rowcheck(i, soduku);
      if (rok != 1) {
         printf("ROW BARF, %d\n", i);
         break;
      } else {
         printf("ROW %d OK\n", i);
         fflush(stdout);
      }
   }

   for (i = 0; i < COLSIZE; i++) {
      cok = colcheck(i, soduku);
      if (cok != 1) {
         printf("COLUMN BARF, %d\n", i);
         break;
      } else {
         printf("COL %d OK\n", i);
         fflush(stdout);
      }
   }

   for (i = 0; i < ROWSIZE; i += 3) {
      for (j = 0; j < COLSIZE; j += 3) {
         sqok = square(i, j, soduku);
         if (sqok != 1) {
            printf("SQUARE BARF, %d, %d\n", i, j);
            break;
         } else {
            printf("ROW, COL %d, %d OK\n", i, j);
            fflush(stdout);
         }
      }
   }

   if ( rok != 1 || cok != 1 || sqok != 1 ) {
      printf("SODUKU BAD\n");
   } else {
      printf("SODUKU GOOD\n");
   }

}

