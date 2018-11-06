import sys
def process(line):
    L = line.count(",")
    d = {}
    for el in line.split(","):
        if el not in d:
            d[el] = 1
        else:
            d[el] += 1
            if d[el] >= L:
                print el
                return
    out = ""
    for e,v in d.iteritems():
        if v >= len(d)/2:
            print e
            return
    print "None"

with open(sys.argv[1],'r') as f:
    for line in f:
        process(line)
