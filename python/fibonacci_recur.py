#
# Fibonacci Series python language
# with recursion.  First pass.
# it can be improved.
#
import sys
 
def fibonacci(n, first, second, c):

   if (c < n):
      if ( c <= 1 ):
         second = c
      c += 1
      print(second)
      first = fibonacci(n, second, first + second, c)

   return first

if __name__ == "__main__":

   n = 30
   print("First ", n, " terms of Fibonacci series are :")
   print("Final value:", fibonacci(n, 0, 0, 0))
   sys.exit(0)
