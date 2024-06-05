import sys
import string

#
#   Count the occurrences of
#   letters in a string.
#
#   Two ways.  Actual counts into
#   an array.  And map object count
#   However, for map object count
#   the results are limited to
#   lowercase characters.
#

alphabet = string.ascii_lowercase

def init_array(myarray):
 
   i = 0
   while (i < 256):
      myarray.append(0)
      i += 1

   return(myarray)

#
#   Yes, I suppose the counts can
#   be done with map.
#   This only counts lower case
#   alphabetic characters.
#
def othercount(mystring):
   
   return list(map(mystring.lower().count, alphabet))


def parse_word_string(mystring, myarray):

   #
   #   lowercase everything so the sorts
   #   are consistent with respect to
   #   letter order.
   #
   for i in mystring:
      myarray[ord(i.lower())] += 1

   return(myarray)

def printcounts(myarray):

   for i in range(len(myarray)):
      if myarray[i] > 0:
         print("   %c: %d" % (chr(i), myarray[i]))

   return

def printcounts2(myarray):

   for i in range(len(myarray)):
      if myarray[i] > 0:
         print("   %c: %d" % (chr(i + 97), myarray[i]))

   return

def runnit(mystring):

   myarray = []

   myarray = init_array(myarray)
   myarray = parse_word_string(mystring, myarray)

   print("original string  : %s" % (mystring))
   printcounts(myarray)

   return

def runnit2(mystring):

   myarray = othercount(mystring)
   print("  # Map object count")
   printcounts2(myarray)

   return


if __name__ == "__main__":

   runnit("Mississippi")
   runnit2("Mississippi")
   print("######")
   runnit("occurrences")
   runnit2("occurrences")
   print("######")
   runnit("squirrels")
   runnit2("squirrels")
   print("######")
   runnit("Massachusetts")
   runnit2("Massachusetts")
   print("######")
   runnit("Connecticut")
   runnit2("Connecticut")
   print("######")
   runnit("Multi space with punctuation!")
   runnit2("Multi space with punctuation!")
   print("######")
   runnit("2468097135")
   runnit2("2468097135")
