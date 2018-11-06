import sys

REG = [
    ['ONE HUNDRED', 100.00],
    ['FIFTY', 50.00],
    ['TWENTY', 20.00],
    ['TEN', 10.00],
    ['FIVE', 5.00],
    ['TWO', 2.00],
    ['ONE', 1.00],
    ['HALF DOLLAR', .50],
    ['QUARTER', .25],
    ['DIME', .10],
    ['NICKEL', .05],
    ['PENNY', .01],
]

for i in xrange(len(REG)):
    REG[i][1] = int(100*REG[i][1])

def process(line):
    pp,ch = map(lambda x: int(100*x),map(float,line.split(';')))
    if ch < pp:
        print "ERROR"
    elif ch > pp:
        ch = ch-pp
        out = ''
        for it in REG:
            k,v = it
            out += (k+",")*(ch/v)
            ch = ch%v
        print out[:-1]
    else:
        print "ZERO"
        

with open(sys.argv[1],'r') as f:
    for line in f:
        process(line)
