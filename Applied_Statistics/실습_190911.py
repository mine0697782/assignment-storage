import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats

def printout(outFile, xlabel = '', ylabel = '', title = '', outDir = '.'):
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(title)

    plt.tight_layout

    xlim = plt.gca().get_xlim()
    plt.hlines(0, xlim[0], xlim[1], linestyles = '--', colors = '#999999')
    plt.gca().set_xlim(xlim)

    plt.show()
    plt.close()

def normalDist(x, mu, std):
    a = 1/(std*np.sqrt(2*np.pi))
    b = np.exp(-(x-mu)**2/(2*std**2))
    return (a*b)

if __name__ == "__main__":
    ## Data
    np.random.seed(1234)
    x = np.random.randn(500)

    # Scatter Plot
    plt.scatter(np.arange(len(x)),x)
    plt.xlim([0, len(x)])
    printout('scatterPlot.png', 'Datapoints', 'Values', 'Scatter')

    # Histogram
    plt.hist(x)
    printout('histogram_plain.png', 'Data Values', 'Frequency', 'Histogram, Default Settings')

    plt.hist(x, 25)
    printout('histogram.png', 'Data Values', 'Frequency', 'Histogram, 25 bins')

    # Cumulative probability density
    numbines = 20
    plt.plot(stats.cumfreq(x, numbines)[0])
    printout('Cumulative Frequency Function.png', 'Data Values', 'CumFreq', 'Cumulative Frequency')

    # Boxplot
        # The ox consists of the first, second (middle) and third quartile
    plt.boxplot(x, sym = '*')
    printout('boxplot.png,', xlabel = 'Values', title = 'Boxplot')

    plt.boxplot(x, sym = '*', vert = False)
    plt.title('Boxplot, horizontal')
    plt.xlabel('Values')
    plt.show()

    # Gaussian Normal Distribution
    n, bins, ig = plt.hist(x, bins = 25, density = True)
    mu = np.mean(x)
    std = np.std(x)
    plt.plot(bins, normalDist(bins, mu, std), color = 'r')
    plt.show()