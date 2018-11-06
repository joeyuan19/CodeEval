import sys

FIB = [0,1,1]

def fib(n):
    if n < len(FIB):
        return FIB[n]
    else:
        l = len(FIB)
        for i in xrange(l,n+1):
            FIB.append(FIB[-1]+FIB[-2])
        return FIB[-1]

with open(sys.argv[1],'r') as f:
    for line in f:
        print fib(int(line.strip()))
        
