def first(a, b):
    if a*b != 0:
        return first(a-1, b+1)
    else:
        return a+b
def second(a, b):
    if a*b != 0:
        return second(a-1, b-1)
    else:
        return a+b

def third(c):
    if c != 0:
        return c+third(c-1)
    else:
        return c

A = int(input("Enter number 1 : "))
B = int(input("Enter number 2 : "))
print("Addition Result is : ",first(A, B))
print("Difference Result : ",second(A, B))

print()
C = int(input("Enter number : "))
print("Result is :",third(C))

