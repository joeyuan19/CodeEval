#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    size_t p;
    while (getline(stream, line)) {
        p = (line.substr(0,line.size()-1)).rfind(line[line.size()-1]);
        if (p == string::npos) {
            cout << -1 << endl;
        } else {
            cout << p << endl;
        }
    }
    return 0;
}
