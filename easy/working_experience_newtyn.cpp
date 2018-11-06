#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int month(string m) {
    if (m.compare("Jan") == 0) {
        return 0;
    } else if (m.compare("Feb") == 0) {
        return 1;
    } else if (m.compare("Mar") == 0) {
        return 2;
    } else if (m.compare("Apr") == 0) {
        return 3;
    } else if (m.compare("May") == 0) {
        return 4;
    } else if (m.compare("Jun") == 0) {
        return 5;
    } else if (m.compare("Jul") == 0) {
        return 6;
    } else if (m.compare("Aug") == 0) {
        return 7;
    } else if (m.compare("Sep") == 0) {
        return 8;
    } else if (m.compare("Oct") == 0) {
        return 9;
    } else if (m.compare("Nov") == 0) {
        return 10;
    } else if (m.compare("Dec") == 0) {
        return 11;
    } else {
        return 0;
    }
}

int year(string y) {
    int tmp;
    stringstream(y) >> tmp;
    return tmp;
}

void process(string line) {
    line += "; ";
    int i, j, k;
    int total_months = 31*12;
    int months [total_months];
    for (i = 0; i < total_months; i++) {
        months[i] = 0;
    }
    int m1, y1, m2, y2;
    bool first = true;
    string buf = "";
    for (i = 0; i < line.size(); i++) {
        if (line[i] == '-') {
            y1 = year(buf);
            buf = "";
            first = !first;
        } else if (line[i] == ';') {
            y2 = year(buf);
            buf = "";
            for (j = 12*(y1-1990)+m1; j <= 12*(y2-1990)+m2; j++) {
                months[j] = 1;
            }
            i++;
            first = !first;
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
    int exp = 0;
    int y = 1991;
    for (i = 0; i < total_months; i++) {
        exp += months[i];
    }
    cout << exp/12 << endl;
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
