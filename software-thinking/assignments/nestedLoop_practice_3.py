month = int(input("몇월인지 입력하시오 : "))
days = 0
if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12):
	days = 31
elif (month == 4 or month == 6 or month == 9 or month == 11):
	days = 30
else:
	dyas = 28

print("\n\n\t\t\t{}월\n\n".format(month))

print("{}\t{}\t{}\t{}\t{}\t{}\t{}\n".format("월","화","수","목","금","토","일"))
for i in range(days):
	print("%d\t"%(i+1),end='')
	if not((i+1)%7):
		print("\n")
print("\n\n")
