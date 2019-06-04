# Josh Ortiz cs 561
# Question 2
num = 1
sum = 0
while(num%5!=0):
	num = int(input("Please enter number:"))
	if num%2 == 0:
		sum += num

print("Sum:",sum)