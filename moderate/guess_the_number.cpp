#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void process(string line) {
    string buf = "";
    int low = 0, high;
    int idx = line.find(" ");
    stringstream(line.substr(0,idx)) >> high;
    int g = high%2 == 0 ? high/2 : 1+high/2;
    for (int i = idx+1; i < line.size(); i++) {
        if (line[i] == ' ') {
            if (buf.compare("Lower") == 0) {
                high = g-1;
                low = low;
                g = low + (high-low)%2 + (high-low)/2;
            } else if (buf.compare("Higher") == 0) {
                high = high;
                low = g+1;
                g = low + (high-low)%2 + (high - low)/2;
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    cout << g << endl;
}

int main(int argc, char *argv[]) {
    string line;
    ifstream f (argv[1]);
    while (getline(f,line)) {
        process(line);
    }
    f.close();
    return 0;
}

