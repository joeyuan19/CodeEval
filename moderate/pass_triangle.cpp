#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line, buf = "";
    vector<int> row, last (1,0);
    int tmp, i;
    while (getline(f,line)) {
        line += " ";
        buf = "";
        for (i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                stringstream(buf) >> tmp;
                row.push_back(tmp);
                buf = "";
            } else {
                buf += line[i];
            }
        }
        row[0] += last[0];
        row[row.size()-1] += last[last.size()-1];
        for (i = 1; i < row.size()-1; i++) {
            if (last[i-1] > last[i]) {
                row[i] += last[i-1];
            } else {
                row[i] += last[i];
            }
        }
        last.swap(row);
        row.clear();
    }
    f.close();
    int m = 0;
    for (i = 0; i < last.size(); i++) {
        if (last[i] > m) {
            m = last[i];
        }
    }
    cout << m << endl;
    return 0;
}

