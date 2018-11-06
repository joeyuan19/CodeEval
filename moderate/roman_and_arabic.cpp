#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int roman(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
}

void process(string line) {
    int last = 0, s = 0, r, a;
    for (int i = line.size()-1; i >= 0; i -= 2) {
        r = roman(line[i]);
        a = ((int)(line[i-1]-'0'));
        if (r < last) {
            s += -r*a;
        } else {
            s += r*a;
        }
        last = r;
    }
    cout << s << endl;
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

