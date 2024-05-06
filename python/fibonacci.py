# Fibonacci Series python language
import sys
 
if __name__ == "__main__":
   first = 0
   second = 1
   next = 0
 
   n = 30
 
   print("First ", n, " terms of Fibonacci series are :")
 
   c = 0
   while (c < n):
      if ( c <= 1 ):
         next = c
      else:
         next = first + second
         first = second
         second = next
      print(next)
      c += 1
 
   sys.exit(0)
