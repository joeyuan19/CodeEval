import sys
import re

def process(line):
    nums = sorted([int(i) for i in re.findall(r',(\d*);',line)])
    l = 0
    out = ""
    for i in nums:
        out += str(i-l)+","
        l = i
    print out[:-1]
        

with open(sys.argv[1],'r') as f:
    for line in f:
        process(line)


