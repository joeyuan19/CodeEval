#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int abs(int n) {
    return (n < 0 ? -n : n);
}

void process(string line) {
    line += " ";
    vector<int> seq;
    string buf = "";
    int tmp, i;
    int idx = line.find(" ");
    int n;
    stringstream(line.substr(0,idx)) >> n;
    for (i = idx+1; i < line.size(); i++) {
        if (line[i] == ' ') {
            stringstream(buf) >> tmp;
            seq.push_back(tmp);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    int c [n-1];
    for (i = 0; i < n-1; i++) {
        c[i] = 0;
    }
    for (i = 0; i < n-1; i++) {
        tmp = abs(seq[i]-seq[i+1]);
        if (tmp < 1 || tmp > n-1) {
            cout << "Not jolly" << endl;
            return;
        }
        c[tmp-1]++;
    }
    for (i = 0; i < n-1; i++) {
        if (c[i] != 1) {
            cout << "Not jolly" << endl;
            return;
        }
    }
    cout << "Jolly" << endl;
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


