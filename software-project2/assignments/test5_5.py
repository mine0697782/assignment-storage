import time
import random

def fibo(n):
    if n <= 1:
        return n
    return fibo(n - 1) + fibo(n - 2)

def interfibo(int n):
    sum1 = 0
    sum2 = 1
    result = 0
    
    if n <= 1:
        return 0
    
    for i in range(n-1):
        result = sum1 + sum2
        sum1 = sum2
        sum2 = result
    
    return result

while True:
    nbr = int(input("Enter a number: "))
    if nbr == -1:
        break
    ts = time.time()
    fibonumber = fibo(nbr)
    ts = time.time() - ts
    print("Fibo(%d)=%d, time %.6f" %(nbr, fibonumber, ts))
