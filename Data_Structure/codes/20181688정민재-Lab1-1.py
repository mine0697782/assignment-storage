def inter(data, num):
    high = len(data)
    low = 0
    while True:
        if low >= high:
            return "NOT FOUND"
        index = (high + low) // 2

        if data[index] > num:
            high = index - 1
        elif data[index] < num:
            low = index + 1
        elif data[index] == num:
            return index

def recur(data, num, high, low):
    if low >= high:
        return "NOT FOUND"
    index = (high + low) // 2

    if data[index] > num:
        high = index
    elif data[index] < num:
        low = index
    elif data[index] == num:
        return index
    return recur(data, num, high, low)

n = int(input("Eneter an integer to search : "))
data = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
method = int(input("Enter method of search (1. Binary Search  2. Recursive binary search) : "))
method_list = [inter, recur]
high = len(data)
low = 0
if method == 2:
    result = method_list[method-1](data, n, high, low)
    print(n,"is at position",result,".")
elif method == 1:
    result = method_list[method-1](data, n)
    print(n,"is",result,".")
