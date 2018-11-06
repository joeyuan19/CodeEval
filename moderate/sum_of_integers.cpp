#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void process(string line) {
    line += ",";
    string buf = "";
    long tmp;
    int i, j, k;
    vector<long> v;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            stringstream(buf) >> tmp;
            v.push_back(tmp);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    long m = v.at(0), s = 0;
    for (i = 0; i < v.size(); i++) {
        s = 0;
        for (j = i; j < v.size(); j++) {
            s += v.at(j);
            if (s > m) {
                m = s;
            }
        }
    }
    cout << m << endl;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    int a = 0;
    while (getline(f,line)) {
        if (line.size() > 0) {
            process(line);
        } else {
            cout << 0 << endl;
        }
    }
    f.close();
    return 0;
}
