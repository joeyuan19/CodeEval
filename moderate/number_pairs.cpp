#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string to_string(int n) {
    ostringstream ss;
    ss << n;
    return ss.str();
}

void process(string line) {
    int s, idx = line.find(";");
    line.insert(idx,",");
    idx++;
    stringstream(line.substr(idx+1,line.size()-(idx+1))) >> s;
    string A, B;
    int a, b;
    int i, j;
    string out = "";
    for (i = 0; i < idx; i++) {
        if (line[i] == ',') {
            stringstream(A) >> a;
            if (a >= s) {
                break;
            }
            B = "";
            for (j = i+1; j < idx; j++) {
                if (line[j] == ',') {
                    stringstream(B) >> b;
                    if (a+b >= s) {
                        if (a+b == s) {
                            out += to_string(a)+","+to_string(b)+";";
                        }
                        break;
                    }
                    B = "";
                } else {
                    B += line[j];
                }
            }
            A = "";
        } else {
            A += line[i];
        }
    }
    if (out.size() > 0) {
        cout << out.substr(0,out.size()-1) << endl;
    } else {
        cout << "NULL" << endl;
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

