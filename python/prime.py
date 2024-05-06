import sys

def isprime(num):

   if ( num <= 1):
      return(False)

   if ( num <= 3):
      return(True)

   if (( num % 2 ) == 0):
      return(False)

   mood = 3
   while ((mood * mood) <= num):
      if ((num % mood) == 0):
         return(False)
      mood += 2

   return(True)


if __name__ == "__main__":

   x = 100

   bbl = False
   c = 0
   while (c <= x):
      bbl = isprime(c)
      if (bbl):
         print(c, " is PRIME")
      else:
         print(c, " is NOT prime")
      c += 1

   sys.exit(0)
