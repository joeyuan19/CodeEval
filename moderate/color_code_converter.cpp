#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

double abs(double x) {
    return x >= 0 ? x : -x;
}

double mod2(double x) {
    return x - 2*(((int)x)/2);
}

int properRound(double x) {
    if (x-((int)x) >= .5) {
        return ((int)x)+1;
    } else {
        return ((int)x);
    }
}

int hexToDec(string h) {
    int n = 0;
    if (h[0] >= 'a' && h[0] <= 'f') {
        n = 10+((int)(h[0]-'a'));
    } else {
        n = ((int)(h[0]-'0'));
    }
    n = n*16;
    if (h[1] >= 'a' && h[1] <= 'f') {
        n += 10+((int)(h[1]-'a'));
    } else {
        n += ((int)(h[1]-'0'));
    }
    return n;
}

void convertHex(string line) {
    cout << "RGB(" << hexToDec(line.substr(1,2)) << "," << hexToDec(line.substr(3,2)) << "," << hexToDec(line.substr(5,2)) << ")" << endl;
}

void convertCMYK(string line) {
    line += ",";
    double c, m, y, k;
    string buf;
    int itr = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            if (itr == 0) {
                stringstream(buf) >> c;
            } else if (itr == 1) {
                stringstream(buf) >> m;
            } else if (itr == 2) {
                stringstream(buf) >> y;
            } else if (itr == 3) {
                stringstream(buf) >> k;
            }
            itr++;
            buf = "";
        } else if (line[i] == '.' || (line[i] <= '9' && line[i] >= '0')) {
            buf += line[i];
        }
    }
    cout << "RGB(" << (properRound(255*(1.-c)*(1.-k))) << "," << (properRound(255*(1.-m)*(1.-k))) << "," << (properRound(255*(1.-y)*(1.-k))) << ")" << endl;
}

void convertHSL(string line) {
    line += ",";
    double h, s, l;
    string buf;
    int itr = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            if (itr == 0) {
                stringstream(buf) >> h;
            } else if (itr == 1) {
                stringstream(buf) >> s;
            } else if (itr == 2) {
                stringstream(buf) >> l;
            }
            itr++;
            buf = "";
        } else if (line[i] == '.' || (line[i] <= '9' && line[i] >= '0')) {
            buf += line[i];
        }
    }
    s = s/100.;
    l = l/100.;
    double c = (1. - abs(2.*l-1.))*s;
    double hp = h/60.;
    double x = c*(1 - abs(mod2(hp) - 1));
    double r1, g1, b1;
    if (0 <= hp && hp < 1) {
        r1 = c;
        g1 = x;
        b1 = 0;
    } else if (1 <= hp && hp < 2) {
        r1 = x;
        g1 = c;
        b1 = 0;
    } else if (2 <= hp && hp < 3) {
        r1 = 0;
        g1 = c;
        b1 = x;
    } else if (3 <= hp && hp < 4) {
        r1 = 0;
        g1 = x;
        b1 = c;
    } else if (4 <= hp && hp < 5) {
        r1 = x;
        g1 = 0;
        b1 = c;
    } else if (5 <= hp && hp < 6) {
        r1 = c;
        g1 = 0;
        b1 = x;
    }
    double m = l - .5*c;
    r1 = r1 + m;
    g1 = g1 + m;
    b1 = b1 + m;
    int R = properRound(255*r1);
    int G = properRound(255*g1);
    int B = properRound(255*b1);
    cout << "RGB(" << R << "," << G << "," << B << ")" << endl;
}

void convertHSV(string line) {
    line += ",";
    double h, s, v;
    string buf;
    int itr = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            if (itr == 0) {
                stringstream(buf) >> h;
            } else if (itr == 1) {
                stringstream(buf) >> s;
            } else if (itr == 2) {
                stringstream(buf) >> v;
            }
            itr++;
            buf = "";
        } else if (line[i] == '.' || (line[i] <= '9' && line[i] >= '0')) {
            buf += line[i];
        }
    }
    v = v/100.;
    s = s/100.;
    double c = v*s;
    double hp = h/60.;
    double x = c*(1 - abs(mod2(hp) - 1));
    double r1, g1, b1;
    if (0 <= hp && hp < 1) {
        r1 = c;
        g1 = x;
        b1 = 0;
    } else if (1 <= hp && hp < 2) {
        r1 = x;
        g1 = c;
        b1 = 0;
    } else if (2 <= hp && hp < 3) {
        r1 = 0;
        g1 = c;
        b1 = x;
    } else if (3 <= hp && hp < 4) {
        r1 = 0;
        g1 = x;
        b1 = c;
    } else if (4 <= hp && hp < 5) {
        r1 = x;
        g1 = 0;
        b1 = c;
    } else if (5 <= hp && hp < 6) {
        r1 = c;
        g1 = 0;
        b1 = x;
    }
    double m = v - c;
    r1 = r1 + m;
    g1 = g1 + m;
    b1 = b1 + m;
    int R = properRound(255*r1);
    int G = properRound(255*g1);
    int B = properRound(255*b1);
    cout << "RGB(" << R << "," << G << "," << B << ")" << endl;
}

void process(string line) {
    if (line[0] == '#') {
        convertHex(line);
    } else if (line[0] == '(') {
        convertCMYK(line);
    } else if (line[0] == 'H') {
        if (line[2] == 'L') {
            convertHSL(line);
        } else if (line[2] == 'V') {
            convertHSV(line);
        } else {
            cout << "DONT KNOW: " << line << endl;
        }
    } else {
        cout << "DONT KNOW: " << line << endl;
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

