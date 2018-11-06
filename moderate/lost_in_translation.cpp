#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char trans(char c) {
    switch (c) {
        case 'c':
            return 'e';
        case 'r':
            return 't';
        case 'y':
            return 'a';
        case 'e':
            return 'o';
        case 'k':
            return 'i';
        case 's':
            return 'n';
        case 'd':
            return 's';
        case 'b':
            return 'h';
        case ' ':
            return ' ';
        case 'p':
            return 'r';
        case 'i':
            return 'd';
        case 'm':
            return 'l';
        case 'f':
            return 'c';
        case 'j':
            return 'u';
        case 'x':
            return 'm';
        case 't':
            return 'w';
        case 'w':
            return 'f';
        case 'l':
            return 'g';
        case 'a':
            return 'y';
        case 'v':
            return 'p';
        case 'n':
            return 'b';
        case 'g':
            return 'v';
        case 'o':
            return 'k';
        case 'u':
            return 'j';
        case 'h':
            return 'x';
        case 'z':
            return 'q';
        case 'q':
            return 'z';
        default:
            return c;
    }
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line, text = "";
    int i;
    while (getline(f,line)) {
        for (i = 0; i < line.size(); i++) {
            cout << trans(line[i]);
        }
    } cout << endl;
    f.close();
    return 0;
}

