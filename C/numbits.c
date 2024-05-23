/*

      num bits(many different ones)
         mask and shift
         value & (value - 1)
         value % 2      (2 different)
         table look up  (2 different, both good 0 to 255, not just 127)

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/**********************************************************************/
/*   My global look up table(yes I know it should have a better
     name than x)
 */
int x[256];

/**********************************************************************/
/*
   A routine to initialize a look up table for a couple of
   the numbits routines
*/
void table_init()
{
int i, j, bits, ltarget;

   /*   Initialize the lookup table.
        In a real usage situation, you would only do this once,
        not every time the routine was called.
   */
   for (i = 0; i < 256; i++) {
      bits = 0;
      ltarget = i;
      while (ltarget > 0) {
         ltarget = (ltarget & (ltarget - 1));
         bits++;
      }
      x[i] = bits;
   }
}
/**********************************************************************/

/************************************************************************/
/*  num_bitsX() represent various solutions to the numbits problems with
    difficulties of using an int represented
*/
/*  And of value and value - 1
    Must have target be unsigned or negative numbers
    always appear to have zero bits set.
*/
void num_bits4(unsigned target)
{
int bits, i, rmd, hold;

   bits = 0;
   hold = target;

   while (target > 0) {
      target = (target & (target - 1));
      bits++;
   }
   printf("numbits4(&, %d) %d bits\n", hold, bits);
}

#define BITCOUNT(x)    (((BX_(x)+(BX_(x)>>4)) & 0x0F0F0F0F) % 255)
#define BX_(x)         ((x) - (((x)>>1)&0x77777777) \
                             - (((x)>>2)&0x33333333) \
                             - (((x)>>3)&0x11111111))

void num_bits7(unsigned target)
{
int count;

   count = BITCOUNT(target);
   printf("numbits7(macro, %d) %d bits\n", target, count);
}

/*   Get the number of bits from a lookup table */
/*   Note the unsigned char * in this example   */
void num_bits5(unsigned target)
{
int i, bits, ltarget, len;
unsigned char *z;

   ltarget = target;
   z = (unsigned char *)&target;
   len = sizeof(target);

   bits = 0;
   for (i = 0; i < len; i++) {
      bits = bits + x[(int)z[i]];
   }
   
   printf("numbits5(table lookup by uchar, %d) %d bits\n", ltarget, bits);
}

/*   Get the number of bits from a lookup table                     */
/*   Another way ...                                                */
/*   Note the lack of unsigned char * in this example               */
/*   Because of the char * declaration change, we have to and       */
/*   the value at the location with eight bits (0xff or 0377)       */
/*   to get the value to work as an array subscript.                */
/*   To understand the difference and why one of these MAY be       */
/*   required, you must know that some machines support the idea    */
/*   of a SIGNED character.  Only up to 7 bits for a character      */
/*   is standard across platforms(for the ascii character set)      */
/*   To you doubters, look it up for yourself.                      */
/*   Without one of these methods, we could probably only get up to */
/*   127 as a valid array reference(from a char).  With the method  */
/*   we can get up to the expected 255.(0 - 255, or 256 values)     */
void num_bits6(unsigned target)
{
int i, bits, ltarget, len;
char *z;

   ltarget = target;
   z = (char *)&target;
   len = sizeof(target);

   bits = 0;
   for (i = 0; i < len; i++) {
      bits = bits + x[(int)(z[i] & 0xff)];
   }
   
   printf("numbits6(table lookup by and, %d) %d bits\n", ltarget, bits);
}

/*   This one only works with positive numbers.
     It doesn't take into account 2s complement on
     negative numbers dude.  Note that the argument is of type
     int.
*/
void num_bits3(int target)
{
int bits, i, rmd, hold;

   bits = 0;
   hold = target;

   if (target >= 0) {
      while (target != 0) {
         rmd = target % 2;
         target = target / 2;
         if (rmd != 0)
            bits++;
      }
      printf("numbits3((int)%d mod 2) %d bits\n", hold, bits);
   } else {
      printf("numbits3((int)%d mod 2) This does not work with negatives\n", hold);
   }
}

/*   This one works with negative numbers because the passed value
     is cast as an unsigned(ie, positive).  Other than that, it is
     identical to num_bits3(int target) above.
*/
void num_bits2(unsigned target)
{
int bits, i, rmd, hold;

   bits = 0;
   hold = target;

   if (target >= 0) {
      while (target != 0) {
         rmd = target % 2;
         target = target / 2;
         if (rmd != 0)
            bits++;
      }
      printf("numbits2((unsigned)%d mod 2) %d bits\n", hold, bits);
   } else {
      printf("numbits2((unsigned)%d mod 2) We should not be here\n", hold);
   }
}


void num_bits(int target)
{
int bits, i, hold;

   bits = 0;
   hold = target;

   for (i = 0; i < sizeof(int) * 8; i++) {
      if (target & 01)
         bits++;
      target = target >> 1;
   }
   printf("numbits(mask and shift %d) %d bits\n", hold, bits);
}

/***************************************************************************/
/*  The string reverse problem
    There are 3 different(well almost different) solutions presented
    here.  There is a FOR loop, a WHILE loop, and a DO-WHILE loop.
    They all work.  Take your pick.
*/
/***************************************************************************/
int main()
{

   num_bits(0);
   num_bits(-0);
   num_bits(127);
   num_bits(128);
   num_bits(82);
   num_bits(83);
   num_bits(87);
   num_bits(107);
   num_bits(-107);
   num_bits(107695);
   printf("\n\n");

   num_bits2(0);
   num_bits2(-0);
   num_bits2(127);
   num_bits2(128);
   num_bits2(82);
   num_bits2(83);
   num_bits2(87);
   num_bits2(107);
   num_bits2(-107);
   num_bits2(107695);
   printf("\n\n");

   num_bits3(0);
   num_bits3(-0);
   num_bits3(127);
   num_bits3(128);
   num_bits3(82);
   num_bits3(83);
   num_bits3(87);
   num_bits3(107);
   num_bits3(-107);
   num_bits3(107695);
   printf("\n\n");

   num_bits4(0);
   num_bits4(-0);
   num_bits4(127);
   num_bits4(128);
   num_bits4(82);
   num_bits4(83);
   num_bits4(87);
   num_bits4(107);
   num_bits4(-107);
   num_bits4(107695);
   printf("\n\n");

   table_init();

   num_bits5(0);
   num_bits5(-0);
   num_bits5(127);
   num_bits5(128);
   num_bits5(82);
   num_bits5(83);
   num_bits5(87);
   num_bits5(107);
   num_bits5(-107);
   num_bits5(107695);
   printf("\n\n");

   num_bits6(0);
   num_bits6(-0);
   num_bits6(127);
   num_bits6(128);
   num_bits6(82);
   num_bits6(83);
   num_bits6(87);
   num_bits6(107);
   num_bits6(-107);
   num_bits6(107695);
   printf("\n\n");

   num_bits7(0);
   num_bits7(-0);
   num_bits7(127);
   num_bits7(128);
   num_bits7(82);
   num_bits7(83);
   num_bits7(87);
   num_bits7(107);
   num_bits7(-107);
   num_bits7(107695);

}
