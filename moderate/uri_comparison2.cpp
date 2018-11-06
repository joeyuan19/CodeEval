#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 'a'+c-'A';
    } else {
        return c;
    }
}

string lower(string s) {
    string out = "";
    for (int i = 0; i < s.size(); i++) {
        out += lower(s[i]);
    }
    return out;
}

bool compareCI(string u1, string u2) {
    if (u1.size() != u2.size()) {
        return false;
    }
    for (int i = 0; i < u1.size(); i++) {
        if (lower(u1[i]) != lower(u2[i])) {
            return false;
        }
    }
    return true;
}

char percentDecode(string pe) {
    if (compareCI(pe,"%3A")) { return ':';}
    else if (compareCI(pe,"%2F")) { return '/';}
    else if (compareCI(pe,"%23")) { return '#';}
    else if (compareCI(pe,"%3F")) { return '?';}
    else if (compareCI(pe,"%24")) { return '$';}
    else if (compareCI(pe,"%40")) { return '@';}
    else if (compareCI(pe,"%25")) { return '%';}
    else if (compareCI(pe,"%2B")) { return '+';}
    else if (compareCI(pe,"%2A")) { return '*';}
    else if (compareCI(pe,"%20")) { return ' ';}
    else if (compareCI(pe,"%3B")) { return ';';}
    else if (compareCI(pe,"%3D")) { return '=';}
    else if (compareCI(pe,"%26")) { return '&';}
    else if (compareCI(pe,"%2C")) { return ',';}
    else if (compareCI(pe,"%3C")) { return '<';}
    else if (compareCI(pe,"%3E")) { return '>';}
    else if (compareCI(pe,"%7E")) { return '~';}
    else if (compareCI(pe,"%5E")) { return '^';}
    else if (compareCI(pe,"%60")) { return '`';}
    else if (compareCI(pe,"%27")) { return '\'';}
    else if (compareCI(pe,"%5C")) { return '\\';}
    else if (compareCI(pe,"%28")) { return '(';}
    else if (compareCI(pe,"%29")) { return ')';}
    else if (compareCI(pe,"%5B")) { return '[';}
    else if (compareCI(pe,"%5D")) { return ']';}
    else if (compareCI(pe,"%7B")) { return '{';}
    else if (compareCI(pe,"%7D")) { return '}';}
    else if (compareCI(pe,"%7C")) { return '|';}
    else if (compareCI(pe,"%22")) { return '"';}
    else if (compareCI(pe,"%21")) { return '!';}
    else { return -1;}
}

string decode(string url) {
    string buf = "";
    for (int i = 0; i < url.size(); i++) {
        if (url[i] == '%') {
            char c = percentDecode(url.substr(i,3));
            if (c >= 0) {
                buf += c;
                i += 2;
            } else {
                buf += url[i];
            }
        } else {
            buf += url[i];
        }
    }
    return buf;
}

string addPort(string url) {
    int idx = url.find_first_of(":/",8);
    if (idx == string::npos) {
        return url+":80";
    } else if (url[idx] == '/') {
        url = url.insert(idx,":80");
        return url;
    } else {
        return url;
    }
}

string fixURL(string url) {
    return decode(addPort(lower(url)));
}

bool matches(string u1, string u2) {
    u1 = fixURL(u1);
    u2 = fixURL(u2);
    return fixURL(u1).compare(fixURL(u2)) == 0;
}
void process(string line) {
    int idx = line.find(";");
    string url1 = line.substr(0,idx), url2 = line.substr(idx+1);
    if (matches(url1,url2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
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

