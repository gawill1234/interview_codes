#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/***************************************************************************/
/*   How to determine if a machine is big endian or little endian
*/
void endian()
{
unsigned int studabaker = 1;

   if ((int)*(char *)&studabaker)
      printf("LITTLE ENDIAN\n");
   else
      printf("BIG ENDIAN\n");

}

int main()
{
   endian();
}
