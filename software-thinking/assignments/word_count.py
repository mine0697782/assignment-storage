import operator
import re

f = open("article.txt")
text = f.read().lower()
f.close()

sw = open("stopwords.txt")
sw = sw.read()

word_list = []
sw_list = []
temp = []

word_list = text.split(" ")
stoplist = sw.split("\n")


wordfreq = {}

for word in word_list:
	if word not in stoplist:
		if word not in wordfreq:
			wordfreq[word] = 1
		else:
			wordfreq[word] += 1

sortedWf = sorted(wordfreq.items(), key = operator.itemgetter(1), reverse=True)
print(sortedWf)
