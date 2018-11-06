import sys
h = {}
with open(sys.argv[1],'r') as f:
    for line in f:
        if line in h:
            h[line] += 1
        else:
            h[line] = 1
print h
