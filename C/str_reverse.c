#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/***************************************************************************/
/*  The string reverse problem
    There are 3 different(well almost different) solutions presented
    here.  There is a FOR loop, a WHILE loop, and a DO-WHILE loop.
    They all work.  Take your pick.
*/
void str_reverse (char *goofy)
{
char c;
int i, j, len, transit;

   if (goofy == NULL)
      return;

   len = strlen(goofy);
   transit = (len + 1) / 2;

   /*  Technically, we could check for 1 instead of zero, but lets
       show that the loop works in all situations
   */
   if (len > 0) {
      printf("string reverse(for, start string, %d)   :  %s\n", len, goofy);

      for (i = 0; i < transit; i++) {
         c = goofy[len - (i + 1)];
         goofy[len - (i + 1)] = goofy[i];
         goofy[i] = c;
      }

      printf("string reverse(for, final string, %d)   :  %s\n", len, goofy);
   } else {
      printf("string_reverse, for,  %d)   :  NOTHING TO REVERSE\n", len);
   }
}

void str_reverse2(char *goofy)
{
char c;
int len, done;

   if (goofy == NULL)
      return;

   len = strlen(goofy);

   /*  Technically, we could check for 1 instead of zero, but lets
       show that the loop works in all situations
   */
   if (len > 0) {

      printf("string reverse2(while, start string, %d)   :  %s\n", len, goofy);

      done = 0;

      while (len > done) {
         len--;
         c = goofy[len];
         goofy[len] = goofy[done];
         goofy[done] = c;
         done++;
      }

      printf("string reverse2(while, final string, %d)   :  %s\n",
              len + done, goofy);
   } else {
      printf("string_reverse2, while,  %d)   :  NOTHING TO REVERSE\n", len);
   }
}

void str_reverse3(char *goofy)
{
char c;
int len, done;

   if (goofy == NULL)
      return;

   len = strlen(goofy);

   /*  Technically, we could check for 1 instead of zero, but lets
       show that the loop works in all situations
   */
   if (len > 0) {

      printf("string reverse3(do, start string, %d)   :  %s\n", len, goofy);

      done = 0;

      do {
         len--;
         c = goofy[len];
         goofy[len] = goofy[done];
         goofy[done] = c;
         done++;
      } while (len > done);

      printf("string reverse3(do, final string, %d)   :  %s\n",
              len + done, goofy);
   } else {
      printf("string_reverse3, do,  %d)   :  NOTHING TO REVERSE\n", len);
   }
}
/***************************************************/
int main()
{
char blarg[512];

   strcpy(blarg, "hello there odd");
   str_reverse(blarg);
   strcpy(blarg, "hello there even");
   str_reverse(blarg);
   strcpy(blarg, "I");
   str_reverse(blarg);
   strcpy(blarg, "");
   str_reverse(blarg);
   printf("\n\n");

   strcpy(blarg, "hello there odd");
   str_reverse2(blarg);
   strcpy(blarg, "hello there even");
   str_reverse2(blarg);
   strcpy(blarg, "I");
   str_reverse2(blarg);
   strcpy(blarg, "");
   str_reverse2(blarg);
   printf("\n\n");

   strcpy(blarg, "hello there odd");
   str_reverse3(blarg);
   strcpy(blarg, "hello there even");
   str_reverse3(blarg);
   strcpy(blarg, "I");
   str_reverse3(blarg);
   strcpy(blarg, "");
   str_reverse3(blarg);
   printf("\n\n");

}
