#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void getIndex(string line, int idx2[]) {
    int idx [line.size()];
    int i, tmpIdx;
    for (i = 0; i < line.size(); i++) {
        idx[i] = i;
    }
    char tmp;
    string tmpString = line;
    bool swap = true;
    while (swap) {
        swap = false;
        for (i = 0; i < tmpString.size()-1; i++) {
            if (tmpString[i] > tmpString[i+1]) {
                tmp = tmpString[i];
                tmpString[i] = tmpString[i+1];
                tmpString[i+1] = tmp;
                tmpIdx = idx[i];
                idx[i] = idx[i+1];
                idx[i+1] = tmpIdx;
                swap = true;
            }
        }
    }
    int j;
    for (i = 0; i < line.size(); i++) {
        for (j = 0; j < line.size(); j++) {
            if (i == idx[j]) {
                idx2[i] = j;
                break;
            }
        }
    }
}

void process(string line) {
    line = line.substr(0,line.size()-1);
    int itr = line.find("$");
    string out = "";
    out += line[itr];
    int idx [line.size()];
    getIndex(line,idx);
    while (out.size() < line.size()) {
        itr = idx[itr];
        out = line[itr] + out;
    }
    cout << out << endl;
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

