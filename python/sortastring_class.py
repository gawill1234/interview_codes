import sys

#
#   Done for giggles to see
#   how the C sortastring.c
#   would look in python.
#
#   Did it with python lists.
#   You can use actual arrays,
#   but you'd need to import
#   numpy.
#
class SORTER(object):

   myarray = []

   def __init__(self, mystring):

      self.init_array()
      self.runnit(mystring)

      return

   def init_array(self):
    
      i = 0
      if (len(self.myarray) >= 256):
         while (i < 256):
            self.myarray[i] = 0
            i += 1
      else:
         while (i < 256):
            self.myarray.append(0)
            i += 1
   
      return
   
   
   def parse_word_string(self, mystring):
   
      #
      #   lowercase everything so the sorts
      #   are consistent with respect to
      #   letter order.
      #
      for i in mystring:
         self.myarray[ord(i.lower())] += 1
   
      return
   
   def sortedarray(self):
   
      msorted = ""
   
      for i in range(256):
         if self.myarray[i] > 0:
            for j in range(self.myarray[i]):
               msorted = msorted + chr(i)
   
      return(msorted)
   
   def runnit(self, mystring):
   
      myarray = self.parse_word_string(mystring)
      msorted = self.sortedarray()
   
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
   
   SORTER("Mississippi")
   print("######")
   SORTER("massive flood")
   print("######")
   SORTER("smile")
   print("######")
   SORTER("limes")
   print("######")
   SORTER("slime")
   print("######")
   SORTER("Multi space with punctuation!")
   print("######")
   SORTER("2468097135")
