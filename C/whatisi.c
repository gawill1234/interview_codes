#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
   The point of this is to answer the question:
      What if you do "this" with a variable?
   Answer: it is undefined.  Varies with implementation
*/

/*****************************************************************/
/*   I compiled and ran this function (whatisi) on four different
     compilers on 3 differenct machines.  I used:
            cc           on  OSF1(DEC)
            /usr/ucb/cc  on  Solaris(Sun)
            SUNWspro cc  on  Solaris(Sun)
            cl(c++)      on  Windows 95(Dell,pentium,Microsoft)

     I got four different results.
     How a variable is incremented in the situations below is
     undefined and so is very implementation dependent.
     The most sensible result(to me anyway) came from the DEC
     compiler.

     Regardless, compiling this will give you a pile of warnings
     about unsequenced modifications.
*/
void whatisi()
{
int i;

   printf("===============  Various values for i  ====================\n");

   i = 0;
   i = (i++) + (i++);

   printf("i is initialized to 0\n");
   printf("i = (i++) + (i++),  i = %d\n", i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   i = (++i) + (++i);

   printf("i is initialized to 0\n");
   printf("i = (++i) + (++i),  i = %d\n", i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   i = (++i) + (i++);

   printf("i is initialized to 0\n");
   printf("i = (++i) + (i++),  i = %d\n", i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   i += (++i) + (i++);

   printf("i is initialized to 0\n");
   printf("i += (++i) + (i++),  i = %d\n", i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   i += (i++) + (++i);

   printf("i is initialized to 0\n");
   printf("i += (i++) + (++i),  i = %d\n", i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   i = (i++) + (++i);

   printf("i is initialized to 0\n");
   printf("i = (i++) + (++i),  i = %d\n", i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   printf("i is initialized to 0\n");
   printf("i: %d   i++: %d    i++: %d\n", i, i++, i++);
   printf("After effects:  %d\n\n", i);

   i = 0;
   printf("i is initialized to 0\n");
   printf("i: %d   ++i: %d    ++i: %d\n", i, ++i, ++i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   printf("i is initialized to 0\n");
   printf("i: %d   i++: %d    ++i: %d\n", i, i++, ++i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   printf("i is initialized to 0\n");
   printf("i: %d   ++i: %d    i++: %d\n", i, ++i, i++);
   printf("After effects:  %d\n\n", i);

   i = 0;
   printf("i is initialized to 0\n");
   printf("i: %d   i++: %d    ++i: %d\n", i, i++, ++i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   printf("i is initialized to 0\n");
   printf("i += ++i: %d   i++: %d    ++i: %d   i += i++: %d\n",
           i += ++i, i++, ++i, i += i++);
   printf("After effects:  %d\n\n", i);

   i = 1;
   printf("i is initialized to 1\n");
   printf("i += ++i: %d   i++: %d    ++i: %d   i += i++: %d\n",
           i += ++i, i++, ++i, i += i++);
   printf("After effects:  %d\n\n", i);

   i = 0;
   printf("i is initialized to 0\n");
   printf("i += i: %d   i++: %d    ++i: %d   i += i: %d\n",
           i += i, i++, ++i, i += i);
   printf("After effects:  %d\n\n", i);

   i = 1;
   printf("i is initialized to 1\n");
   printf("i += i: %d   i++: %d    ++i: %d   i += i: %d\n",
           i += i, i++, ++i, i += i);
   printf("After effects:  %d\n\n", i);

   i = 0;
   printf("i is initialized to 0\n");
   printf("i += i: %d   i += i: %d   i += i: %d\n",
           i += i, i += i, i += i);
   printf("After effects:  %d\n\n", i);

   i = 1;
   printf("i is initialized to 1\n");
   printf("i += i: %d   i += i: %d   i += i: %d\n",
           i += i, i += i, i += i);
   printf("After effects:  %d\n\n", i);

   printf("============  End Various values for i  ====================\n");
}

int main()
{
   whatisi();
}
