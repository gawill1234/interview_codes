#
#  Count individual vowels in a string.
#
import sys, string

#
#   Two ways.  map() and the switch
#   like if/else.  If you use python
#   3.10 or greater, you can use an
#   actual switch statement.  Not
#   assuming that here so that method
#   is not included.
#
 
def vowel(mystring):

   a, e, i, o, u = map(mystring.lower().count, "aeiou")

   return a, e, i, o, u

def vowel2(mystring):
   vowels = "aeiou"

   a = e = i = o = u = 0
   for item in mystring.lower():
      if (item in vowels):
         if (item == 'a'):
            a += 1
         elif (item == 'e'):
            e += 1
         elif (item == 'i'):
            i += 1
         elif (item == 'o'):
            o += 1
         else:
            #
            #   We know it is a vowel and
            #   only 'u' is left
            #
            u += 1

   return a, e, i, o, u

def runnit(mystring):

   print("#####")
   a, e, i, o, u = vowel(mystring)
   print("String: ", mystring)
   print("(map result    ) A: ", a, ", E: ", e, ", I: ", i, ", O: ", o, ", U: ", u)
   a, e, i, o, u = vowel2(mystring)
   print("(if/else result) A: ", a, ", E: ", e, ", I: ", i, ", O: ", o, ", U: ", u)

   return
 
if __name__ == "__main__":

   runnit('abcdefghijklmnopqrstuvwxyz')
   runnit('Mississippi')
   runnit('dereference the word')
   runnit('When in the course of human events')
   runnit('This is a sentence with spaces and punctuation!')
   sys.exit(0)

