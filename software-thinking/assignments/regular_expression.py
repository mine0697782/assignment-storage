import operator
import re
import matplotlib.pyplot as plt
from wordcloud import WordCloud

f = open("article.txt")
text = f.read().lower()
f.close()

sw = open("stopwords.txt")
sw = sw.read()

word_list = []
sw_list = []
temp = []

word_list = re.split('\s+|\[^a-z]+\[^0-9\]+|[@,()./:\'-]+',text)
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

wordcloud = WordCloud()
wordcloud.generate_from_frequencies(frequencies=wordfreq)
plt.figure()
plt.imshow(wordcloud, interpolation="bilinear")
plt.axis("off")
plt.show()
