import time

def binSearch_Recursive(numbers, lower, upper, target):
    if (lower > upper):
        return -1

    middle = int((lower + upper) // 2)

    if numbers[middle] == target:
        return middle
    elif numbers[middle] < target:
        lower = middle + 1
    else:
        upper = middle - 1
    return binSearch_Recursive(numbers, lower, upper, target)

def binSearch(numbers, lower, upper, target):
    while (lower <= upper): 
        middle = int((lower + upper) // 2)
      
        if numbers[middle] == target :
            return middle
        elif numbers[middle] < target :
            lower = middle + 1
        else:
            upper = middle - 1
    return -1

data = input("Enter list of sorted numbers: ")
numbers = data.split()
numbers = [int(i) for i in numbers]

target = int(input("Enter the number to find: "))

lower = 0
upper = len(numbers) - 1
idx = -1

ts = time.time()
idx = binSearch(numbers, lower, upper, target)
ts = time.time() - ts
if idx == -1:
    print("No such number : ", target)
else:
    print("Inter Binary Search\nTarget %d is at Index %d" %(target, idx))
  
print("Time : ", ts)

ts = time.time()
idx = binSearch_Recursive(numbers, lower, upper, target)
ts = time.time() - ts
if idx == -1:
    print("No such number : ", target)
else:
    print("Recursive binary Search\nTarget %d is at Index %d" %(target, idx))

print("Time : ", ts)
