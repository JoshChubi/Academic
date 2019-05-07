import random, math

def percAboveSD(fileName,sd):
	count = 0
	data = open(fileName).read().split()
	for elem in data:
		if float(elem) >= sd:
			count += 1
	return (count/len(data))*100

dataSize = 1000000
mean = 0 
sd = 1

dataFile = open("data.txt",'w')
for i in range(dataSize):
	dataFile.write(str(random.gauss(mean,sd))+' ')
dataFile.close()

for i in range(1,4):
	print(str(percAboveSD("data.txt",sd*i))+"%")
