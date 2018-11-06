#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void process(string line) {
    int idx = line.find(";");
    int i;
    line = line.substr(idx+1,line.size()-(idx+1));
    line = "," + line + ",";
    string buf = "";
    for (i = 1; i < line.size(); i++) {
        if (line[i] == ',') {
            if (line.find(","+buf+",") != i-buf.size()-1) {
                cout << buf << endl;
                return;
            }
            buf = "";
        } else {
            buf += line[i];
        }
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

