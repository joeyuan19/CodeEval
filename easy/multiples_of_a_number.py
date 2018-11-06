import timeit
N = 1000
a = timeit.timeit(stmt="""
import sys
with open(sys.argv[1],'r') as f:
    for line in f:
        x,n = tuple(int(i) for i in line.strip().split(','))
        t = n
        while t < x:
            t += n
        print t
""",number=N)
b = timeit.timeit(stmt="""
import sys
def log2(n):
    c = 1
    while n > 2:
        n = n >> 1
        c += 1
    return c
with open(sys.argv[1],'r') as f:
    for line in f:
        x,n = tuple(int(i) for i in line.strip().split(','))
        c = log2(n)
        print (x >> c << c) + n
""",number=N)
print "a",a/N
print "b",b/N
