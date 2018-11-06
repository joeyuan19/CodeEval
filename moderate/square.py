import sys
import re

def plot(X,Y):
    g = [['.' for i in xrange(11)] for j in xrange(11)]
    for x,y in zip(X,Y):
        g[10-y][x] = 'x'
    print  '10 ' + ' '.join(i for i in g[0])
    for y in xrange(9,-1,-1):
        print ' ' + str(y) + ' ' + ' '.join(i for i in g[10-y])
    print '   '+' '.join(str(i) for i in xrange(11))

def process(line):
    points = re.findall(r'\((\d+),(\d+)\)',line)
    x = [int(i[0]) for i in points]
    y = [int(i[1]) for i in points]
    print points
    plot(x,y)

with open(sys.argv[1]) as f:
    i = 1
    for line in f:
        print i
        process(line)
        i += 1
