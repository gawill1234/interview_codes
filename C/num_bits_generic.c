#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdint.h>

/*
 *   Routine to count the bits in any variable type.
 *   Needs the length (int bytes) of the type being
 *   looked at, but it works.
 *   Any contiguous chunk of memory so array, string,
 *   struct, whatever.
 */
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
void *tmp;

   bits = i = 0;
   tmp = myvar;

   if (what <= 0) {
      what = sizeof(int);
   }

   do {
      ttt = ((uint8_t)*(char *)(tmp));
      bits += ones_in_octet(ttt);
      i += 1;
      tmp++;
   } while (i < what);

   return(bits);
}

int main() {
int i = 3;
long j = 11111111;
long long k = 11111111111111111;
float l = 3.1415926;
double m = 6.02 * pow(10, 23);
char n = 'q';
char o[] = {'a', 'b', 'c', 'd', '\0'};

   printf("int:        %d bits in %d\n", num_bits_any(&i, sizeof(int)), i);
   printf("char:       %d bits in %c\n", num_bits_any(&n, sizeof(char)), n);
   printf("long:       %d bits in %ld\n", num_bits_any(&j, sizeof(long)), j);
   printf("long long:  %d bits in %lld\n", num_bits_any(&k, sizeof(long long)), k);
   printf("float:      %d bits in %f\n", num_bits_any(&l, sizeof(float)), l);
   printf("double:     %d bits in %f\n", num_bits_any(&m, sizeof(double)), m);
   printf("string:     %d bits in %s\n", num_bits_any(&o, sizeof(char) * 4), o);

   exit(0);

}

 
