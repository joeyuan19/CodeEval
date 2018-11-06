import sys
with open(sys.argv[1],"r") as f:
    for line in f:
        print (' '.join(i for i in line.strip().split(' ')[::-1])).strip()
