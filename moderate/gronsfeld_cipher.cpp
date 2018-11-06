#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char decode(char c, int n) {
    string key = " !\"#$%&'()*+,-./0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = key.size()-1; i >= 0; i--) {
        if (key[i] == c) {
            if (i-n < 0) {
                return key[key.size()+(i-n)];
            } else {
                return key[i-n];
            }
        }
    }
    return ';';
}

void process(string line) {
    int idx = line.rfind(";");
    for (int i = idx+1; i < line.size(); i++) {
        cout << decode(line[i],((int)(line[(i-idx-1)%idx]-'0')));
    } cout << endl;
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

