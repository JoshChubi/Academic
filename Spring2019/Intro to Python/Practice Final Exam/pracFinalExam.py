import math
def sq(li):
	return [math.sqrt(num) if num >0 else 0.0 for num in li]

def rowColSameSum(mtrx):
	rowSum = all(elem == sum(mtrx[0]) for elem in [sum(row) for row in mtrx])
	diag = []
	transpose = [[row[pos] for row in mtrx]for pos in range(len(mtrx))]
	colSum = all(sum(col) == sum(transpose[0]) for col in transpose)
	return rowSum and colSum

def encode(trans, msg):
	return "".join([ letter if letter == ' ' else trans[ord(letter)-ord('A')] for letter in msg])

def output(fileName, colors):
	for line in open(fileName):
		if any(color in line for color in colors):
			print(line,end='')

print(sq([1.0,1.21,0.0,-9.0]),'\n')

print(rowColSameSum([[2,7,6],[9,5,1],[4,3,8]]),'\n')

print(encode('QWERTYUIOPASDFGHJKLZXCVBNM', 'I LIKE PIZZA'), '\n')

output('data.txt',['red','green','blue'])