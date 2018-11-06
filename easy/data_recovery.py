import sys
with open(sys.argv[1],'r') as f:
    for line in f:
        line = line.strip()
        i = line.rfind(';')
        words,idx = line[:i],line[i+1:]
        words = words.split(' ')
        idx = [int(i) for i in idx.split(' ')]
        out = ""
        for i in xrange(1,len(words)+1):
            if i not in idx:
                idx.append(i)
        print ' '.join(i[1] for i in sorted(zip(idx,words)))
