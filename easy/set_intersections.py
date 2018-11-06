import sys
with open(sys.argv[1],'r') as f:
    out = ""
    for line in f:
        A,B = line.split(';')
        A,B = [int(i) for i in A.split(',')],[int(i) for i in B.split(',')]
        a,b = map(set,(A,B))
        c = a.intersection(b)
        out += ','.join(str(i) for i in list(c))+'\n'
    print out[:-1]

