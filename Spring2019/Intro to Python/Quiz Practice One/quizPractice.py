# Josh Ortiz CI 561
def diffChars(strng):
    if not len(strng):
        return 0;
    count = 0;
    while len(strng):
        count += 1
        strng = strng.replace(strng[0],"")
    return count

#try to make shorter
def phi(n):
    count = 1
    for num in range(n):
        if num > 1:
            for i in range(2,num):
                if (num % i) == 0:
                    break
            else:
                count += 1
    return count

def howMany(c,s):
    pos = s.find(c,0)
    count = 0
    while pos != -1 :
        count += 1
        pos = s.find(c,pos+1)
    return count

def threeInRow(c,s):
    return True if s.find(c*3) != -1 else False

def minAveMax(a,b,c):
    mAm = [a,b,c]
    mAm.sort()
    mAm[1] = (mAm[0] + mAm[2] ) // 2
    return mAm

def output(n,msg):
    print(msg*n)

def doNothing():
    return

print("diffChars(\"Abracadabra\"): ",diffChars("Abracadabra"))

print("\nphi(5): ",phi(5))

print("\nhowMany('e',\"cheese\"): ",howMany('e',"cheese"))

print("\nthreeInRow('e',\"Wheee!\"): ",threeInRow('e',"Wheee!"))

print("\nminAveMax(2.0,6.0,1.0)",minAveMax(2.0,6.0,1.0))

print("\noutput(3,'HELP!'): ",end='')
output(3,"HELP!")

print("\ndoNothing(): ",end='')
doNothing()

