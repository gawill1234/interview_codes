#
#   powerset.  Set of all subsets.
#
def powset(seq):

    if seq:
        head, tail = seq[:1], seq[1:]
        for smaller in powset(tail):
            yield smaller
            yield head + smaller
    else:
        yield []

#Given that, then

def PS(myset):

    count = 0
    for s in powset(myset):
       print(s)
       count += 1
    return count

if __name__ == "__main__":

   count = PS([1,2,3,4,5,6])
   print("SET COUNT:", count)


