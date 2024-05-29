#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**********************************************************************/

/*  How to find out if a void* is on a word boundary */

void addr_bound(void *myaddr)
{
int wsize;

   if (myaddr == NULL)
      return;
  
   /* wsize will probably be 4(word size on 32 bit machines) */
   /* on newer machines, will probably be 8                  */
   wsize = sizeof(long);

   if (((int)myaddr % wsize) == 0)
      /*   1000 is an arbitrary value that I chose so that I could print
           what is actually stored at the void address, ie, if it is less
           than 1000 for the purposes of this test I assume it is a
           character value.
      */
      if (*(int *)myaddr > 1000)
         printf("Address boundry(void *), %u, %c:  We are on a word boundry\n",
              (unsigned)myaddr, *(char *)myaddr);
      else
         printf("Address boundry(void *), %u, %d:  We are on a word boundry\n",
              (unsigned)myaddr, *(int *)myaddr);
   else
      printf("Address boundry(void *), %u, %c:  NOT on a word boundry\n",
              (unsigned)myaddr, *(char *)myaddr);
}

int main()
{
long *myaddr;
long z = 9;
char *addr2;
char arr[8] = "abcdefgh";

   myaddr = &z;
   addr_bound(myaddr);
   addr2 = &arr[0];
   addr_bound(addr2);
   addr2 = &arr[1];
   addr_bound(addr2);
   addr2 = &arr[2];
   addr_bound(addr2);
   addr2 = &arr[3];
   addr_bound(addr2);
   addr2 = &arr[4];
   addr_bound(addr2);
   addr2 = &arr[5];
   addr_bound(addr2);
   addr2 = &arr[6];
   addr_bound(addr2);
   addr2 = &arr[7];
   addr_bound(addr2);
   printf("\n\n");
}
