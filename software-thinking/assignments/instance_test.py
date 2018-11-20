class Ball:
	direction = "default"

	def bounce(self):
		if self.direction == "down":
			self.direction = "up"

myBall = Ball()
print(myBall.direction)
myBall.direction = "down"
print(myBall.direction)
myBall.size = 10

myBall.bounce()
print(myBall.direction)

print(myBall.size)

yourBall = Ball()
yourBall.__class__.direction = "stop"
print(yourBall.direction)
anyBall = Ball()
print(anyBall.direction)
