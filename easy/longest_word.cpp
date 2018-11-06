#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    string buf = "", word;
    int m = 0;
    for (int i = 0; i <= line.size(); i++) {
        if ((i == line.size() || line[i] == ' ') && buf.size() > 0) {
            if (buf.size() > m) {
                m = buf.size();
                word = buf;
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    cout << word << endl;
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

