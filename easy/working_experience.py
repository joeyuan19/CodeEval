import sys, re, datetime

def _coalesce(dates):
    _dates = []
    for i in xrange(len(dates)):
        added = False
        for j in xrange(len(_dates)):
            if _dates[j][0] > dates[i][1] or _dates[j][1] < dates[i][0]:
                pass
            else:
                if _dates[j][0] <= dates[i][0] <= _dates[j][1]:
                    if dates[i][1] > _dates[j][1]:
                        _dates[j][1] = dates[i][1]
                    added = True
                elif _dates[j][0] <= dates[i][1] <= _dates[j][1]:
                    if dates[i][0] < _dates[j][0]:
                        _dates[j][0] = dates[i][0]
                    added = True
                elif _dates[j][0] < dates[i][0] and _dates[j][1] > dates[i][1]:
                    added = True
                elif _dates[j][0] > dates[i][0] and _dates[j][1] < dates[i][1]:
                    _dates[j] = dates[i]
        if not added:
            _dates.append(dates[i])
    return _dates
            
    
def coalesce(dates):
    l = 0
    while l != len(dates):
        l = len(dates)
        dates = _coalesce(dates)
    return dates

def process(line):
    dates = re.findall(r'(\w{3} \d{4})-(\w{3} \d{4})',line)
    dates = [[datetime.datetime.strptime(i,"%b %Y") for i in date] for date in dates]
    odates = dates
    for i in xrange(len(dates)):
        if dates[i][1].month == 12:
            dates[i][1] = dates[i][1].replace(day=31)
        else:
            dates[i][1] = dates[i][1].replace(month=dates[i][1].month + 1)
            dates[i][1] = dates[i][1] - datetime.timedelta(days=1)
    dates = coalesce(dates)
    exp = datetime.datetime(1,1,1)
    for date in dates:
        exp += date[1]-date[0]
    print (exp-datetime.datetime(1,1,1)

with open(sys.argv[1],'r') as f:
    for line in f:
        process(line)


