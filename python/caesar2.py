import string

#
#  Caesar cypher using python3 translate
#  and maketrans
#

alphabet = string.digits + string.ascii_uppercase + \
           string.ascii_lowercase + " " + string.punctuation

def caesar(msg, key):
    return msg.translate(
        str.maketrans(alphabet, alphabet[key:] + alphabet[:key])
    )

def decryptit(key):
    return(len(alphabet) - key)

def runnit(mystring, key):
   
   xx = caesar(mystring, key)
   print("key:", key, "  ", xx)
   new_key = decryptit(key)
   yy = caesar(xx, new_key)
   print("key:", new_key, "  ", yy)

   return


if __name__ == "__main__":

   key = 19
   runnit("ABCDEFGHIJKLMNOPQRSTUVWXYZ", key)

   print("##################")

   key = 13
   runnit("SQUIRREL FART ON A CHIPMUNK", key)

   print("##################")

   key = 22 
   runnit("THE NINTH LEVEL OF HELL IS JOB HUNTING", key)

   print("##################")

   key = 38 
   runnit("A string with a MIX of upper and lower cases", key)
