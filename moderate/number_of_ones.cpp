#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void process(string line) {
    int tmp, c = 0;
    stringstream(line) >> tmp;
    while (tmp > 0) {
        c += tmp%2;
        tmp = tmp/2;
    }
    cout << c << endl;
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

