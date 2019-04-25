data = [90, 40, 60, 10, 50, 80, 20, 70]
MAX = 0
MIN = 9999
maxIndex = 0
minIndex = 0
for i in range(len(data)):
    if data[i] > MAX:
        MAX = data[i]
        maxIndex = i+1
    if data[i] < MIN:
        MIN = data[i]
        minIndex = i+1
print("Minimun number is", MIN, "at position", minIndex)
print("Maximum number is", MAX, "at position", maxIndex)
