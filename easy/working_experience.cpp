#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int month(string s) {
    if (s.compare("Jan") == 0) {
        return 1;
    } else if (s.compare("Feb") == 0) {
        return 2;
    } else if (s.compare("Mar") == 0) {
        return 3;
    } else if (s.compare("Apr") == 0) {
        return 4;
    } else if (s.compare("May") == 0) {
        return 5;
    } else if (s.compare("Jun") == 0) {
        return 6;
    } else if (s.compare("Jul") == 0) {
        return 7;
    } else if (s.compare("Aug") == 0) {
        return 8;
    } else if (s.compare("Sep") == 0) {
        return 9;
    } else if (s.compare("Oct") == 0) {
        return 10;
    } else if (s.compare("Nov") == 0) {
        return 11;
    } else if (s.compare("Dec") == 0) {
        return 12;
    } else {
        return 0;
    }
}

int year(string s) {
    int tmp;
    stringstream(s) >> tmp;
    return tmp;
}

void process(string line) {
    line += ";";
    double exp = 0.0, d1, d2, ld1 = -1, ld2 = -1;
    int i, j, m1, y1, m2, y2;
    string buf = "";
    bool first = true;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ';') {
            y2 = year(buf);
            d1 = y1 + m1/12.0;
            d2 = y2 + m2/12.0;
            cout << "d1  = " << d1 << endl;
            cout << "d2  = " << d2 << endl;
            cout << "ld1 = " << ld1 << endl;
            cout << "ld2 = " << ld2 << endl;
            if (d1 < ld2) {
                exp += d2-ld2; 
            } else {
                exp += d2-d1; 
            }
            cout << "exp = " << exp << endl;
            first = true;
            buf = "";
            ld1 = d1;
            ld2 = d2; 
        } else if (line[i] == '-') {
            y1 = year(buf);
            first = false; 
            buf = "";
        } else if (line[i] == ' ') {
            if (first) {
                m1 = month(buf);
            } else {
                m2 = month(buf);
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    cout << ((int)exp) << endl;
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


