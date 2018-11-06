#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int abs(int n) {
    return n < 0 ? -n : n;
}

void process(string line) {
    int x1,y1,z1,x2,y2,z2;
    int i, itr = 0, tmp;
    string buf = "";
    for (i = 0; i < line.size(); i++) {
        if (line[i] == '|') {
            break;
        } else if ((line[i] == ']' || line[i] == ',') && buf.size() > 0) {
            stringstream(buf) >> tmp;
            switch (itr) {
                case 0:
                    x1 = tmp;
                    break;
                case 1:
                    y1 = tmp;
                    break;
                case 2:
                    x2 = tmp;
                    break;
                case 3:
                    y2 = tmp;
                    break;
                default:
                    break;
            }
            buf = "";
            itr++;
        } else if (line[i] == '-' || (line[i] <= '9' && line[i] >= '0')) {
            buf += line[i];
        }
    }
    int w = abs(x2-x1);
    int h = abs(y2-y1);
    vector<int> bricks;
    itr = 0;
    buf = "";
    for ( ; i < line.size(); i++) {
        if ((line[i] == '[' || line[i] == ',' || line[i] == ']') && buf.size() > 0) {
            stringstream(buf) >> tmp;
            switch (itr%7) {
                case 0:
                    bricks.push_back(tmp);
                    break;
                case 1:
                    x1 = tmp;
                    break;
                case 2:
                    y1 = tmp;
                    break;
                case 3:
                    z1 = tmp;
                    break;
                case 4:
                    x2 = tmp;
                    break;
                case 5:
                    y2 = tmp;
                    break;
                case 6:
                    z2 = tmp;
                    bricks.push_back(abs(x2-x1));
                    bricks.push_back(abs(y2-y1));
                    bricks.push_back(abs(z2-z1));
                    break;
                default:
                    break;
            }
            itr++;
            buf = "";
        } else if (line[i] == '-' || (line[i] <= '9' && line[i] >= '0')) {
            buf += line[i];
        }
    }
    vector<int> out;
    for (i = 0; i < bricks.size(); i += 4) {
        if (bricks[i+1] <= w && bricks[i+2] <= h) { // x vs w, y vs h
            out.push_back(bricks.at(i));
        } else if (bricks[i+1] <= w && bricks[i+3] <= h) { // x vs w, z vs h
            out.push_back(bricks.at(i));
        } else if (bricks[i+1] <= h && bricks[i+2] <= w) { // x vs h, y vs w
            out.push_back(bricks.at(i));
        } else if (bricks[i+1] <= h && bricks[i+3] <= w) { // x vs h, z vs w
            out.push_back(bricks.at(i));
        } else if (bricks[i+2] <= w && bricks[i+3] <= h) { // y vs w, z vs h
            out.push_back(bricks.at(i));
        } else if (bricks[i+2] <= h && bricks[i+3] <= w) { // y vs h, z vs w
            out.push_back(bricks.at(i));
        }
    }
    if (out.size() == 0) {
        cout << '-' << endl;
    } else {
        bool s = true;
        while (s) {
            s = false;
            for (i = 0; i < out.size()-1; i++) {
                if (out.at(i) > out.at(i+1)) {
                    tmp = out.at(i);
                    out[i] = out.at(i+1);
                    out[i+1] = tmp;
                    s = true;
                }
            }
        }
        for (i = 0; i < out.size()-1; i++) {
            cout << out.at(i) << ",";
        } cout << out.at(i) << endl;
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

