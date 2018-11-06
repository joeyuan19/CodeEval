#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void process(string line) {
    vector<int> a, b;
    int tmp;
    bool ab = false;
    string buf = "";
    for (int i = 0; i <= line.size(); i++) {
        if ((i == line.size() || line[i] == ' ') && buf.size() > 0) {
            stringstream(buf) >> tmp;
            if (ab) {
                b.push_back(tmp);
            } else {
                a.push_back(tmp);
            }
            buf = "";
        } else if (line[i] == '|') {
            ab = !ab;
        } else {
            buf += line[i];
        }
    }
    for (int i = 0; i < a.size(); i++) {
        cout << (a.at(i)*b.at(i));
        if (i < a.size()-1) {
            cout << " ";
        }
    }
    cout << endl;
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

