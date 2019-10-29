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

if __name__ == '__main__':
    np.random.seed(1234)
    x = np.random.randn(500)

    plt.hist(x)
    printout('histogram_plain.png', 'Data Values', 'Frequency', 'Histogram, Default Settings')

    plt.hist(x, 25)
    printout('histogram.png', 'Data Values', 'Frequency', 'Histogram, 25 bins')