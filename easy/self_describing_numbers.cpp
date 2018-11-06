#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ctoi(char c) {
    return (int)(c-'0');
}

int processLine(string line) {
    int i, j, c;
    for (i = 0; i < line.size(); i++) {
        c = 0;
        for (j = 0; j < line.size(); j++) {
            if (ctoi(line[j]) == i) {
                c++;
            }
        }
        if (c != ctoi(line[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        cout << processLine(line) << endl;
    }
    f.close();
    return 0;
}
