# Josh Ortiz cs561
# Question 5

class c1:
	def __init__(self,s,x,y):
		self.s = s
		self.x = x
		self.y = y
	def __str__(self):
		return ' '.join([self.s,str(self.x),str(self.y)])
	def swap(self):
		self.x,self.y = self.y,self.x
	def add(self,other):
		return c1(self.s+'-'+other.s,self.x+other.x,self.y+other.y)
	def sum(self):
		return self.x + self.y

def distance(c1Data):
	return abs(c1Data.x - c1Data.y)

trial = c1("A",10,6)
print("trial:               ",trial)
trial.swap()
print("trial.swap():        ",trial)
print("trial.add('B',14,50):",trial.add(c1('B',14,50)))
print("trial.sum():         ",trial.sum())
print("distance(trial):     	",distance(trial))