#I declare i have never cheated at all

year = int(input("몇년입니까? "))
month = int(input("몇월입니까? "))
day = int(input("며칠입니까? "))
total = 0

total += (year-1)*365

if month == 2:
	total += 31
elif month == 3:
	total += 59
elif month == 4:
	total += 90
elif month == 5:
	total += 120
elif month == 6:
	total += 151
elif month == 7:
	total += 181
elif month == 8:
	total += 212
elif month == 9:
	total += 243
elif month == 10:
	total += 273
elif month == 11:
	total += 304
elif month == 12:
	total += 334

total += day

yun = year//4 - year//100 + year//400

if month>2:
	yun-1
total += yun

if (total-1)%7 == 0:
	print("월요일")
if (total-1)%7 == 1:
	print("화요일")
if (total-1)%7 == 2:
        print("수요일")
if (total-1)%7 == 3:
        print("목요일")
if (total-1)%7 == 4:
        print("금요일")
if (total-1)%7 == 5:
        print("토요일")
if (total-1)%7 == 6:
        print("일요일")

