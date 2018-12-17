def func():
    numList = [x for x in range(1,10000)]
    for n in range(1,10000):
        num = n
        num = num + (num%10) + ((num%100)//10) + ((num%1000)//100) + ((num%10000)//1000) + (num//10000)
        if num<10000:
            numList[num-1] = -1
    for n in numList:
        if n != -1:
            print(n)

func()