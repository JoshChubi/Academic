# Josh Ortiz 
import math
temp = float(input("Enter Number: "))
nums = []
while temp > 0:
	nums.append(temp)
	temp = float(input("Enter Number: "))
avg = sum(nums)/len(nums)
nums.sort()
print("average:",avg)
print("range:",nums[-1]-nums[0])
print("median:", (nums[len(nums)//2] + nums[len(nums)//2 - 1])/2if len(nums)%2 == 0 else nums[len(nums)//2])
nums = [(num - avg)**2 for num in nums]
print("standard dev.:", math.sqrt(sum(nums)/len(nums)))