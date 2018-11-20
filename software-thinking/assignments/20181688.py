from random import *
from math import sqrt

x = 0
y = 0
radius = 10000 # cm, 임의의 반지름 지정
count = 0
pi = 0
average = 0

circle = radius*radius  # 이후 입력받는 경우를 고려해 변수를 사용

num = int(input("점을 찍을 횟수를 입력하세요 : "))

for i in range(num):
	x = randint(-radius, radius)
	y = randint(-radius, radius)

	if (((x*x)+(y*y)) <= circle):
		count += 1

pi += (count/num) * 4

print(pi)
