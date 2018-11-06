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

bool startsWithCI(string s, string start) {
    if (s.size() < start.size()) {
        return false;
    }
    for (int i = 0; i < start.size(); i++) {
        if (lower(s[i]) != lower(start[i])) {
            return false;
        }
    }
    return true;
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
            buf += percentDecode(url.substr(i,3));
            i += 2;
        } else {
            buf += url[i];
        }
    }
    return buf;
}

bool matches(string u1, string u2) {
    int i1 = 0, j1, i2 = 0, j2;
    if (startsWithCI(u1,"http://")) {
        if (!startsWithCI(u2,"http://")) {
            cout << "broke on http:" << endl;
            cout << "  " << u1 << endl;
            cout << "  " << u2 << endl;
            return false;
        }
        i1 = 7;
        i2 = 7;
    } else if (startsWithCI(u1,"https://")) {
        if (!startsWithCI(u2,"https://")) {
            cout << "broke on https:" << endl;
            cout << "  " << u1 << endl;
            cout << "  " << u2 << endl;
            return false;
        }
        i1 = 8;
        i2 = 8;
    }
    if (!compareCI(u1.substr(i1,(j1 = u1.find_first_of(":/",i1))-i1),u2.substr(i2,(j2 = u2.find_first_of(":/",i2))-i2))) {
        cout << "broke on domain:" << endl;
        cout << "  " << (u1) << endl;
        cout << "  " << (u2) << endl;
        return false;
    }
    i1 = j1;
    i2 = j2;
    string p1, p2;
    if (u1[i1] == ':') {
        p1 = u1.substr(i1+1,(j1 = u1.find_first_not_of("0123456789",i1+1))-i1-1);
    } else {
        p1 = "80";
    }
    if (u2[i2] == ':') {
        p2 = u2.substr(i2+1,(j2 = u2.find_first_not_of("0123456789",i2+1))-i2-1);
    } else {
        p2 = "80";
    }
    if (!startsWithCI(p1,p2)) {
        return false;
    }
    i1 = j1;
    i2 = j2;
    string buf = "";
    char c = -1;
    while (i1 < u1.size() && i2 < u2.size()) {
        if (u1[i1] == '%' && u2[i2] != '%' && (c = percentDecode(u1.substr(i1,3))) >= 0) {
            if (c == u2[i2]) {
                i1 += 2;
            } else {
                return false;
                cout << "broke on percent:" << endl;
                cout << c << " vs " << u1[i1] << endl;
                cout << "  " << u1 << endl;
                cout << "  " << decode(u1) << endl;
                cout << "  " << u2 << endl;
                cout << "  " << decode(u2) << endl;
            }
        } else if (u2[i2] == '%' && u1[i1] != '%' && (c = percentDecode(u2.substr(i2,3))) >= 0) {
            if (c == u1[i1]) {
                i2 += 2;
            } else {
                cout << "broke on percent:" << endl;
                cout << c << " vs " << u1[i1] << endl;
                cout << "  " << u1 << endl;
                cout << "  " << decode(u1) << endl;
                cout << "  " << u2 << endl;
                cout << "  " << decode(u2) << endl;
                return false;
            }
        } else if (u1[i1] != u2[i2]) {
            cout << "broke on compare:" << endl;
            cout << u1[i1] << " vs " << u2[i2] << endl;
            cout << " raw:" << endl;
            cout << "  " << u1 << endl;
            cout << "  " << u2 << endl;
            cout << " decoded:" << endl;
            cout << "  " << decode(u1) << endl;
            cout << "  " << decode(u1) << endl;
            return false;
        }
        i1++;
        i2++;
    }
    return i1 == u1.size() && i2 == u2.size();
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

