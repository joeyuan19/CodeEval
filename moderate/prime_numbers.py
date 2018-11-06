def sieve(N):
    s = [0,0,1]+[1,0]*(N/2)
    i = 3
    while i*i < N:
        if s[i]:
            for itr in xrange(i*2,N,i):
                s[itr] = 0
        i += 2
    return [i for i in range(N) if s[i]==1]

from sys import argv

with open(argv[1], 'r') as f:
    for line in f:
        print ','.join(str(i) for i in sieve(int(line)))

