// Sample code to read in test cases:
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    char map [50][12];
    int path [50][12];
    int i = 0, j = 0;
    while (getline(stream, line)) {
        for (j = 0; j < line.size(); j++) {
            map[i][j] = line[j];
        }
        i++;
    }
    stream.close();
    for (j = 0; j < 12; j++) {
        if (map[0][j] == '#') {
            path[0][j] = 0;
        } else if (map[0][j] == '_') {
            path[0][j] = 1;
        } else if (map[0][j] == 'C') {
            path[0][j] = 2;
        }
    }
    for (i = 1; i < 50; i++) {
        for (j = 0; j < 12; j++) {
            if (map[i][j] == '#') {
                path[i][j] = 0;
            } else if (map[i][j] == '_') {
                if (j == 0) {
                    path[i][j] = max(path[i-1][j],path[i-1][j+1]) + 1;
                } else if (j == 11) {
                    path[i][j] = max(path[i-1][j-1],path[i-1][j]) + 1;
                } else {
                    path[i][j] = max(path[i-1][j-1],max(path[i-1][j],path[i-1][j+1])) + 1;
                }
            }  else if (map[i][j] == 'C') {
                if (j == 0) {
                    path[i][j] = max(path[i-1][j],path[i-1][j+1]) + 2;
                } else if (j == 11) {
                    path[i][j] = max(path[i-1][j-1],path[i-1][j]) + 2;
                } else {
                    path[i][j] = max(path[i-1][j-1],max(path[i-1][j],path[i-1][j+1])) + 2;
                }
            }
        }
    }
    int m = 0, lj;
    for (j = 0; j < 12; j++) {
        if (path[49][j] > m) {
            m = path[49][j];
            lj = j;
        }
    }
    string out = "";
    line = "";
    for (i = 49; i > 0; i--) {
        line = "";
        for (j = 0; j < 12; j++) {
            if (lj == j) {
                if (j == 0) {
                    if (path[i-1][j] > path[i-1][j+1]) {
                        m = j;
                        line += "|";
                    } else {
                        m = j+1;
                        line += "/";
                    }
                } else if (j == 11) {
                    if (path[i-1][j] > path[i-1][j+1]) {
                        m = j;
                        line += "|";
                    } else {
                        m = j-1;
                        line += "\\";
                    }
                } else {
                    if (path[i-1][j] >= path[i-1][j+1] && path[i-1][j] >= path[i-1][j-1]) {
                        m = j;
                        line += "|";
                    } else if (path[i-1][j+1] >= path[i-1][j] && path[i-1][j+1] >= path[i-1][j-1]) {
                        m = j+1;
                        line += "/";
                    } else if (path[i-1][j-1] >= path[i-1][j] && path[i-1][j-1] >= path[i-1][j+1]) {
                        m = j-1;
                        line += "\\";
                    }
                }
            } else {
                line += map[i][j];
            }
        }
        out = line + "\n" + out;
        lj = m;
    }
    line = "";
    for (j = 0; j < 12; j++) {
        if (j == lj) {
            line += "|";
        } else {
            line += map[i][j];
        }
    }
    out = line + "\n" + out;
    cout << out;
    return 0;
} 
