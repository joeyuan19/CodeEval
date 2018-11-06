#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void process(string line) {
    int x [11], y [11], i, tmp;
    for (i = 0; i < 11; i++) {
        x[i] = 0;
        y[i] = 0;
    }
    line += ",";
    string buf = "";
    bool xy = true;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            stringstream(buf) >> tmp;
            if (xy) {
                x[tmp]++;
            } else {
                y[tmp]++;
            }
            buf = "";
            xy = !xy;
        } else if (line[i] >= '0' && line[i] <= '9') {
            buf += line[i];
        }
    }
    int c = 0;
    for (i = 0; i < 11; i++) {
        if (x[i] == 2) {
            c++;
        }
    }
    if (c != 2) {
        cout << "false" << endl;
        return;
    }
    c = 0;
    for (i = 0; i < 11; i++) {
        if (y[i] == 2) {
            c++;
        }
    }
    if (c != 2) {
        cout << "false" << endl;
        return;
    }
    cout << "true" << endl;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        process(line);
    }
    stream.close();
    return 0;
}
