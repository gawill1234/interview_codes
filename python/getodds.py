#
#   Three ways to see if a number is odd
#   in python3
#
def getodds(nums):
     odd_nums = filter(lambda num: num % 2, nums)
     return list(odd_nums)

def getodds2(nums):

   odd_nums = []

   for item in nums:
      if ((item % 2) == 1):
         odd_nums.append(item)

   return odd_nums

def getodds3(nums):

   odd_nums = []

   for item in nums:
      if (item & 1):
         odd_nums.append(item)

   return odd_nums

if __name__ == "__main__":
   nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

   print(getodds(nums))
   print(getodds2(nums))
   print(getodds3(nums))
