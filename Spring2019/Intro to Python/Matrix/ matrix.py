import random

def show(mtx):
	for row in mtx:
		print('|',end='')
		for col in row:
			print("{0:2}".format(col),end = ' ')
		print('|')
	print()

def makeMat(row,col):	
	return [[random.randint(0,9) for colIttr in range(col)]for rowIttr in range(row)]

def zeroMat(row,col):	
	return [[0]*row]*col

def sumMat(mtrLhs,mtrRhs):
	return [[colLhs+colRhs for colLhs, colRhs in zip(rowLhs,rowRhs)]for rowLhs,rowRhs in zip(mtrLhs,mtrRhs)]	

matrixLhs = makeMat(3,3)
matrixRhs = makeMat(3,3)
show(matrixRhs)
show(matrixLhs)
show(sumMat(matrixLhs,matrixRhs))
