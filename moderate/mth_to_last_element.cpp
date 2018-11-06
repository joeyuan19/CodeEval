#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void process(string line) {
    line = " " + line;
    int idx = -1, c = 0;
    string buf = "";
    for (int i = line.size()-1; i >= 0; i--) {
        if (line[i] == ' ') {
            if (idx < 0) {
                stringstream(buf) >> idx;
            } else {
                c++;
                if (c == idx) {
                    cout << buf << endl;
                    return;
                }
            }
            buf = "";
        } else {
            buf = line[i] + buf;
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

