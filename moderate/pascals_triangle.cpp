#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string to_string(int n) {
    ostringstream ss;
    ss << n;
    return ss.str();
}

void process(string line) {
    int rows;
    stringstream(line) >> rows;
    vector<int> row (1,1), last (1,1);
    int i, j;
    string out = "";
    for (i = 1; i < rows; i++) {
        for (j = 0; j < row.size(); j++) {
            out += to_string(row[j]) + " ";
        }
        last.swap(row);
        row.clear();
        for (j = 0; j < last.size()-1; j++) {
            row.push_back(last[j]+last[j+1]);
        }
        row.insert(row.begin(),1);
        row.insert(row.end(),1);
    }
    for (j = 0; j < row.size(); j++) {
        out += to_string(row[j]) + " ";
    }
    cout << out.substr(0,out.size()-1) << endl;
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

