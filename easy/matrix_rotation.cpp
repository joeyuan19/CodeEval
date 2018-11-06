#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void process(string line) {
    vector<char> v;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ') {
            v.push_back(line[i]);
        }
    }
    int l = v.size(), s = ((int)sqrt(l));
    int i, j, tmp;
    for (i = 0; i < s; i++) {
        for (j = s-1; j >= 0; j--) {
            cout << v.at(j*s + i);
            if (j > 0 || i < s-1) {
                cout << " ";
            }
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

