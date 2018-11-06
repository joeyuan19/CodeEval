#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void sort(vector<string> * v) {
    bool swap = true;
    int i;
    string tmp;
    while (swap) {
        swap = false;
        for (i = 0; i < v->size()-1; i++) {
            if (v->at(i).size() < v->at(i+1).size()) {
                tmp = v->at(i);
                v->operator[](i) = v->at(i+1);
                v->operator[](i+1) = tmp;
                swap = true;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    vector<string> lines;
    bool first = true;
    int n_lines;
    while (getline(f,line)) {
        if (first) {
            stringstream(line) >> n_lines;
            first = !first;
        } else {
            lines.push_back(line);
        }
    }
    f.close();
    sort(&lines);
    for (int i = 0; i < n_lines; i++) {
        cout << lines.at(i) << endl;
    }
    return 0;
}
