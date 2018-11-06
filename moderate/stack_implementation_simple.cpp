#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    line = " " + line;
    string buf = "", out = "";
    int c = 0;
    for (int i = line.size()-1; i >= 0; i--) {
        if (line[i] == ' ') {
            if (c%2 == 0) {
                out += " " + buf;
            }
            c++;
            buf = "";
        } else {
            buf = line[i] + buf;
        }
    }
    cout << out.substr(1,out.size()-1) << endl;
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

