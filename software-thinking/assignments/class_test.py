class Ball:
	def __init__(self):
		self.color = "default"
		self.size = 1
		self.direction = "down"

	def bounce(self):
		if self.direction == "down" :
			self.direction = "up"
myball = Ball()
print(myball.direction)
myball.bounce()
print(myball.direction)
