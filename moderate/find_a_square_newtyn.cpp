#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void process(string line) {
    line += ",";
    string buf = "";
    int p1x, p2x, p3x, p4x;
    int p1y, p2y, p3y, p4y;
    int i, itr = 0, tmp;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            stringstream(buf) >> tmp;
            if (itr == 0) {
                p1x = tmp;
            } else if (itr == 1) {
                p1y = tmp;
            } else if (itr == 2) {
                p2x = tmp;
            } else if (itr == 3) {
                p2y = tmp;
            } else if (itr == 4) {
                p3x = tmp;
            } else if (itr == 5) {
                p3y = tmp;
            } else if (itr == 6) {
                p4x = tmp;
            } else if (itr == 7) {
                p4y = tmp;
            }
            itr++;
            buf = "";
        } else if (line[i] >= '0' && line[i] <= '9') {
            buf += line[i];
        }
    }
    if ((p1x == p2x && p1y == p2y) ||
        (p1x == p3x && p1y == p3y) ||
        (p1x == p4x && p1y == p4y) ||
        (p2x == p3x && p2y == p3y) ||
        (p2x == p4x && p2y == p4y) ||
        (p3x == p4x && p3y == p4y)) {
        cout << "false" << endl;
        return;
    }
    int dx, dy;
    int d12, d13, d14;
    dx = p2x - p1x;
    dy = p2y - p1y;
    d12 = dx*dx + dy*dy;
    dx = p3x - p1x;
    dy = p3y - p1y;
    d13 = dx*dx + dy*dy;
    dx = p4x - p1x;
    dy = p4y - p1y;
    d14 = dx*dx + dy*dy;
    if (d12 == d13 && 2*d12 == d14) {
        cout << "true" << endl;
    } else if (d12 == d14 && 2*d12 == d13) {
        cout << "true" << endl;
    } else if (d13 == d14 && 2*d13 == d12) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
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
