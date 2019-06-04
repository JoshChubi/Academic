# Josh Ortiz Cs561
# Question 4
inFile = open(input("input file name:"),'r')
outFile = open(input("output file name:"),'w')
lineNum = 1
for line in inFile:
	numLi = sorted([int(num) for num in line.split()])
	numCount = len(numLi)
	avg = sum(numLi)/numCount
	median = (numLi[numCount//2] + numLi[numCount//2-1])/2 if numCount%2 == 0 else numLi[numCount//2]
	outFile.write(' '.join([str(lineNum),line[:-1],str(avg),str(median)])+'\n')
	lineNum += 1
inFile.close()
outFile.close()