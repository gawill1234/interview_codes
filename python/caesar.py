import sys
from string import ascii_uppercase

#
#  Caesar cypher using python3 translate
#  and maketrans
#

alphabet = ascii_uppercase

def caesar(msg, key):
    return msg.translate(
        str.maketrans(alphabet, alphabet[key:] + alphabet[:key])
    )

def decryptit(key):
    return(len(alphabet) - key)

if __name__ == "__main__":

   key = 19
   xx = caesar("ABCDEFGHIJKLMNOPQRSTUVWXYZ", key)
   print("key:", key, "  ", xx)
   new_key = decryptit(key)
   yy = caesar(xx, new_key)
   print("key:", new_key, "  ", yy)

   print("##################")

   key = 13
   xx = caesar("SQUIRREL FART ON A CHIPMUNK", key)
   print("key:", key, "  ", xx)
   new_key  = decryptit(key)
   yy = caesar(xx, new_key)
   print("key:", new_key, "  ", yy)

   print("##################")

   key = 22 
   xx = caesar("THE NINTH LEVEL OF HELL IS JOB HUNTING", key)
   print("key:", key, "  ", xx)
   new_key  = decryptit(key)
   yy = caesar(xx, new_key)
   print("key:", new_key, "  ", yy)

   print("##################")
   #
   #   When they ask you to do the caesar cypher, this is
   #   actually how they want you to fish for it.
   #
   mydict = ["NINTH", "HELL", "HUNTING", "NOT", "NEEDED"]
   found = False

   print("key:", key, "  ", xx)
   for i in range(len(alphabet)):
      yy = caesar(xx, i)
      print("key:", i, "  ", yy)
      for item in yy.split(" "):
         if item in mydict:
            print("Found key: ", i)
            found = True
            break

      if (found):
         break

   sys.exit(0)
