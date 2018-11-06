#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void process(string line) {
    if (line.size() > 0) {
        string code, key, buf = "";
        int idx = line.rfind("|"), i;
        code = line.substr(0,idx);
        key = line.substr(idx+1,line.size()-(idx+1));
        for (i = 0; i <= key.size(); i++) {
            if ((i == key.size() || key[i] == ' ') && buf.size() > 0) {
                stringstream(buf) >> idx;
                cout << code[idx-1];
                buf = "";
            } else {
                buf += key[i];
            }
        }
        cout << endl;
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
