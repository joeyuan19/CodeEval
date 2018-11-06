def sieve(N):
    s = [0,0,1]+[1,0]*(N/2)
    i = 3
    while i*i < N:
        if s[i]:
            for itr in xrange(i*2,N,i):
                s[itr] = 0
        i += 2
    return [i for i in range(N) if s[i]==1]

def palidrome(n):
    s = str(n)
    l = len(s)
    for i in xrange(0,l/2):
        if s[i] != s[l-1]:
            return False
    return True
s = 0
for i in sieve(10000)[:1000]:
    s += i
print s
