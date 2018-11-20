year = 0
money = 1000000

for year in range(1,100):
	money *= 1.05
	if money > 2000000:
		break
print("{}년이 {}원이 되기 전 해입니다.".format(year-1,2000000))

