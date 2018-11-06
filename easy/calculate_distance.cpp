#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

void getPoint(int x[2],string s) {
    int tmp, idx;
    idx = s.find(", ");
    stringstream(s.substr(1,idx)) >> tmp;
    x[0] = tmp;
    stringstream(s.substr(idx+2,s.size()-(idx+3))) >> tmp;
    x[1] = tmp;
}

void process(string line) {
    int p1[2], p2[2];
    int mid = line.rfind(") (");
    getPoint(p1,line.substr(0,mid+1));
    getPoint(p2,line.substr(mid+2,line.size()-(mid+2)));
    int x = p2[0]-p1[0];
    int y = p2[1]-p1[1];
    cout << sqrt(x*x + y*y) << endl;
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

