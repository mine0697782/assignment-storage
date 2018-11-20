def factorial(num):
	if num==1:
		return 1
	else:
		return num*factorial(num-1)
### start ###

result = 0
count = 0
#number = input("input number : ")
for number in range(1,100):
	number = str(number)
	for j in number:
		j = int(j)
		result += factorial(j)

	number = int(number)
	
	if result == number:
		count += 1
		#print("This is Digit Factorial")
	#else:
		#print("This is not Digit Factorial")
	result = 0
print("count : "+count)
