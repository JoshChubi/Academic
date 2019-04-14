# Josh Ortiz CS561
import time
import datetime
import math

def volume5d(radius):
    return (8/15)*(math.pi**2)*(float(radius)**5)

def volumeD(d,radius):
    if d%2 == 0:
        return (1/math.factorial(d/2))*(float(radius)**2)*(math.pi**(d/2))
    temp = 2/d
    piExp = 0
    for i in range(d):
        if i%2 != 0:
            temp *= 2/i
            piExp += 1
    return (temp)*(math.pi**piExp)*(float(radius)**d)

print("Current Date Time is:",datetime.datetime.now(),"\n\n")

print(volume5d(1.2),'\n')

print(volumeD(5,1.2),'\n')