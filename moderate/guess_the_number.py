import sys
with open(sys.argv[1],'r') as f:
    for line in f:
        tmp = int(line[:line.find(' ')])
        r = [i for i in xrange(0,tmp+1)]
        inx = map(lambda x: x.strip().lower(),line[line.find(' ')+1:].split(' '))
        for i in inx:
            if i == 'lower':
                r = r[:len(r)/2]
            elif i == 'higher':
                r = r[len(r)/2:]
            elif i == 'yay!':
                print r[len(r)/2]+1
        
