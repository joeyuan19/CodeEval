#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void process(string line) {
    int n [10], i, tmp;
    for (i = 0; i < 10; i++) {
        n[i] = 0;
    }
    string buf = "";
    for (int i = 0; i <= line.size(); i++) {
        if ((i == line.size() || line[i] == ' ') && buf.size() > 0) {
            stringstream(buf) >> tmp;
            n[tmp]++;
            buf = "";
        } else {
            buf += line[i];
        }
    }
    for (i = 1; i < 10; i++) {
        if (n[i] == 1) {
            cout << 1+line.find('0'+i)/2 << endl;
            return;
        }
    }
    cout << 0 << endl;
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

