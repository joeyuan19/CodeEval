import sys
import json

with open(sys.argv[1],'r') as f:
    for line in f:
        if len(line.strip()) == 0:
            continue
        _json = json.loads(line)
        s = 0
        for item in _json["menu"]["items"]:
            if item is not None and "label" in item:
                s += item["id"]
        print s
