import time

def fibo(num):
    if num <= 1:
        return num
    return fibo(num-1) + fibo(num-2)

def interfibo(num):
    pre_Fibo_1 = 0
    pre_Fibo_2 = 1
    result = 0 

    if num <= 1:
        return num 
    
    for i in range(num-1):
        result = pre_Fibo_1 + pre_Fibo_2
        pre_Fibo_1 = pre_Fibo_2
        pre_Fibo_2 = result

    return result

while True:
    nbr = int(input("Enter a number : "))
    if nbr == -1:
        break
    ts = time.time()
    fibonumber = interfibo(nbr)
    ts = time.time() - ts
    print("InterFibo(%d) = %d, time %.6f" %(nbr, fibonumber, ts))
    ts = time.time()
    fibonumber = fibo(nbr)
    ts = time.time() - ts
    print("Fibo(%d) = %d, time %.6f\n" %(nbr, fibonumber, ts))
