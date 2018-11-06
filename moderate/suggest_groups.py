from sys import argv

GROUPS = []
NAMES = []
USERS = {}


with open(argv[1],'r') as f:
    for line in f:
        line = line.strip()
        name,friends,groups = line.split(':')
        NAMES.append(name)
        USERS[name] = {'friends':[],'groups':[]}
        for friend in friends.split(','):
            USERS[name]['friends'].append(friend)
        for group in groups.split(','):
            USERS[name]['groups'].append(group)
            if group not in GROUPS:
                GROUPS.append(group)

NAMES = sorted(NAMES)
GROUPS = sorted(GROUPS)

for name in NAMES:
    out = []
    for group in GROUPS:
        if group not in USERS[name]['groups']:
            if float(len([friend for friend in USERS[name]['friends'] if group in USERS[friend]['groups']]))/len(USERS[name]['friends']) >= .5:
                out.append(group)
    if len(out) > 0:
        print name+":"+','.join(i for i in out)
