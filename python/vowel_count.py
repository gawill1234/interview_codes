#
#  Count individual vowels in a string.
#
import sys, string
 
def vowel(mystring):

   a, e, i, o, u = map(mystring.lower().count, "aeiou")

   return a, e, i, o, u

def runnit(mystring):

   print("#####")
   a, e, i, o, u = vowel(mystring)
   print("String: ", mystring)
   print("A: ", a, ", E: ", e, ", I: ", i, ", O: ", o, ", U: ", u)

   return
 
if __name__ == "__main__":

   runnit('abcdefghijklmnopqrstuvwxyz')
   runnit('Mississippi')
   runnit('dereference the word')
   runnit('When in the course of human events')
   runnit('This is a sentence with spaces and punctuation!')
   sys.exit(0)

