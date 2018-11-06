import sys
from math import log
with open(sys.argv[1],'r') as f:
    for line in f:
        n = long(line)
        if n == 0:
            print -1
        else:
            print int(log(n,2))
