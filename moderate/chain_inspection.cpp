#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


void process(string line) {
    line += ";";
    vector<string> v;
    string buf = "";
    int i;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ';' || line[i] == '-') {
            v.push_back(buf);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    bool c = true;
    int j;
    while (c) {
        c = false;
        i = 0;
        while (i < v.size()) {
            j = i+2;
            while (j < v.size()) {
                if (v.at(i+1).compare(v.at(j)) == 0) {
                    v[i+1] = v.at(j+1);
                    v.erase(v.begin()+j+1);
                    v.erase(v.begin()+j);
                    c = true;
                } else if (v.at(i).compare(v.at(j+1)) == 0) {
                    v[i] = v.at(j);
                    v.erase(v.begin()+j+1);
                    v.erase(v.begin()+j);
                    c = true;
                } else {
                    j += 2;
                }
            }
            i += 2;
        }
    }
    if (v.size() == 2 && v.at(0).compare("BEGIN") == 0 && v.at(1).compare("END") == 0) {
        cout << "GOOD" << endl;
    } else {
        cout << "BAD" << endl;
    }
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

