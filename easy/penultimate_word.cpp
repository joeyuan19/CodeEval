#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string process(string line) {
    int end = line.rfind(" ");
    int start = line.substr(0,end).rfind(" ");
    start = start == string::npos ? 0 : start+1;
    return line.substr(start,end-start);
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        cout << process(line) << endl;
    }
    f.close();
    return 0;
}

