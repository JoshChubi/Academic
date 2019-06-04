# Josh Ortiz 

def f1(n):
	count = 0
	while n%2 == 0:
		n/= 2
		count += 1
	return count

def f2(li):
	n = min(li)
	fac = [i for i in range(1,n+1) if n%1 ==0]
	for f in sorted(fac,reverse = True):
		if all(num%f == 0 for num in li):
			return f

def f3(n):
	if n <= 1: 
		return n
	if n == 2:
		return 1
	prev = 1
	cur = 1
	phib = 1
	for i in range(2,n):
		prev = cur
		cur = phib
		phib = cur + prev
	return phib
	
def f4(li):
	res = []
	for nums in li:
		for n in nums:
			res.append(n)		
	return res

print("f1(96):",f1(96))
print("f2(li):",f2([99,33,44,55,121]))
print("f3(100):",f3(100))
print("f4(li):", f4([[1,2,3],[3,2,1],[],[1,2,3]]))