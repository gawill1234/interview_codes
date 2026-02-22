#
#   get prime number using a function
#   using "yield".
#
def getprimes(mymax):
    i = 2
    while i < mymax:
        for j in range(2, i):
            if i % j == 0:
                break
        else:
            yield i
        i += 1

print(list(getprimes(100)))
