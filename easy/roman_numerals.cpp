#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string intToRoman(int n) {
    int tmp = n;
    string s = "";
    while (tmp > 0) {
        if (tmp >= 3000) {
            s += "MMM";
            tmp -= 3000;
        } else if (tmp >= 2000) {
            s += "MM";
            tmp -= 2000;
        } else if (tmp >= 1000) {
            s += "M";
            tmp -= 1000;
        } else if (tmp >= 900) {
            s += "CM";
            tmp -= 900;
        } else if (tmp >= 500) {
            s += "D";
            tmp -= 500;
        } else if (tmp >= 400) {
            s += "CD";
            tmp -= 400;
        } else if (tmp >= 300) {
            s += "CCC";
            tmp -= 300;
        } else if (tmp >= 200) {
            s += "CC";
            tmp -= 200;
        } else if (tmp >= 100) {
            s += "C";
            tmp -= 100;
        } else if (tmp >= 90) {
            s += "XC";
            tmp -= 90;
        } else if (tmp >= 50) {
            s += "L";
            tmp -= 50;
        } else if (tmp >= 40) {
            s += "XL";
            tmp -= 40;
        } else if (tmp >= 30) {
            s += "XXX";
            tmp -= 30;
        } else if (tmp >= 20) {
            s += "XX";
            tmp -= 20;
        } else if (tmp >= 10) {
            s += "X";
            tmp -= 10;
        } else if (tmp >= 9) {
            s += "IX";
            tmp -= 9;
        } else if (tmp >= 5) {
            s += "V";
            tmp -= 5;
        } else if (tmp >= 4) {
            s += "IV";
            tmp -= 4;
        } else if (tmp >= 3) {
            s += "III";
            tmp -= 3;
        } else if (tmp >= 2) {
            s += "II";
            tmp -= 2;
        } else if (tmp >= 1) {
            s += "I";
            tmp -= 1;
        }
    }
    return s;
}


void process(string line) {
    int tmp;
    stringstream(line) >> tmp;
    cout << intToRoman(tmp) << endl;
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

