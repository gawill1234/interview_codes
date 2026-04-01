#include <stdio.h>
#include <stdlib.h>

/*
 *   Set the nth bit to 1
 */
unsigned int bit_set(unsigned int twiddlenum, unsigned int n) {
    return twiddlenum | ((unsigned int)1 << n);
}

/*
 *   Set the nth bit to 0
 */
unsigned int bit_clear(unsigned int twiddlenum, unsigned int n) {
    return twiddlenum & ~((unsigned int)1 << n);
}

/*
 *   Toggle the nth bit from 0 to 1 or 1 to 0
 */
unsigned int bit_toggle(unsigned int twiddlenum, unsigned int n) {
    return twiddlenum ^ ((unsigned int)1 << n);
}

/*
 *   check if the nth bit is 1
 */
unsigned int bit_check(unsigned int twiddlenum, unsigned int n) {
    return (twiddlenum >> n) & (unsigned int)1;
}

/*
 *   Set the nth bit to 0 or 1
 */
unsigned int bit_set_to(unsigned int twiddlenum, unsigned int n, unsigned int setto) {
    return (twiddlenum & ~((unsigned int)1 << n)) | ((unsigned int)setto << n);
}

void printbinary(unsigned int num) {
int zing, i, wordsz;

   wordsz = sizeof(int) * 8 - 1;
   for (i = wordsz; i >= 0; i--) {
      zing = ((num >> i) & 1);
      if (zing) {
         printf("1");
      } else {
         printf("0");
      }
      if ((i % 8) == 0) {
         printf(" ");
      }
   }
   printf("\n");

   return;
}

int main() {
unsigned int gleeb;

   gleeb = 0;

   printf("Remember, indexing starts at 0 (zero)\n");
   printf("\n");

   /*
    *   Set bits 5, 7 and 30 to 1
    */
   printf("Set bits 5, 7, and 30 to 1\n");
   gleeb = bit_set_to(gleeb, 5, 1);
   gleeb = bit_set_to(gleeb, 7, 1);
   gleeb = bit_set_to(gleeb, 30, 1);
   printbinary(gleeb);
   printf("\n");

   if (bit_check(gleeb, 5)) {
      printf("Fifth bit is 1\n");
   } else {
      printf("Fifth bit is 0\n");
   }

   printbinary(gleeb);
   printf("\n");

   printf("Set bit 5 to 0 by toggle\n");
   gleeb = bit_toggle(gleeb, 5);

   if (bit_check(gleeb, 5)) {
      printf("Fifth bit is 1\n");
   } else {
      printf("Fifth bit is 0\n");
   }

   printbinary(gleeb);
   printf("\n");

   printf("Set bit 5 to 1 by set\n");
   gleeb = bit_set(gleeb, 5);

   if (bit_check(gleeb, 5)) {
      printf("Fifth bit is 1\n");
   } else {
      printf("Fifth bit is 0\n");
   }

   printbinary(gleeb);
   printf("\n");
}
