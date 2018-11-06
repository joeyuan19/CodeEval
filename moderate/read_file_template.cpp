#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
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

