#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char capitalize(char c) {
    if (c >= 'a' && c <= 'z') {
        return 'A'+c-'a';
    } else {
        return c;
    }
}

string capitalize(string s) {
    return capitalize(s[0])+s.substr(1,s.size()-1);
}

void process(string line) {
    string buf = "";
    for (int i = 0; i <= line.size(); i++) {
        if (line.size() == i) {
            cout << capitalize(buf);
            buf = "";
        } else if (line[i] == ' ') {
            buf += line[i];
            cout << capitalize(buf);
            buf = "";
        } else {
            buf += line[i];
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

