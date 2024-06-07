#include <stdio.h>

/*
 *   Some of these start at 1
 *   and go up.  Some start at
 *   the top and go down.  There
 *   is a difference with the 
 *   larger numbers.  But, that is
 *   the way of floats.  :)
 */
/*
 *   Also, put int the factorial of
 *   52 (deck of cards).  How many
 *   different configurations can
 *   a shuffled deck of cards take.
 */
/*
 *   Start at the bottom and
 *   work the way up with a
 *   for loop.
 */
void factorial(int n)
{
int i;
double total = 1.0;

   // show error if the user enters a negative integer
   if (n < 0) {
      printf("Error! Factorial of a negative number doesn't exist.");
   } else {
      for (i = 1; i <= n; ++i) {
         total *= (double)i;              // factorial = factorial*i;
      }
      printf("Factorial of %d = %f\n", n, total);
   }
   fflush(stdout);

   return;
}

/*
 *   Start at the bottom and
 *   work the way up with a
 *   while loop.
 */
void factorial2(int n)
{
double mynumber;
double total = 1.0;

   mynumber = 1.0;

   while (mynumber <= n) {
      total = total * mynumber;
      mynumber += 1.0;
   }

   printf("Factorial2 of %d = %f\n", n, total);
   fflush(stdout);

   return;
}

/*
 *   Computes a factorial, but
 *   by going backwards.  This
 *   actually is closer to the
 *   calculator result.
 *   while loop
 */
void factorial3(int n)
{
double mynumber;
double total = 1.0;

   mynumber = (double)n;

   while (mynumber >= 1.0) {
      total = total * mynumber;
      mynumber -= 1.0;
   }

   printf("Factorial3 of %d = %f\n", n, total);
   fflush(stdout);

   return;
}

/*
 *   Computes a factorial, but
 *   by going backwards.  This
 *   actually is closer to the
 *   calculator result.
 *   for loop
 */
void factorial4(int n)
{
int i;
double total = 1.0;

   // show error if the user enters a negative integer
   if (n < 0) {
      printf("Error! Factorial of a negative number doesn't exist.");
   } else {
      for (i = n; i >= 1.0; i--) {
         total *= (double)i;              // factorial = factorial*i;
      }
      printf("Factorial4 of %d = %f\n", n, total);
   }
   fflush(stdout);

   return;
}

int main()
{
   factorial(5);
   factorial(11);
   factorial(17);
   factorial(8);
   factorial(7);
   factorial(52);
   printf("\n");


   factorial2(5);
   factorial2(11);
   factorial2(17);
   factorial2(8);
   factorial2(7);
   factorial2(52);
   printf("\n");

   factorial3(5);
   factorial3(11);
   factorial3(17);
   factorial3(8);
   factorial3(7);
   factorial3(52);
   printf("\n");

   factorial4(5);
   factorial4(11);
   factorial4(17);
   factorial4(8);
   factorial4(7);
   factorial4(52);
}
