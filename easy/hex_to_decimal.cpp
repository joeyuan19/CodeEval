#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int dec_to_hex(char c) {
    switch (c) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
    }
}

int dec_to_hex(string s) {
    int a = 0;
    int p = 0;
    for (int i = s.size()-1; i >= 0; i--,p++) {
        a += dec_to_hex(s[i])*pow(16,p);
    }
    return a;
}

int process(string line) {
    return dec_to_hex(line);
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        cout << process(line) << endl;
    }
    f.close();
    return 0;
}

