#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void process(string line) {
    cout << line << endl;
    int idx = line.find(";");
    double pp, ch;
    stringstream(line.substr(0,idx)) >> pp;
    stringstream(line.substr(idx+1,line.size()-(idx+1))) >> ch;
    int p = (int)(pp*100);
    int c = (int)(ch*100);
    cout << (c-p) << endl;
    if (c < p) {
        cout << "ERROR" << endl;
    } else if (c == p) {
        cout << "ZERO" << endl;
    } else {
        string out = "";
        int i;
        c = c-p;
        for (i = 0; i < c/10000; i++) {
            out += "ONE HUNDRED,";
        }
        c = c%10000;
        for (i = 0; i < c/5000; i++) {
            out += "FIFTY,";
        }
        c = c%5000;
        for (i = 0; i < c/2000; i++) {
            out += "TWENTY,";
        }
        c = c%2000;
        for (i = 0; i < c/1000; i++) {
            out += "TEN,";
        }
        c = c%1000;
        for (i = 0; i < c/500; i++) {
            out += "FIVE,";
        }
        c = c%500;
        for (i = 0; i < c/200; i++) {
            out += "TWO,";
        }
        c = c%200;
        for (i = 0; i < c/100; i++) {
            out += "ONE,";
        }
        c = c%100;
        for (i = 0; i < c/50; i++) {
            out += "HALF DOLLAR,";
        }
        c = c%50;
        for (i = 0; i < c/25; i++) {
            out += "QUARTER,";
        }
        c = c%25;
        for (i = 0; i < c/10; i++) {
            out += "DIME,";
        }
        c = c%10;
        for (i = 0; i < c/5; i++) {
            out += "NICKEL,";
        }
        c = c%5;
        for (i = 0; i < c; i++) {
            out += "PENNY,";
        }
        cout << out.substr(0,out.size()-1) << endl;
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
