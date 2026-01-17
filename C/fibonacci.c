#include <stdio.h>
#include <stdlib.h>

/*
 *   Fibonacci, iterative style
 */
void fibber(int n, int first, int second) {
int c, next;

   c = next = 0;
   while (c < n) {
      if (c <= 1) {
         next = c;
      } else {
         next = first + second;
         first = second;
         second = next;
      }
      printf("%d\n", next);
      c += 1;
   }

   return;
}


/*
 *   Fibonacci, recursive
 */
int fibber2(int n, int first, int second, int c) {

   if (c < n) {
      if (c <= 1)
         second = c;
      c += 1;
      printf("%d\n", second);
      first = fibber2(n, second, first + second, c);
   }

   return(first);
}

int main() {
int c, n, x;

   //  Fibonacci, iterative
   printf("Fibonacci, iterative\n");
   fibber(30, 0, 1);
   printf("#########################\n");

   //  Fibonacci, recursion
   printf("Fibonacci, recursion\n");
   fibber2(30, 0, 0, 0);
}
