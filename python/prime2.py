#
#   get prime number using a function
#   using "yield".
#
def getprimes(mymax):
   i = 2
   while (i < mymax):
      #
      #   It is difficult for me to get used to the
      #   idea of an "else" on a for loop.  But, here
      #   it is.
      #   The "else" code ONLY executes if the for loop
      #   never hits a break
      #
      for j in range(2, i):
         if ((i % j) == 0):
            break
      else:
          yield i
      i += 1

if __name__ == "__main__":

   print(list(getprimes(100)))
