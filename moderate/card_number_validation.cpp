#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int digitSum(int n) {
    int s = n;
    while (s >= 10) {
        s = s%10+s/10;
    }
    return s;
}

void process(string line) {
    int s = 0;
    bool d = false;
    for (int i = line.size()-1; i >= 0; i--) {
        if (line[i] != ' ') {
            if (d) {
                s += digitSum(2*((int)(line[i]-'0')));
            } else {
                s += ((int)(line[i]-'0'));
            }
            d = !d;
        }
    }
    if (s%10 == 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
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

