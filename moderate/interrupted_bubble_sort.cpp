#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void bubble(vector<int> * v, int iterations) {
    int i, j, tmp;
    bool swap = true;
    for (i = 0; i < iterations; i++) {
        swap = false;
        for (j = 0; j < v->size()-1; j++) {
            if (v->at(j) > v->at(j+1)) {
                tmp = v->at(j);
                v->operator[](j) = v->at(j+1);
                v->operator[](j+1) = tmp;
                swap = true;
            }
        }
        if (!swap) {
            return;
        }
    }
}

void process(string line) {
    vector<int> v;
    int tmp;
    string buf = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            stringstream(buf) >> tmp;
            v.push_back(tmp);
            buf = "";
        } else if (line[i] == '|') {
            stringstream(line.substr(i+2,line.size()-(i+2))) >> tmp;
            bubble(&v,tmp);
            for (tmp = 0; tmp < v.size()-1; tmp++) {
                cout << v.at(tmp) << " ";
            }
            cout << v.at(tmp) << endl;
            return;
        } else {
            buf += line[i];
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        if (line.size() > 0) {
            process(line);
        }
    }
    f.close();
    return 0;
}

