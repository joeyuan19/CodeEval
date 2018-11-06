import sys

class Node:
    def __init__(self,value,parent,children=[]):
        self.value = value
        self.parent = parent
        self.children = children
    
    def add(self, entry,l=0):
        print l,children
        r = False
        if entry[0] != self.value[0]:
            f = False
            for child in self.children:
                if entry[0] == child.value[0]:
                    f = True
                elif entry[1][0] == child.value[1][1]:
                    print "adding ", entry, " to ", child.value,"child of",self.value
                    r = r or child.add(entry,l+1)
            if not f:
                self.children.append(Node(entry,self))
                r = True
        return r

    def prnt(self,level=0):
        print self.value
        for child in self.children:
            print " "*level,
            child.prnt(level+1)

def process(line):
    line = line.strip()
    words = [(j,i[0]+i[-1]) for j,i in enumerate(line.split(','))]
    nodes = [Node(i,None) for i in words]
    for word in words:
        try:
            nodes[0].add(word)
        except Exception,e:
            print e
            sys.exit()
    nodes[0].prnt()

if len(sys.argv) < 2:
    fname = 'test.txt'
else:
    fname = sys.argv[1]
with open(fname,'r') as f:
    for line in f:
        process(line)
        break

