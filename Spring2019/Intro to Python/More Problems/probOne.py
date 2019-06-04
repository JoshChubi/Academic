# Josh Ortiz
import math
side = float(input("please enter the side of a regular hexagon: "))

if side < 0:
	print("side cannot be negative")
	exit()
else:
	area = 3/2 * math.sqrt(3)*(side**2)
	print("area of regular hexagon is:",area)