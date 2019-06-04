# Josh Ortiz 

infile = open(input("enter input file name: "),'r')
output = open(input("enter output file name: "),'w')

for line in infile:
	temp = []
	if len(line.split()) <= 0:
		print("not enough entries")
		output.seek(0)
		output.truncate()
		exit()
	try:
		temp = [float(num) for num in line.split()]
	except:
		print("not float detected")
		output.seek(0)
		output.truncate()
		exit()
	output.write(str(sum(temp)/len(temp))+": "+line)
