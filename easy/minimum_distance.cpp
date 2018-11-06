#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int abs(int n) {
    return n < 0 ? -n : n;
}


void process(string line) {
    line += " ";
    int min = 10001, max = 0, tmp, i;
    string buf = "";
    vector<int> addrs;
    for (i = line.find(' ')+1; i < line.size(); i++) {
        if (line[i] == ' ') {
            stringstream(buf) >> tmp;
            if (tmp > max) {
                max = tmp;
            }
            if (tmp < min) {
                min = tmp;
            }
            addrs.push_back(tmp);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    int j;
    long s = 1000000, d;
    for (i = min; i <= max; i++) {
        d = 0;
        for (j = 0; j < addrs.size(); j++) {
            d += abs(addrs.at(j)-i);
        }
        if (d < s) {
            s = d;
        }
    }
    cout << s << endl;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        process(line);
    }
    f.close();
    return 0;
}

