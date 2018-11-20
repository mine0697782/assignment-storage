import random

class GuessNumber:

	def __init__(self):
		self.secret = 0
		self.trials = 0

	def newGame(self):
		self.secret = int((random.random())*1000)
		self.trials = 0
	
	def guess(self, userGuess):
		self.trials += 1
		num = int(userGuess)
		if num == self.secret:
		       return ('Success')
		elif num > self.secret:
		       return ('Guess is Bigger')
		elif num < self.secret:
		       return ('Guess is Smaller')

	def getGuessCount(self):
	        return self.trials


if __name__ == '__main__':
	g = GuessNumber()
	g.newGame()
	while(1):
		g.trials += 1
		num = int(input("Guess : "))
		if num == g.secret:
			print ('Success')
			break
		elif num > g.secret:
			print ('Guess is Bigger')
		elif num < g.secret:
			print ('Guess is Smaller')

	guessCount = g.getGuessCount()
	print("SUCCESS in %d trials" % guessCount)
