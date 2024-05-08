#
# Fibonacci Series python language
# with recursion.  First pass.
# it can be improved.
#
import sys
 
def fibonacci(n, first, second, c):

   if (c < n):
      if ( c <= 1 ):
         next = c
         second = next
      else:
         next = first + second
         first = second
         second = next
      print(next)
      c += 1
      fibonacci(n, first, second, c)

   return
 
if __name__ == "__main__":

   n = 30
   print("First ", n, " terms of Fibonacci series are :")
   fibonacci(n, 0, 0, 0)
   sys.exit(0)
