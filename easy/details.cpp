#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    line += ",";
    int m = line.size(), c = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            if (c < m) {
                if (m == 0) {
                    cout << m << endl;
                    return;
                }
                m = c;
            }
            c = 0;
        } else if (line[i] == '.') {
            c++;
        } else if (line[i] == 'Y' && line[i-1] == 'X') {
            cout << 0 << endl;
            return;
        }
    }
    cout << m << endl;
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

