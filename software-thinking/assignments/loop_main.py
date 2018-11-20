"""print(list(range(11)))
sum = 0
for i in range(11):
    sum = sum + i
print("Total Sum is %d"%sum)"""

"""
for i in range(10):
    print ("%d"%i)
"""

# 시간과 관련된 기능을 가져옵니다.
import time

n = int(input("자연수 >"))

# 소수를 구하기전 시간을 저장 합니다.jdsa
start_time = time.time()
for i in range(2, n) :
    if n % i == 0 :
        print("{N}은 {I}로 나누어 떨어집니다.".format(N = n, I = i))
        break

# whatever you want

# 걸린 시간을 출력합니다.
print("걸린 시간 :", time.time() - start_time)