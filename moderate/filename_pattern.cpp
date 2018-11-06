#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool matches(string str, string pattern) {
    bool matched = false;
    int s, p, l;
    for (p = 0, s = 0; p < pattern.size() && s < str.size(); p++) {
        if (pattern[p] == '*') {
            if (p == pattern.size()-1) {
                return true;
            }
            matched = false;
            while (s < str.size()) {
                if (pattern[p+1] == '[') {
                    bool f = false;
                    for (l = 1; pattern[p+1+l] != ']'; l++) {
                        f = f || pattern[p+1+l] == str[s];
                    }
                    if (f && (p+1+l == pattern.size()-1 || matches(str.substr(s+1,str.size()-(s+1)),pattern.substr(p+2+l,pattern.size()-(p+2+l))))) {
                        return true;
                    }
                } else if (pattern[p+1] == str[s] && 
                    (p == pattern.size()-2 || matches(str.substr(s+1,str.size()-(s+1)),pattern.substr(p+2,pattern.size()-(p+2))))) {
                    return true;
                }
                s++;
            }
        } else if (pattern[p] == '?') {
            s++;
        } else if (pattern[p] == '[') {
            matched = false;
            for (l = 1; pattern[p+l] != ']'; l++) {
                matched = matched || pattern[p+l] == str[s];
            }
            if (matched) {
                p += l;
                s++;
            } else {
                return false;
            }
        } else if (pattern[p] == str[s]) {
            s++;
        } else {
            return false;
        }
    }
    return str.size() == s && (pattern.size() == p || (pattern.size()-1 == p && pattern[p] == '*'));
}


void process(string line) {
    line += " ";
    string pattern = "", buf = "";
    int i;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            pattern = buf;
            break;
        } else {
            buf += line[i];
        }
    }
    buf = "";
    string out = "";
    bool matched = false;
    for (i = i+1; i < line.size(); i++) {
        if (line[i] == ' ') {
            if (matches(buf,pattern)) {
                out += buf + " ";
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    if (out.size() > 0) {
        cout << out.substr(0,out.size()-1) << endl;
    } else {
        cout << '-' << endl;
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

