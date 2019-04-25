f = open("/home/jmj/Data_Structure/codes/lab0-1.dat", "r")
lines = f.readlines()
nums = []
for i in range(3):
    print(lines[i],end='')
    nums.append(len(lines[i].split()))
    print("The number of words : ", nums[i])
print("\nTotal NUmber of Words: ", sum(nums))

f.close()
