#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void process(string line) {
    line += " ";
    long n = 0, c;
    bool onFlag = true;
    string buf = "", flag = "", count = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            if (onFlag) {
                flag = buf;
            } else {
                count = buf;
            }
            if (flag.size() > 0 && count.size() > 0) {
                if (flag.size() == 2) {
                    for (c = 0; c < count.size(); c++) {
                        n = n*2 + 1;
                    }
                } else {
                    for (c = 0; c < count.size(); c++) {
                        n = n*2;
                    }
                }
                flag = "";
                count = "";
            }
            buf = "";
            onFlag = !onFlag;
        } else {
            buf += line[i];
        }
    }
    cout << n << endl;
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
