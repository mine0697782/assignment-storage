import numpy as np

np.random.seed(1234)
x = np.random.randn(500)

temp = 0
for i in range(len(x)):
    temp += x[i]

m = temp/len(x)

temp = 0
for i in range(len(x)):
    temp += (m-x[i])**2

v = temp/len(x)
sd = v**0.5

md = np.sort(x)[250]

print("mean: ", m, "variance: ", v, "standard deviation: ", sd, "median: ", md)
print("Mean: ", np.mean(x), "Variance: ", np.var(x), "Standard deviation: ", np.std(x), "Median: ", np.median(x))
