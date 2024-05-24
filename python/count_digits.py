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

   mystring = "tHis A tesT of 123#something stupid 4 no reason!"
   digitcount = countdigits(mystring)
   print("Digit count  : Expected 4, got ", digitcount)
   digitcount = countdigits2(mystring)
   print("Digit count 2: Expected 4, got ", digitcount)

   mystring = "1 2 buckle my shoe, 3 4 shut the door, 5 6 pick up sticks"
   digitcount = countdigits(mystring)
   print("Digit count  : Expected 6, got ", digitcount)
   digitcount = countdigits2(mystring)
   print("Digit count 2: Expected 6, got ", digitcount)

   sys.exit(0)
