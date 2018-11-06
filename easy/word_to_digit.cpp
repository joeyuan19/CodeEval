#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char fromWord(string word) {
    if (word.compare("zero") == 0) {
        return '0';
    }
    if (word.compare("one") == 0) {
        return '1';
    }
    if (word.compare("two") == 0) {
        return '2';
    }
    if (word.compare("three") == 0) {
        return '3';
    }
    if (word.compare("four") == 0) {
        return '4';
    }
    if (word.compare("five") == 0) {
        return '5';
    }
    if (word.compare("six") == 0) {
        return '6';
    }
    if (word.compare("seven") == 0) {
        return '7';
    }
    if (word.compare("eight") == 0) {
        return '8';
    }
    if (word.compare("nine") == 0) {
        return '9';
    }
}

void process(string line) {
    int idx = 0, last = 0;
    int i = 0;
    string buf = "";
    for (i = 0; i <= line.size(); i++) {
        if ((i == line.size() || line[i] == ';') && buf.size() > 0) {
            cout << fromWord(buf);
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

