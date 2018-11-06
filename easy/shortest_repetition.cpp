#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    int p, i, j;
    string pat;
    for (p = 1; p <= line.size(); p++) {
        pat = line.substr(0,p);
        if (line.size()%p == 0) {
            for (i = 0; i < line.size()/p; i++) {
                if (pat.compare(line.substr(i*p,p)) != 0) {
                    break;
                }
            }
            if (i == line.size()/p) {
                cout << p << endl;
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

