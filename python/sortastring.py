import sys

#
#   Done for giggles to see
#   how the C sortastring.c
#   would look in python.
#
#   Did it with python lists.
#   You can use actual arrays,
#   buy you'd need to import
#   numpy.
#
def init_array(myarray):
 
   i = 0
   while (i < 256):
      myarray.append(0)
      i += 1

   return(myarray)


def parse_word_string(mystring, myarray):

   #
   #   lowercase everything so the sorts
   #   are consistent with respect to
   #   letter order.
   #
   for i in mystring:
      myarray[ord(i.lower())] += 1

   return(myarray)

def sortedarray(myarray):

   msorted = ""

   for i in range(256):
      if myarray[i] > 0:
         for j in range(myarray[i]):
            msorted = msorted + chr(i)

   return(msorted)

def runnit(mystring):

   myarray = []

   myarray = init_array(myarray)
   myarray = parse_word_string(mystring, myarray)
   msorted = sortedarray(myarray)

   print("original string  : %s" % (mystring))
   print("sorted (program) : %s" % (msorted))
   #
   #   Just so folk realize that I know
   #   python has a number of sorts "built in".
   #
   res = ''.join(sorted(mystring.lower()))
   print("sorted(py sort)  : %s" % (res))

   return


if __name__ == "__main__":

   runnit("Mississippi")
   print("######")
   runnit("massive flood")
   print("######")
   runnit("smile")
   print("######")
   runnit("limes")
   print("######")
   runnit("slime")
   print("######")
   runnit("Multi space with punctuation!")
   print("######")
   runnit("2468097135")
