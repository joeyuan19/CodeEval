#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int LIMIT = 256;

void setRow(int x[LIMIT][LIMIT], int row, int val) {
    for (int i = 0; i < LIMIT; i++) {
        x[row][i] = val;
    }
}

void setCol(int x[LIMIT][LIMIT], int col, int val) {
    for (int i = 0; i < LIMIT; i++) {
        x[i][col] = val;
    }
}

int queryRow(int x[LIMIT][LIMIT], int row) {
    int a = 0;
    for (int i = 0; i < LIMIT; i++) {
        a += x[row][i];
    }
    return a;
}

int queryCol(int x[LIMIT][LIMIT], int col) {
    int a = 0;
    for (int i = 0; i < LIMIT; i++) {
        a += x[i][col];
    }
    return a;
}

void process(int m[LIMIT][LIMIT], string line) {
    string buf = "";
    int i;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            break;
        }
        buf += line[i];
    }
    if (buf.compare("SetCol") == 0) {
        int a, b;
        buf = "";
        for (i = i+1; i < line.size(); i++) {
            if (line[i] == ' ') {
                stringstream(buf) >> a;
                buf = "";
            }
            buf += line[i];
        }
        stringstream(buf) >> b;
        setCol(m,a,b);
    } else if (buf.compare("SetRow") == 0) {
        int a, b;
        buf = "";
        for (i = i+1; i < line.size(); i++) {
            if (line[i] == ' ') {
                stringstream(buf) >> a;
                buf = "";
            }
            buf += line[i];
        }
        stringstream(buf) >> b;
        setRow(m,a,b);
    } else if (buf.compare("QueryRow") == 0) {
        int a;
        stringstream(line.substr(i+1,line.size()-(i+1))) >> a;
        cout << queryRow(m,a) << endl;
    } else if (buf.compare("QueryCol") == 0) {
        int a;
        stringstream(line.substr(i+1,line.size()-(i+1))) >> a;
        cout << queryCol(m,a) << endl;
    }
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    int m [LIMIT][LIMIT];
    int i, j;
    for (i = 0; i < LIMIT; i++) {
        for (j = 0; j < LIMIT; j++) {
            m[i][j] = 0;
        }
    }
    while (getline(f,line)) {
        process(m,line);
    }
    f.close();
    return 0;
}

