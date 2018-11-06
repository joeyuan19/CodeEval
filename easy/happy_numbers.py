import sys

REC = {}

def happy(n,path=[]):
    if n in REC:
        return REC[n]
    elif n%10 == 1:
        REC[n] = 1
        return 1
    elif n in path:
        REC[n] = 0
        return 0
    else:
        REC[n] = happy(sum(i*i for i in map(int,str(n))),path+[n])
        return REC[n]

with open(sys.argv[1],'r') as f:
    for line in f:
        print happy(int(line.strip()))
        
