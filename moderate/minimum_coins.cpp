#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void process(string line) {
    int n, c;
    stringstream(line) >> n;
    c += n/5;
    n = n%5;
    c += n/3;
    n = n%3;
    c += n;
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

