import sys
import string
import heapq

#
#   A popular training site uses this
#   as a sort/merge in place method.
#   It does not work.  It always leaves
#   off the last element of list1.
#   Just here so folks can "recognize" it
#   when they stumble across it.
#
def mergeandsortbroken(list1, list2):

   for i in range(len(list1) - 1):  
      for j in range(len(list2) - 1):  
         if (list1[i] > list2[j]) and (list1[i] <= list2[j+1]):  
            list2.insert(j + 1, list1[i])  
            break

   print("MSBroken: Sorted list is", list2, "<-- there should be a 12")  

   return


#
#   Merge and sort as of python3
#
def mergeandsort(list1, list2):

   list3 = list1 + list2
   list3.sort()
   print("MS: Sorted list is", list3)  

   return

#
#   Naive/traditional approach to
#   merge and sort
#
def mergeandsort2(list1, list2):

   for item in list2:
      list1.append(item)
   list1.sort()
   print("MS2: Sorted list is", list1)  

   return

#
#   Merge and sort as of python3
#
def mergeandsort3(list1, list2):

   list1.extend(list2)
   list1.sort()
   print("MS3: Sorted list is", list1)  

   return

#
#   Merge and sort using heap merge
#   Heap merge return an object.
#   You need to make it a list
#
def mergeandsort4(list1, list2):

   list3 = list(heapq.merge(list1, list2))
   print("MS4: Sorted list is", list3)  

   return


if __name__ == "__main__":

   #
   #   Broken merge sort
   #
   list1 = [2, 4, 6, 8, 10, 12]
   list2 = [1, 3, 5, 7, 9, 11]
   mergeandsortbroken(list1, list2)

   #
   #   The routine above attempted in place
   #   work.  So list2 gets changed.  reset.
   #
   list1 = [2, 4, 6, 8, 10, 12]
   list2 = [1, 3, 5, 7, 9, 11]
   mergeandsort(list1, list2)
   mergeandsort2(list1, list2)

   list1 = [2, 4, 6, 8, 10, 12]
   list2 = [1, 3, 5, 7, 9, 11]
   mergeandsort3(list1, list2)

   list1 = [2, 4, 6, 8, 10, 12]
   list2 = [1, 3, 5, 7, 9, 11]
   mergeandsort4(list1, list2)

   sys.exit(0)
