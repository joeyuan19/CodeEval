#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int abs(int n) {
    return n < 0 ? -n : n;
}

string pad(int n) {
    string tmp = "";
    tmp += ((char)('0'+n/10));
    tmp += ((char)('0'+n%10));
    return tmp;
}

void process(string line) {
    line += " ";
    int h1 = -1, m1 = -1, s1 = -1, h2 = -1, m2 = -1, s2 = -1;
    string buf = "";
    bool first = true;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ':' || line[i] == ' ') {
            if (first) {
                if (h1 < 0) {
                    stringstream(buf) >> h1;
                } else if (m1 < 0) {
                    stringstream(buf) >> m1;
                } else if (s1 < 0) {
                    stringstream(buf) >> s1;
                }
                buf = "";
            } else {
                if (h2 < 0) {
                    stringstream(buf) >> h2;
                } else if (m2 < 0) {
                    stringstream(buf) >> m2;
                } else if (s2 < 0) {
                    stringstream(buf) >> s2;
                }
                buf = "";
            }
            if (line[i] == ' ') {
                first = false;
            }
        } else {
            buf += line[i];
        }
    }
    int t1 = h1*60*60 + m1*60 + s1;
    int t2 = h2*60*60 + m2*60 + s2;
    int d = abs(t2-t1);
    cout << pad(d/(60*60)) << ":";
    d = d%(60*60);
    cout << pad(d/60) << ":";
    d = d%(60);
    cout << pad(d) << endl;
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

