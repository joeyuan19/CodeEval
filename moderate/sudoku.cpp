#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

bool checkRows(vector<vector<int>> puzzle) {
    int i, j, size = puzzle.size();
    int correct [size];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            correct[j] = 0;
        }
        for (j = 0; j < size; j++) {
            correct[puzzle[i][j]-1]++;
        }
        for (j = 0; j < size; j++) {
            if(correct[j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool checkCols(vector<vector<int>> puzzle) {
    int i, j, size = puzzle.size();
    int correct [size];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            correct[j] = 0;
        }
        for (j = 0; j < size; j++) {
            correct[puzzle[j][i]-1]++;
        }
        for (j = 0; j < size; j++) {
            if(correct[j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool checkBoxes(vector<vector<int>> puzzle) {
    int i, j, k;
    int size = puzzle.size();
    int b = size == 9 ? 3 : 2;
    int l, w;
    int correct [puzzle.size()];
    for (l = 0; l < b; l++) {
        for (w = 0; w < b; w++) {
            for (j = 0; j < size; j++) {
                correct[j] = 0;
            }
            for (j = 0; j < b; j++) {
                for (k = 0; k < b; k++) {
                    correct[puzzle[l*b+j][w*b+k]-1]++;
                }
            }
            for (j = 0; j < size; j++) {
                if(correct[j] != 1) {
                    return false;
                }
            }
        }
    }
    return true;
}



void process(string line) {
    line += ",";
    int s, idx = line.find(";"), i, tmp;
    stringstream(line.substr(0,idx)) >> s;
    vector<vector<int>> puzzle;
    for (i = 0; i < s; i++) {
        vector<int> t (s,0);
        puzzle.push_back(t);
    }
    string buf = "";
    for (i = idx+1, idx = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            stringstream(buf) >> tmp;
            puzzle[idx/s][idx%s] = tmp;
            idx++;
            buf = "";
        } else {
            buf += line[i];
        }
    }
    if (checkCols(puzzle) && checkRows(puzzle) && checkBoxes(puzzle)) {
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

