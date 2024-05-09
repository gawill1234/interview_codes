#
# Fibonacci Series python language
# with recursion.  First pass.
# Done without a counter value as in
# fibonacci_recur.py.
# it can be improved.
#
import sys
 
def fibonacci(n, first, second):

   if (second == 0):
      print(second)

   if ( n <= 1 ):
      return

   if (second <= 1):
      second = 1

   print(second)
   fibonacci(n - 1, second, first + second)

   return

if __name__ == "__main__":

   n = 30
   print("First ", n, " terms of Fibonacci series are :")
   fibonacci(n, 0, 0)
   sys.exit(0)
