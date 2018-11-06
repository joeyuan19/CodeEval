#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string getDigit(char n, bool hasDec) {
    string out = "0000000";
    switch (n) {
        case '0':
            out = "1111110";
            break;
        case '1':
            out = "0110000";
            break;
        case '2':
            out = "1101101";
            break;
        case '3':
            out = "1111001";
            break;
        case '4':
            out = "0110011";
            break;
        case '5':
            out = "1011011";
            break;
        case '6':
            out = "1011111";
            break;
        case '7':
            out = "1110000";
            break;
        case '8':
            out = "1111111";
            break;
        case '9':
            out = "1111011";
            break;
        case '.':
            return "00000001";
        default:
            out = "0000000";
    }
    return out + (hasDec ? '1' : '0');
}

bool canDisplay(string n, string display) {
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == '1' && display[i] != '1') {
            return false;
        }
    }
    return true;
}

void process(string line) {
    vector<string> digits;
    string buf = "", tmp;
    int itr, i, j;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ';' || line[i] == ' ') {
            digits.push_back(buf);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    bool good = false;
    for (itr = 0; itr < digits.size()-(buf.size()-2); itr++) {
        good = true;
        for (i = 0, j = 0; i < buf.size(); i++, j++) {
            if (i < buf.size()-1 && buf[i+1] == '.') {
                tmp = getDigit(buf[i],true);
                i++;
            } else {
                tmp = getDigit(buf[i],false);
            }
            if (!canDisplay(tmp,digits[itr+j])) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << 1 << endl;
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

