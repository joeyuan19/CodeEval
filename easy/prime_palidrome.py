def quick_prime(n):
    for i in xrange(3,int(n**.5)+1,2):
        if n%i == 0:
            return False
    return True

def palidrome(n):
    s = str(n)
    l = len(s)
    for i in xrange(0,l/2):
        if s[i] != s[l-1]:
            return False
    return True

for i in xrange(999,3,-2):
    if quick_prime(i) and palidrome(i):
        break
print i
