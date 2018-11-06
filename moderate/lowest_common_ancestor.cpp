#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int LCA(int a, int b) {
    if (a == b) {
        return a;
    } else if (a == 30 || b == 30) {
        return 30;
    } else if (a == 52 || b == 52) {
        return 30;
    } else if (a == 8 || b == 8) {
        return 8;
    } else if (a == 3 || b == 3) {
        return 8;
    } else {
        return 20;
    }
}

void process(string line) {
    string buf = "";
    line += " ";
    int a = -1, b = -1;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            if (a >= 0) {
                stringstream(buf) >> b;
            } else {
                stringstream(buf) >> a;
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    cout << LCA(a,b) << endl;
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

