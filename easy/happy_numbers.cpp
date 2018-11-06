#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

char itoc(int n) {
    return ((char)('0'+n));
}

int ctoi(char c) {
    return ((int)(c-'0'));
}

string toString(int n) {
    int tmp = n;
    string s = "";
    s += itoc(tmp%10);
    tmp = tmp/10;
    while (tmp > 0) {
        s += itoc(tmp%10);
        tmp = tmp/10;
    }
    return s;
}

void process(string line) {
    int tmp, i, itr;
    string stmp = line;
    stringstream(line) >> tmp;
    vector<int> trail;
    while (tmp > 1) {
        tmp = 0;
        for (i = 0; i < stmp.size(); i++) {
            itr = ctoi(stmp[i]);
            tmp += itr*itr;
        }
        for (i = 0; i < trail.size(); i++) {
            if (trail.at(i) == tmp) {
                cout << "0" << endl;
                return; 
            }
        }
        trail.push_back(tmp);
        stmp = toString(tmp);
    }
    cout << "1" << endl;
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

