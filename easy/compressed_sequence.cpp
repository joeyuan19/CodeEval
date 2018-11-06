#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    line += " ";
    int c = 1, i = line.find(" ");
    string buf = "", last = line.substr(0,i);
    for (i = i +1; i < line.size(); i++) {
        if (line[i] == ' ') {
            if (buf.compare(last) == 0) {
                c++;
            } else {
                cout << c << " " << last << " ";
                c = 1;
                last = buf;
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    cout << c << " " << last << endl;
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

