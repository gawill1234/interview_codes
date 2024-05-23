import sys
import string
import ctypes

#
#   Bit count using python
#
#   The easier division by 2 method
#   and remainder to count bits.
#   The bitwise and is for
#   negative values (like C unsigned).
#
#
#   In python3, you can declare a variable type
#
def num_bits2(target: int):

   bits = 0
   hold = target

   #
   #   bitwise and  for negative values
   #   To make it like a C unsigned int
   #   Assuming either 32 or 64 bits
   #
   if (target < 0):
      wordsize = ctypes.sizeof(ctypes.c_int) * 8
      if (wordsize == 32):
         target = target & 0xffffffff
      else:
         target = target & 0xffffffffffffffff

   if (target >= 0):
      while (target > 0):
         rmd = target % 2
         #
         #   Override python automatic
         #   variable typing.  Need this
         #   to stay an int
         #
         target = int(target / 2)
         if (rmd != 0):
            bits += 1
      print("numbits2((unsigned)%d mod 2) %d bits" % (hold, bits))
   else:
      print("numbits2((unsigned)%d mod 2) We should not be here" % (hold))

   return


#
#   Yes, you can do a bit shift with python
#
#
#   In python3, you can declare a variable type
#
def num_bits(target: int):

   bits = 0
   hold = target
   i = 0

   #
   #   wordsize assumption setting
   #   would be: wordsize = 32
   #
   wordsize = ctypes.sizeof(ctypes.c_int) * 8
   while (i < wordsize):
      if (target & 1):
         bits += 1
      target = target >> 1
      i += 1
   print("numbits(mask and shift %d) %d bits" % (hold, bits))

   return

if __name__ == "__main__":

   num_bits2(0)
   #
   #   Some older systems allowed
   #   negative zero.  And the
   #   internal representation reflected
   #   that it was a negative zero
   #
   num_bits2(-0)
   num_bits2(1)
   num_bits2(2)
   num_bits2(3)
   num_bits2(127)
   num_bits2(128);
   num_bits2(82)
   num_bits2(83)
   num_bits2(87)
   num_bits2(107)
   num_bits2(-107)
   num_bits2(107695)
   print("\n")

   num_bits(0)
   num_bits(-0)
   num_bits(1)
   num_bits(2)
   num_bits(3)
   num_bits(127)
   num_bits(128);
   num_bits(82)
   num_bits(83)
   num_bits(87)
   num_bits(107)
   num_bits(-107)
   num_bits(107695)
   print("\n")

   sys.exit(0)
