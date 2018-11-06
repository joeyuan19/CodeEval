#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int ctoi(char c) {
    return ((int)(c-'0'));
}

string process(string line) {
    int tmp, i, c = 0, p = line.size();
    for (i = 0; i < p; i++) {
        c += pow(ctoi(line[i]),p);
    }
    stringstream(line) >> tmp;
    if (c == tmp) {
        return "True";
    } else {
        return "False";
    }
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        cout << process(line) << endl;
    }
    f.close();
    return 0;
}
