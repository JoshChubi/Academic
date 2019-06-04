# Josh Ortiz Cs561
# QUestion 3
import math
def f(x):
	return 3*math.sqrt(x) if type(x) == float and x > 0 else "Invalid Input"

def without(s0,s1):
	if type(s0) != str and type(s1) != str:
		return "Invalid Input"
	for letter in s1:
		s0 = s0.replace(letter,'')
	return s0

def f1(li):
	if not all(type(num) == float for num in li):
		return "Invalid Input"
	newLi = [f(num) for num in li if num >= 1 ]
	return newLi[::-1]

def f2(li):
	if not all(len(elem) > 0 and all(type(num) == float for num in elem) for elem in li):
		return "Invalid Input"
	return [(min(elem),max(elem)) for elem in li]
	
print("\nf(4):",f(4.0))
print('f("bogus"):',f("bogus"))
print("f(-math.pi):",f(-math.pi))

print("\nwithout(s0,s1):",without("abracadabra","Yabba Dabba"))

print("\nf1(li):",f1([0.5,-47.0,9.0,4.0,16.0]))	

print("\nf2(li):",f2([[1.0,2.0,3.0],[5.0],[10.0,9.0,8.0,7.0]]))