import sys
with open(sys.argv[1],'r') as f:
    for line in f:
        n,p1,p2 = tuple(int(i) for i in line.strip().split(','))
        s = str(bin(n))
        print str(s[-p1] == s[-p2]).lower().strip()

