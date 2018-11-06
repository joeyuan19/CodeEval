from sys import argv
import re
chars = '[a-zA-Z0-9!#\$%\'\*+-/=\?\^_`\{\}\|~]|\\[@ \\]'
dom = 'a-zA-Z0-9-'

em = r'^(".*"|(' + chars + r')+)@['+dom+']+(\.['+dom+']+)+$'


with open(argv[1],'r') as f:
    for line in f:
        print str(len(re.findall(em,line)) == 1).lower()
