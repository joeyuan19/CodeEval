#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

void process(string line) {
    if (regex_match(line,regex("\\.[a-z]"))) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
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
