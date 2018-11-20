list1 = ['a','b', 'c']
list2 = ['d', 'e', 'f']

print(list1+list2)

list1.append('append')

print(list1+list2)

list3 = list1 + list2

list3.insert(2,'insert')

print(list3)

list1.append(list2)

print (list1)

list1.remove(list2)

print(list1)

del list1[3]

print(list1)

pop = list1.pop()

print(list1)
print(pop)
