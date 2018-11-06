#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void process(string line) {
    line += " ";
    vector<int> v;
    int tmp, l, i, j;
    string buf = "";
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            stringstream(buf) >> tmp;
            v.push_back(tmp);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    for (i = 0; i < v.size(); i++) {
        for (l = 1; l <= (v.size()-(i+1))/2; l++) {
            for (j = 0; j < l; j++) {
                if (i+j+l < v.size() && v[i+j] != v[i+l+j]) {
                    break;
                }
            }
            if (j == l) {
                for (j = 0; j < l-1; j++) {
                    cout << v[i+j] << " ";
                }
                cout << v[i+l-1] << endl;
                return;
            }
        }
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

