num = int(input("자연수 n을 입력하세요"))

for line in range(num):

	for blank in range(num-line):
		print(" ",end='')
	if num%2:
		for j in range(((line+1)*2)-1):
			print("*",end='')
		print()

	else:
		for j in range((line+1)*2):
			print("*",end='')
		print()

#8번 라인의 기능은 print(" "*(n))로도 구분할 수 있다.
