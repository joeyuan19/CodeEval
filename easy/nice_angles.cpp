#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string pad(int n) {
    string tmp = "";
    tmp += '0'+n/10;
    tmp += '0'+n%10;
    return tmp;
}

void process(string line) {
    double x;
    stringstream(line) >> x;
    int deg = ((int)(x));
    x = x-deg;
    int min = ((int)(60*x));
    x = 60*x;
    x = x-((int)x);
    int sec = ((int)(60*x));
    cout << deg << "." << pad(min) << "'" << pad(sec) << "\"" << endl;
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

