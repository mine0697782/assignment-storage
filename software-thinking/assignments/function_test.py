def multifly(start_num,end_num) :
	ret = 1
	for num in range(start_num,end_num+1) :
		ret *= num
	
	return(ret)

#main program start

a = int(input("enter a : "))
b = int(input("enter b : "))
print("First print : ",multifly(a,b))
print("Second print : {}".format(multifly(a,b)))
