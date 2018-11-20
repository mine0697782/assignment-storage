def encode(input_word, num):
	a = []
	word = 'abcdefghijklmnopqrstuvwxyz'
	for i in range(len(input_word)):
		for j in range(len(word)):
			if input_word[i] == word[j]:
				a.append(word[(j+num)%len(word)])
	return a

word = input()
n = int(input())
print(encode(word,n))
