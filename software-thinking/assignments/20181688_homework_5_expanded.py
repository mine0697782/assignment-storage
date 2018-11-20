

			#반지름의 크기에 따른 정확도 측정


from random import *
from math import sqrt

x = 0
y = 0
radius = 0
count = 0
pi = 0
average = 0

for times in range(5):

	radius = (10**(times+1))
	circle = radius*radius  
	
	for cal in range(1000):
	
		for i in range(1000):
			x = randint(-radius, radius)
			y = randint(-radius, radius)
		
			if (((x*x)+(y*y)) <= circle):
				count += 1
	
		pi += (count/1000) * 4
		count = 0

	average = pi/1000
	pi = 0

	print("반지름이 ",radius,"일 때 파이는 ",average)
