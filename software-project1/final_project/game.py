from guess import GuessNumber 

g = GuessNumber()

def new_game():
	g.newGame()
	return {'code': 'success'}

def guess(d):
	try:
		guess = d.get('guess', [''])[0]
	except:
		return {'code': 'error', 'msg': 'wrong guess parameter'}

	compare = g.guess(guess)
	trials = g.getGuessCount()

	return {'code': 'success', 'compare': compare, 'trials': trials}
