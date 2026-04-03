#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

/*
 *   Another way to dump bits.  Maybe not the greatest.
 *   But it is interesting in its approach so figured
 *   I'd put it up.  
 *
 *   Though it does, mostly, speed up getting the actual
 *   bits.  Not sure about overall performance due to the
 *   use of string routines.
 */

/*
 *   Get the bits for a nibble based on a lookup.
 */
char *bit_in_octet(uint8_t octet)
{
  char *bitstr;
  static const char* NIBBLE_ONES_BITS[16] =
  {
    "0000\0", "0001\0", "0010\0", "0011\0", "0100\0", "0101\0", "0110\0", "0111\0",
    "1000\0", "1001\0", "1010\0", "1011\0", "1100\0", "1101\0", "1110\0", "1111\0"
  };

  bitstr = (char *)calloc(9,1);

  strcpy(bitstr, NIBBLE_ONES_BITS[octet >> 4]);
  strcat(bitstr, NIBBLE_ONES_BITS[octet & 0x0F]);

  return(bitstr);
}

/*
 *   Process the value and put the bits in a string
 *   Can process any value type.  Just make sure
 *   you specify the size of what you are processing.
 */
char *show_bits_generic(void *myvar, int what) {
int bits, i;
uint8_t ttt;
char *tmp;
char *gleeb, *bitstr;

   bits = i = 0;
   tmp =(char *)myvar;

   gleeb = NULL;

   if (what <= 0) {
      what = sizeof(int);
   }

   do {
      ttt = ((uint8_t)*(tmp));
      bitstr = bit_in_octet(ttt);
      if (gleeb == NULL) {
         gleeb = (char *)calloc((what * 8) + 1 + what, 1);
         strcpy(gleeb, bitstr);
      } else {
         strcat(gleeb, " ");
         strcat(gleeb, bitstr);
      }
      free(bitstr);
      i += 1;
      tmp++;
   } while (i < what);

   return(gleeb);
}

/********************************************************/
int ones_in_octet(uint8_t octet)
{
  static const int NIBBLE_ONES_COUNT[16] =
  {
    0, 1, 1, 2, 1, 2, 2, 3,
    1, 2, 2, 3, 2, 3, 3, 4
  };

  return NIBBLE_ONES_COUNT[octet & 0x0F] + NIBBLE_ONES_COUNT[octet >> 4];
}

/********************************************************/
/*
 *    Generic "num_bits".  Pass in the item and its size
 *    in bytes/octets.
 */
int num_bits_any(void *myvar, int what) {
int bits, i;
uint8_t ttt;
char *tmp;

   bits = i = 0;
   tmp =(char *)myvar;

   if (what <= 0) {
      what = sizeof(int);
   }

   do {
      ttt = ((uint8_t)*(tmp));
      bits += ones_in_octet(ttt);
      i += 1;
      tmp++;
   } while (i < what);

   return(bits);
}

/********************************************************/

int main() {
long long abc = 111111111111111111;
long cde = 111111111;
int z = 3;
char q = 'q';
char a[] = {'a', 'b', 'c', 'd', '\0'};
char A[] = {'A', 'B', 'C', 'D', '\0'};
float hi = 3.1415926;
double dhi = 6.02 * pow(10, 23);
char *bitres;

   printf("long long:  %d bits in %lld\n", num_bits_any(&abc, sizeof(long long)), abc);
   bitres = show_bits_generic(&abc, sizeof(long long));
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   printf("char:       %d bits in %c\n", num_bits_any(&q, sizeof(char)), q);
   bitres = show_bits_generic(&q, sizeof(char));
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   printf("long:       %d bits in %ld\n", num_bits_any(&cde, sizeof(long)), cde);
   bitres = show_bits_generic(&cde, sizeof(long));
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   cde = 87654321;
   printf("long:       %d bits in %ld\n", num_bits_any(&cde, sizeof(long)), cde);
   bitres = show_bits_generic(&cde, sizeof(long));
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   printf("float:      %d bits in %f\n", num_bits_any(&hi, sizeof(float)), hi);
   bitres = show_bits_generic(&hi, sizeof(float));
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   printf("double:     %d bits in %f\n", num_bits_any(&dhi, sizeof(double)), dhi);
   bitres = show_bits_generic(&dhi, sizeof(double));
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   printf("int:        %d bits in %d\n", num_bits_any(&z, sizeof(int)), z);
   bitres = show_bits_generic(&z, sizeof(int));
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   printf("array:      %d bits in %s\n", num_bits_any(&a, sizeof(char) * 4), a);
   bitres = show_bits_generic(&a, sizeof(char) * 4);
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   printf("array:      %d bits in %s\n", num_bits_any(&A, sizeof(char) * 4), A);
   bitres = show_bits_generic(&A, sizeof(char) * 4);
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   z = 16;
   printf("int:        %d bits in %d\n", num_bits_any(&z, 0), z);
   bitres = show_bits_generic(&z, 0);
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   z = 15;
   printf("int:        %d bits in %d\n", num_bits_any(&z, 0), z);
   bitres = show_bits_generic(&z, 0);
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   z = 18;
   printf("int:        %d bits in %d\n", num_bits_any(&z, 0), z);
   bitres = show_bits_generic(&z, 0);
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   z = 256;
   printf("int:        %d bits in %d\n", num_bits_any(&z, 0), z);
   bitres = show_bits_generic(&z, 0);
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   z = 66;
   printf("int:        %d bits in %d\n", num_bits_any(&z, 0), z);
   bitres = show_bits_generic(&z, 0);
   printf("            BITS:  %s\n", bitres);
   free(bitres);

   z = 97;
   printf("int:        %d bits in %d\n", num_bits_any(&z, 0), z);
   bitres = show_bits_generic(&z, 0);
   printf("            BITS:  %s\n", bitres);
   free(bitres);
}
