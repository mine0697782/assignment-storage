for i in range(2,10):
	print("{}단\n".format(i))
	for j in range(1,10):
		print("{} x {} = {}".format(i,j,i*j),end="	")
		if not(j%3):
			print("\n")
	print()
