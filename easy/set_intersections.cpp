#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string printIntersections(string line) {
    string out = "", buf = "";
    int idx = line.rfind(";"), i, j, last = idx + 1;
    for (i = 0; i <= idx; i++) {
        if (i == idx || line[i] == ',') {
            for (j = last; j <= line.size()-buf.size(); j++) {
                if ((line[j+buf.size()] == ',' || j+buf.size() == line.size()) && line.substr(j,buf.size()).compare(buf) == 0) {
                    out += buf + (i == idx ? "" : ",");
                    last = j+buf.size();
                    break;
                }
            }
            buf = "";
        } else {
            buf += line[i];
        }
    }
    if (out[out.size()-1] == ',') {
        out = out.substr(0,out.size()-1);
    }
    return out;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        cout << printIntersections(line) << endl;
    }
    f.close();
    return 0;
}
