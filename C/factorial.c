#include <stdio.h>

void factorial(int n)
{
int i;
unsigned long long factorial = 1;

   // show error if the user enters a negative integer
   if (n < 0) {
      printf("Error! Factorial of a negative number doesn't exist.");
   } else {
      for (i = 1; i <= n; ++i) {
         factorial *= i;              // factorial = factorial*i;
      }
      printf("Factorial of %d = %llu\n", n, factorial);
   }
   fflush(stdout);

   return;
}

void factorial2(int n)
{
unsigned long long total = 1;
int mynumber;

   mynumber = n;

   while (mynumber > 1) {
      total = total * mynumber;
      mynumber -= 1;
   }

   printf("Factorial2 of %d = %llu\n", n, total);
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


   factorial2(5);
   factorial2(11);
   factorial2(17);
   factorial2(8);
   factorial2(7);
}
