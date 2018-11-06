#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void process(string line) {
    line += ",";
    int L = 0, i;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            L++;
        }
    }
    string buf = "";
    map<string,int> data;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            if (data.find(buf) == data.end()) {
                data[buf] = 1;
            } else {
                data[buf]++;
            }
            if (data[buf] >= L/2) {
                cout << buf << endl;
                return;
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    cout << "None" << endl;
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

