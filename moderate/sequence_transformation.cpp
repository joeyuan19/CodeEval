#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int bSections(string s) {
    char c = s[0];
    int b = 0;
    if (c == 'B') {
        b++;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != c) {
            c = s[i];
            if (c == 'B') {
                b++;
            }
        }
    }
    return b;
}

int oneSections(string s) {
    char c = s[0];
    int o = 0;
    if (c == '1') {
        o++;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != c) {
            c = s[i];
            if (c == '1') {
                o++;
            }
        }
    }
    return o;
}

int sections(string s) {
    char c = s[0];
    int f = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != c) {
            c = s[i];
            f++;
        }
    }
    return f;
}

bool fits(char p, string m) {
    if (p == '0') {
        return m.find_first_not_of('A') == -1;
    } else {
        return m.find_first_not_of(m[0]) == -1;
    }
    return true;
}

bool fits(string pattern, string line, int level = 0) {
    if (pattern.size() == 0 && line.size() == 0) {
        return true;
    } else if (pattern.size() == 0 || line.size() == 0 ||
            pattern.size() > line.size()  ||
            sections(line) > sections(pattern) ||
            bSections(line) > oneSections(pattern)) {
        return false;
    } else {
        for (int i = 0; i < line.size() && line[0] == line[i]; i++) {
            if (fits(pattern[0],line.substr(0,i+1)) && fits(pattern.substr(1),line.substr(i+1),level+1)) {
                return true;
            }
        }
        return false;
    }
}

void process(string line) {
    int idx = line.find(" "), end;
    string pattern = line.substr(0,idx);
    if ((line.front() == 'B' && pattern.front() == '0') || (line.back() == 'B' && pattern.back() == '0')) {
        cout << "No" << endl;
        return;
    }
    line = line.substr(idx+1);
    if (fits(pattern,line)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    int i;
    while (getline(f,line)) {
        if (line.size() > 290) {
            cout << "skip" << endl;
            continue;
        }
        i++;
        //cout << i << " " << line.size() << endl;
        process(line);
    }
    f.close();
    return 0;
}

