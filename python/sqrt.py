import sys

#
#   Get the square root of a value using
#   subtract the odds followed by directed
#   guessing(like a binary search).
#
def guess_the_rest(count, origval):

   tries = 0
   starter =  0.5
   newcount = (count * 1.0) + starter

   while (tries < 150):
      tries += 1
      if ((newcount * newcount) > origval):
         starter = starter / 2.0
         newcount = newcount  - starter
      elif ((newcount * newcount) < origval):
         starter + starter + (starter / 2.0)
         newcount = newcount + starter
      else:
         return newcount

   if (abs((newcount * newcount) - origval) < 0.0000000000001):
      return newcount

   return newcount

def square_root(myval):
   count = 0
   nextodd = 1
   origval = myval

   while (myval > 0):
      myval = myval - nextodd
      nextodd += 2
      if (myval < 0):
         count = guess_the_rest(count, origval)
      else:
         count += 1

   return count

if __name__ == "__main__":

   myval = square_root(9)
   print("square root of 9:", f"{myval:.6f}")
   print("    sqrt times itself", f"{(myval * myval):.6f}")

   myval = square_root(5)
   print("square root of 5:", f"{myval:.6f}")
   print("    sqrt times itself", f"{(myval * myval):.6f}")

   myval = square_root(144)
   print("square root of 144:", f"{myval:.6f}")
   print("    sqrt times itself", f"{(myval * myval):.6f}")

   myval = square_root(18)
   print("square root of 18:", f"{myval:.6f}")
   print("    sqrt times itself", f"{(myval * myval):.6f}")

   myval = square_root(1001)
   print("square root of 1001:", f"{myval:.6f}")
   print("    sqrt times itself", f"{(myval * myval):.6f}")

   myval = square_root(99)
   print("square root of 99:", f"{myval:.6f}")
   print("    sqrt times itself", f"{(myval * myval):.6f}")

   myval = square_root(1010101)
   print("square root of 1010101:", f"{myval:.6f}")
   print("    sqrt times itself", f"{(myval * myval):.6f}")

   exit
