import sys

#
#   This way you can keep a running
#   total, if you want, in another list
#
def adder1(mylist):

   print("ADDER1(for) values")
   total = 0
   newlist = []

   for item in mylist:
      total += item
      newlist.append(total)

   #
   #   Print original list
   #
   print(mylist)
   #
   #   Print new list with
   #   running total
   #
   print(newlist)

   return

#
#   sum returns a total, not a list
#   this one also calculates the average of
#   the list of numbers
#
def adder2(mylist):

   print("ADDER2(sum) values")
   total = sum(mylist)
   average = total / len(mylist)

   #
   #   Print original list
   #
   print(mylist)
   #
   #   Print total
   #
   print("SUM: ", total)
   print("AVERAGE: ", average)

   return

if __name__ == "__main__":

   mylist = [1, 2, 3, 4, 5, 6]

   adder1(mylist)
   adder2(mylist)
