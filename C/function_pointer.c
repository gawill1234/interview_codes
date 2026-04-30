#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef void (*func_p)(int);
typedef int (*func_p2)(int);
typedef void (*func_p3)(char *);
typedef void (*func_p4)();

/**********************************************************************/
/*
   These routines are used to illustrate a use of funtion pointers.
   function oddeven() returns a pointer to a function that returns void.
   The returned function prints out whether the number passed to oddeven
   was in fact odd or even.
*/
void stuffy()
{

   printf("In stuffy\n");
   fflush(stdout);

}
void endian()
{
unsigned int studabaker = 1;

   if ((int)*(char *)&studabaker)
      printf("LITTLE ENDIAN\n");
   else
      printf("BIG ENDIAN\n");

}
void oddout(int mynumber)
{
   printf("%d is odd\n", mynumber);
}
void evenout(int mynumber)
{
   printf("%d is even\n", mynumber);
}

void *oddeven(int mynumber)
{
void (*fp)(int);

   if (mynumber & 01)
      fp = oddout;
   else
      fp = evenout;

   return(fp);
}

void generalfp(char *mystring)
{
   printf("generalfp:   %s\n", mystring);
   return;
}

int intgenfp(int myvalue)
{
   printf("intgenfp:   %d\n", myvalue);
   return(myvalue + 2);
}

/*
 *   One way of doing declarations for function pointers.
 *   See function pointer typedef at the top.
 */
int main() {
char blarg[32];
func_p4 func_array[2] = {stuffy, endian};
func_p qqqq;
func_p2 zzzz;
func_p3 yyyy;

   printf("Calls using function pointers from a function array\n");
   func_array[0]();
   func_array[1]();

   qqqq = oddeven(1);
   qqqq(1);
   qqqq = oddeven(2);
   qqqq(2);

   yyyy = generalfp;
   strcpy(blarg, "this is my first string");
   yyyy(blarg);
   strcpy(blarg, "this is my second string");
   yyyy(blarg);
   zzzz = intgenfp;
   printf("returned:   %d\n", zzzz(5));
   printf("returned:   %d\n", zzzz(1));
   printf("End function pointer illustration\n\n");

   return(0);

}
