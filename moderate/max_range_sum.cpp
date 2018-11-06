#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void process(string line) {
    line += " ";
    int N;
    int idx = line.find(";");
    stringstream(line.substr(0,idx)) >> N;
    string buf = "";
    vector<int> v;
    int i, tmp, j;
    for (i = idx+1; i < line.size(); i++) {
        if (line[i] == ' ') {
            stringstream(buf) >> tmp;
            v.push_back(tmp);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    int s, m = 0;
    for (i = 0; i < v.size()+1-N; i++) {
        s = 0;
        for (j = i; j < i+N; j++) {
            s += v.at(j);
        }
        if (s > m) {
            m = s;
        }
    }
    cout << m << endl;
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

