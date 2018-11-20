def encode(input_word,input_num):
	encoded = []
	alp = 'abcdefghijklmnopqrstuvwxyz'
	for i in range(len(input_word)):
		for j in range(len(alp)):
			if input_word[i] == alp[j]:
				encoded.append(alp[j+input_num%len(alp)])
	return encoded


word = input("Word : ")
num = int(input("number : "))
print("Caesar code : ",encode(word,num))
