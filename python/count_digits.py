import sys
import string

#
#   Count the digits(numbers) in a string
#   Bone simple in python3
#

DIGITS = string.digits

def countdigits(mystring):

   digitcount = 0

   for item in mystring:
      if (item in DIGITS):
         digitcount += 1

   return digitcount

#
#   To me, this is a bit convoluted.  But,
#   if you want it to reek of python3, 
#   here you go.
#
def countdigits2(mystring):

   return sum(map(mystring.count, DIGITS))


if __name__ == "__main__":

   digitcount = countdigits("tHis A tesT of 123#something stupid 4 no reason!")
   print("Digit count: Expected 4, got ", digitcount)
   digitcount = countdigits2("tHis A tesT of 123#something stupid 4 no reason!")
   print("Digit count 2: Expected 4, got ", digitcount)
   digitcount = countdigits("1 2 buckle my shoe, 3 4 shut the door, 5 6 pick up sticks")
   print("Digit count: Expected 6, got ", digitcount)
   digitcount = countdigits2("1 2 buckle my shoe, 3 4 shut the door, 5 6 pick up sticks")
   print("Digit count 2: Expected 6, got ", digitcount)

   sys.exit(0)
