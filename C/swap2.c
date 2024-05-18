#include <stdio.h> 
#include <stdlib.h>
  
/*
 *   Swap the value of 2 variables
 *   in place with no additional
 *   variables.
 */

void swappit(int a, int b) {

   printf("SWAP,    a: %d, b: %d\n", a, b); 
  
   /*
    *   Code to swap 'a' and 'b' 
    */
   a = a + b; 
   b = a - b; 
   a = a - b; 
  
   printf("SWAPPED, a: %d, b: %d\n\n", a, b); 
   fflush(stdout);

   return;
}
int main() 
{ 

   swappit(9, 23);
   swappit(32, 7);
   swappit(1, 2);
   swappit(-3, 7);
  
   exit(0);
}
