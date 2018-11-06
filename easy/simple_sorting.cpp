#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void process(string s) {
    string buf = "";
    double tmp;
    vector<double> v;
    vector<string> w;
    int i;
    for (i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            stringstream(buf) >> tmp;
            v.push_back(tmp);
            w.push_back(buf);
            buf = "";
        } else {
            buf += s[i];
        }
    }
    bool swap = true;
    string stmp;
    while (swap) {
        swap = false;
        for (i = 0; i < v.size()-1; i++) {
            if (v.at(i) > v.at(i+1)) {
                tmp = v.at(i);
                v[i] = v.at(i+1);
                v[i+1] = tmp;
                stmp = w.at(i);
                w[i] = w.at(i+1);
                w[i+1] = stmp;
                swap = true;
            }
        }
    }
    for (i = 0; i < w.size(); i++ ) {
        cout << w.at(i);
        if (i != w.size()-1) {
            cout << " ";
        }
    }
    cout << endl;
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

