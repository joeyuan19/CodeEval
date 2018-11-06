#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void process(string line) {
    int idx = line.find(";"), N, n = 0;
    stringstream(line.substr(idx+1,line.size()-(idx+1))) >> N;
    line = line.substr(0,idx)+",";
    string out = "", buf = "", tmp = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            if (n < N) {
                tmp = buf + "," + tmp;
            } else {
                out += tmp;
                tmp = buf + ",";
                n = 0;
            }
            buf = "";
            n++;
        } else {
            buf += line[i];
        }
    }
    buf = "";
    if (n == N) {
        out += tmp;
    } else {
        string tmp2 = "";
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == ',') {
                tmp2 = buf + "," + tmp2;
                buf = "";
            } else {
                buf += tmp[i];
            }
        }
        out += tmp2;
    }
    cout << out.substr(0,out.size()-1) << endl;
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

