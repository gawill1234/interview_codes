#
# Fibonacci Series python language
# with recursion.  Horrible version.
# At least to me.  I like the other
# (fibonacci_recur.py) better.
# But it does use recursion.
# And it is noticably slower.
#
import sys

 
def fibonacci(n):

   if (n <= 1):
      return n

   return fibonacci(n - 1) + fibonacci(n - 2)

if __name__ == "__main__":

   n = 30
   c = 0
   print("First ", n, " terms of Fibonacci series are :")
   while (c < n):
      x = fibonacci(c)
      print(x)
      c += 1
   print("Final value: ", x)
   sys.exit(0)
