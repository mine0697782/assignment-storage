money = 1000000
year = 0
while money < 2000000:
    money *= 1.05
    year += 1
print("{}년째에 {}원이 됩니다.".format(year,money))