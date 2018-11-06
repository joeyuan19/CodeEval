from sys import argv
import matplotlib.pyplot as plt
from re import findall

def process(line):
    pts = [map(int,i) for i in findall(r'\((\d+),(\d+)\)',line)]
    x = [i[0] for i in pts]
    y = [i[1] for i in pts]
    plt.xlim(-1,12)
    plt.ylim(-1,12)
    plt.plot(x,y,'ro')
    plt.show()


with open(argv[1],'r') as f:
    for line in f:
        process(line)

