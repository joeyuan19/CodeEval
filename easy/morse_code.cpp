#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

char morseCode(string s) {
    if (s.compare(".-") == 0) {
        return 'A';
    } else if (s.compare("-...") == 0) {
        return 'B';
    } else if (s.compare("-.-.") == 0) {
        return 'C';
    } else if (s.compare("-..") == 0) {
        return 'D';
    } else if (s.compare(".") == 0) {
        return 'E';
    } else if (s.compare("..-.") == 0) {
        return 'F';
    } else if (s.compare("--.") == 0) {
        return 'G';
    } else if (s.compare("....") == 0) {
        return 'H';
    } else if (s.compare("..") == 0) {
        return 'I';
    } else if (s.compare(".---") == 0) {
        return 'J';
    } else if (s.compare("-.-") == 0) {
        return 'K';
    } else if (s.compare(".-..") == 0) {
        return 'L';
    } else if (s.compare("--") == 0) {
        return 'M';
    } else if (s.compare("-.") == 0) {
        return 'N';
    } else if (s.compare("---") == 0) {
        return 'O';
    } else if (s.compare(".--.") == 0) {
        return 'P';
    } else if (s.compare("--.-") == 0) {
        return 'Q';
    } else if (s.compare(".-.") == 0) {
        return 'R';
    } else if (s.compare("...") == 0) {
        return 'S';
    } else if (s.compare("-") == 0) {
        return 'T';
    } else if (s.compare("..-") == 0) {
        return 'U';
    } else if (s.compare("...-") == 0) {
        return 'V';
    } else if (s.compare(".--") == 0) {
        return 'W';
    } else if (s.compare("-..-") == 0) {
        return 'X';
    } else if (s.compare("-.--") == 0) {
        return 'Y';
    } else if (s.compare("--..") == 0) {
        return 'Z';
    } else if (s.compare("-----") == 0) {
        return '0';
    } else if (s.compare(".----") == 0) {
        return '1';
    } else if (s.compare("..---") == 0) {
        return '2';
    } else if (s.compare("...--") == 0) {
        return '3';
    } else if (s.compare("....-") == 0) {
        return '4';
    } else if (s.compare(".....") == 0) {
        return '5';
    } else if (s.compare("-....") == 0) {
        return '6';
    } else if (s.compare("--...") == 0) {
        return '7';
    } else if (s.compare("---..") == 0) {
        return '8';
    } else if (s.compare("----.") == 0) {
        return '9';
    } else {
        return '*';
    }
}

void process(string line) {
    string buf = "", out = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            if (i+1 < line.size() && line[i+1] == ' ') {
                if (buf.size() > 0) {
                    out += morseCode(buf);
                }
                out += " ";
                i++;
            } else {
                out += morseCode(buf);
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    if (buf.size() > 0) {
        out += morseCode(buf);
    }
    cout << out << endl;
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

