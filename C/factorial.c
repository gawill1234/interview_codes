#include <stdio.h>
void factorial(int n)
{
    int i;
    unsigned long long factorial = 1;

    // show error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");

    else
    {
        for(i=1; i<=n; ++i)
        {
            factorial *= i;              // factorial = factorial*i;
        }
        printf("Factorial of %d = %llu\n", n, factorial);
    }

    return;
}

void factorial2(int n)
{
   double total = 1.0;
   double mynumber;

   printf("Factorial calculation of %d.\n", n);
   fflush(stdout);

   mynumber = (double)n;

   while (mynumber > 1) {
      total = total * mynumber;
      mynumber -= 1.0;
   }

   printf("factorial is %.2f\n", total);
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
