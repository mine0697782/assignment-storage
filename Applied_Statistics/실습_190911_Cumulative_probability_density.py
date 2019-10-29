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

    numbines = 20
    plt.plot(stats.cumfreq(x, numbines)[0])
    printout('Cumulative Frequency Function.png', 'Data Values', 'CumFreq', 'Cumulative Frequency')