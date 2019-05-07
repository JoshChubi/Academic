def sumOfThree(li):
	return sum(li) if (li.count(li[0]) == 1) and (li.count(li[1]) == 1) and (li.count(li[2]) == 1) else 0

def numberFromDigits(digits,base):
	if len(digits) == 1:
		if digits <= '9': return int(digits)
		return ord(digits) + 10 - ord('A')
	return numberFromDigits(digits[:-1],base)*base+numberFromDigits(digits[-1:],base)

def digitsFromNumber(n,base):
	if n < base:
		if n <= 9: return str(n)
		return chr(n - 10 + ord('A'))
	return digitsFromNumber(n//base,base) + digitsFromNumber(n%base,base)

def baseConvert(digits, frum, to):
	n = numberFromDigits('45',10)
	return digitsFromNumber(n,to)

print("list        Sum")
li = [1,2,3]
print(li,':',sumOfThree(li))
li[0] = 2
print(li,':',sumOfThree(li))

print(numberFromDigits("23242526",36))
print(digitsFromNumber(23520935735,10))
print(baseConvert('45',10,2))
