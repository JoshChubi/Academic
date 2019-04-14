# Josh Ortiz CI 561
import random
import math

numberOfRandoms = 10

file_ranNum = open("randomNumbers.txt",'w')
for itteration in range(numberOfRandoms):
    file_ranNum.write(str(random.randint(0,9))+' ')
file_ranNum.close()

numbers = [int(element) for element in ( open("randomNumbers.txt").read() ).split()] 
file_ranNum.close()

avg = sum(numbers) / numberOfRandoms     

tempSD = [((element-avg)**2) for element in numbers]
sd = math.sqrt(sum(tempSD) / numberOfRandoms)

print("RandomNumbers:", numbers,"\n\naverage:",avg,"\n\nstandard Deviation:",round(sd,2),"\n")