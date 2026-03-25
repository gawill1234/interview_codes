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

/*
 *   Swap the value of 2 variables
 *   in place with no additional
 *   variables.
 *   XOR variant.
 */
void swappit2(int a, int b) {

   printf("SWAP,    a: %d, b: %d\n", a, b); 
  
   /*
    *   Code to swap 'a' and 'b' 
    */
   a ^= b;
   b ^= a;
   a ^= b;
  
   printf("SWAPPED, a: %d, b: %d\n\n", a, b); 
   fflush(stdout);

   return;
}
int main() 
{ 

   printf("=========================\n");
   printf("add/subract method of swapping\n");
   swappit(9, 23);
   swappit(32, 7);
   swappit(1, 2);
   swappit(-3, 7);

   printf("=========================\n");
   printf("XOR method of swapping\n");
   swappit2(9, 23);
   swappit2(32, 7);
   swappit2(1, 2);
   swappit2(-3, 7);
  
   exit(0);
}
