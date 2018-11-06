from sys import argv
import re

def process(line):
    pattern,line = line.split(' ')
    regex = r'^'
    for i in pattern:
        if i == '0':
            regex += r'[A]+'
        elif i == '1':
            regex += r'([A]+|[B]+)'
    regex += r'$'
    if len(re.findall(regex,line)) > 0:
        print 'Yes'
    else:
        print 'No'

with open(argv[1],'r') as f:
    for line in f:
        process(line)
