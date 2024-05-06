#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**********************************************************************/
/*   Odd or even number, by mod 2  */
void odd_or_even(int target)
{

   if (target % 2)
      printf("odd even(mod 2) %d is an ODD number\n", target);
   else
      printf("odd even(mod 2) %d is an EVEN number\n", target);

}

/*   Odd or even number, by anding with 01  */
void odd_or_even2(int target)
{

   if (target & 01)
      printf("odd even(and) %d is an ODD number\n", target);
   else
      printf("odd even(and) %d is an EVEN number\n", target);

}
/**********************************************************************/

int main()
{
   odd_or_even(1);
   odd_or_even(2);
   odd_or_even(-1);
   odd_or_even(-2);
   odd_or_even(107);
   odd_or_even(-107);
   odd_or_even(108);
   odd_or_even(-108);
   printf("\n\n");

   odd_or_even2(1);
   odd_or_even2(2);
   odd_or_even2(-1);
   odd_or_even2(-2);
   odd_or_even2(107);
   odd_or_even2(-107);
   odd_or_even2(108);
   odd_or_even2(-108);
   printf("\n\n");
}
