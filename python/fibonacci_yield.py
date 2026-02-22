#
#   This  one has an issue in that it misses
#   the first 0 and 1 in the result.
#   But it does illustrate the use of "yield" in
#   this context.  Some will say it is fine.
#   Some will say it has a bug.
#
def fibonacci(n):
       a, b = 0, 1
       for i in range(n):
           yield b
           a, b = b, a + b

if __name__ == "__main__":

   print(list(fibonacci(5)))
   print(list(fibonacci(9)))
   print(list(fibonacci(30)))
