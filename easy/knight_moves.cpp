#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int fromLetter(char c) {
    return ((int)(c-'a'));
}

char toLetter(int n) {
    return ((char)('a'+n));
}

int fromNumber(char c) {
    return ((int)(c-'1'));
}

char toNumber(int n) {
    return ((char)('1'+n));
}

void process(string line) {
    vector<string> moves;
    string tmp = "";
    int c = fromLetter(line[0]);
    int r = fromNumber(line[1]);
    if (c-2 >= 0 && r-1 >= 0) {
        tmp = "";
        tmp += toLetter(c-2);
        tmp += toNumber(r-1);
        moves.push_back(tmp);
    }
    if (c-2 >= 0 && r+1 < 8) {
        tmp = "";
        tmp += toLetter(c-2);
        tmp += toNumber(r+1);
        moves.push_back(tmp);
    }
    if (c-1 >= 0 && r-2 >= 0) {
        tmp = "";
        tmp += toLetter(c-1);
        tmp += toNumber(r-2);
        moves.push_back(tmp);
    }
    if (c-1 >= 0 && r+2 < 8) {
        tmp = "";
        tmp += toLetter(c-1);
        tmp += toNumber(r+2);
        moves.push_back(tmp);
    }
    if (c+1 < 8 && r-2 >= 0) {
        tmp = "";
        tmp += toLetter(c+1);
        tmp += toNumber(r-2);
        moves.push_back(tmp);
    }
    if (c+1 < 8 && r+2 < 8) {
        tmp = "";
        tmp += toLetter(c+1);
        tmp += toNumber(r+2);
        moves.push_back(tmp);
    }
    if (c+2 < 8 && r-1 >= 0) {
        tmp = "";
        tmp += toLetter(c+2);
        tmp += toNumber(r-1);
        moves.push_back(tmp);
    }
    if (c+2 < 8 && r+1 < 8) {
        tmp = "";
        tmp += toLetter(c+2);
        tmp += toNumber(r+1);
        moves.push_back(tmp);
    }
    for (int i = 0; i < moves.size()-1; i++) {
        cout << moves.at(i) << " ";
    }
    cout << moves.at(moves.size()-1) << endl;
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
