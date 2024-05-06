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
