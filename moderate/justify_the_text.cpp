#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    line += " ";
    int idx = line.find(" ");
    string buf = "", next_line = line.substr(0,idx);
    for (int i = idx; i < line.size(); i++) {
        if (line[i] == ' ') {
            if ((next_line+" "+buf).size() > 80) {
                idx = 0;
                while (next_line.size() < 80) {
                    if (next_line[idx] == ' ') {
                        next_line.insert(idx," ");
                        while (next_line[idx] == ' ') {
                            idx = (idx+1)%next_line.size();
                        }
                    } else {
                        idx = (idx+1)%next_line.size();
                    }
                }
                cout << next_line << endl;
                next_line = buf;
            } else {
                next_line += " " + buf;
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    cout << next_line << endl;
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

