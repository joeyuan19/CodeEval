#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void process(string line) {
    vector<int> bats;
    int i, itr = 0, d, tmp;
    line += " ";
    string buf = "";
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            stringstream(buf) >> tmp;
            if (itr == 0) {
                if (tmp >= 12) {
                    bats.push_back(6);
                    bats.push_back(tmp-6);
                } else {
                    cout << 0 << endl;
                    return;
                }
            } else if (itr == 1) {
                d = tmp;
                if (bats.at(bats.size()-1) == 6) {
                    cout << (1-d) << endl;
                    return;
                }
            } else if (itr == 2) {
                if (tmp == 0) {
                    tmp = bats.at(1)-bats.at(0);
                    cout << (1+tmp/d) << endl;
                    return;
                }
            } else {
                bats.insert(bats.end()-1,tmp);
            }
            itr++;
            buf = "";
        } else {
            buf += line[i];
        }
    }
    int c = 0;
    itr = bats.at(0);
    for (i = 1; i < bats.size(); i++) {
        while (itr+d <= bats.at(i) || (i == bats.size()-1 && itr <= bats.at(i))) {
            c++;
            itr += d;
        }
        itr = bats.at(i) + d;
    }
    cout << c << endl;
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

