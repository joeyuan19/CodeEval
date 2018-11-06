import sys
import re

def format(n):
    s = list(str(n))
    while s[-1] == '0':
        s.pop()
    if s[-1] == '.':
        s.pop()
    return ''.join(s)
        

with open(sys.argv[1],'r') as f:
    for line in f:
        line = line.strip().replace("^","**")
        line = re.sub(r'(^|[^\.0-9])(\d+)([^\.0-9])',r'\1\2.\3',line)i
        n = eval(line)
        print n
        print format(round(n,5))

