#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool pointInRect(int x, int y, int x1, int y1, int x2, int y2) {
    return x >= x1 && x <= x2 && y >= y2 && y <= y1;
}

void process(string line) {
    int d [8];
    int tmp, c = 0;
    line += ",";
    string buf = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            stringstream(buf) >> tmp;
            d[c] = tmp;
            c++;
            buf = "";
        } else {
            buf += line[i];
        }
    }
    if (pointInRect(d[0],d[1],d[4],d[5],d[6],d[7]) ||
        pointInRect(d[2],d[1],d[4],d[5],d[6],d[7]) ||
        pointInRect(d[0],d[3],d[4],d[5],d[6],d[7]) ||
        pointInRect(d[2],d[3],d[4],d[5],d[6],d[7]) ||
        pointInRect(d[4],d[5],d[0],d[1],d[2],d[3]) ||
        pointInRect(d[4],d[7],d[0],d[1],d[2],d[3]) ||
        pointInRect(d[6],d[5],d[0],d[1],d[2],d[3]) ||
        pointInRect(d[6],d[7],d[0],d[1],d[2],d[3])) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
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

