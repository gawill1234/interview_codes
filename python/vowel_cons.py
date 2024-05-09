#
#  Count vowels and consonants in a string.
#  First make sure what you are looking at
#  is a letter, not some other character.
#  Then see if it is a vowel or not.
#
import sys, string

vowels = "aeiou"
alphabet = string.ascii_lowercase
 
def vowel(mystring):

   vowel_count = cons_count = 0

   for letter in mystring.lower():
      if (letter in alphabet):
         if (letter in vowels):
            vowel_count += 1
         else:
            cons_count += 1


   return vowel_count, cons_count
 
if __name__ == "__main__":

   mystring = 'abcdefghijklmnopqrstuvwxyz'
   v, c = vowel(mystring)
   print("String: ", mystring)
   print("vowels: ", v, "  consonants: ", c)
   mystring = 'ABC! DEF^ G..,, HIJKLMNOPQRSTUVWXYZ'
   v, c = vowel(mystring)
   print("String: ", mystring)
   print("vowels: ", v, "  consonants: ", c)
   mystring = 'This is a real sentence.  With punctuation and everything!'
   v, c = vowel(mystring)
   print("String: ", mystring)
   print("vowels: ", v, "  consonants: ", c)
   sys.exit(0)

