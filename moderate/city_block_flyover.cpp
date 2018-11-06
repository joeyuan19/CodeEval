#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool passes(double slope, int x1, int y1, int x2, int y2) {
    double p = y1/slope;
    if (p > x1 && p < x2) {
        return true;
    }
    p = y2/slope;
    if (p > x1 && p < x2) {
        return true;
    }
    p = slope*x1;
    if (p > y1 && p < y2) {
        return true;
    }
    p = slope*x2;
    if (p > y1 && p < y2) {
        return true;
    }
    p = slope*(x1 + (x2-x1)/2.0);
    if (p > y1 && p < y2) {
        return true;
    }
    return false;
}

void process(string line) {
    vector<int> x, y;
    string buf = "";
    int idx = line.find(" "), tmp;
    int i, j;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ',' || line[i] == ')') {
            stringstream(buf) >> tmp;
            if (i < idx) {
                x.push_back(tmp);
            } else {
                y.push_back(tmp);
            }
            buf = "";
        } else if (line[i] >= '0' || line[i] <= '9') {
            buf += line[i];
        }
    }
    double m = y.back()/((double)x.back());
    int blocks = 0;
    for (i = 0; i < x.size()-1; i++) {
        for (j = 0; j < y.size()-1; j++) {
            if (passes(m,x[i],y[j],x[i+1],y[j+1])) {
                blocks++;
            }
        }
    }
    cout << blocks << endl;
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

