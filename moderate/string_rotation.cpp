#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    int idx = line.find(","), i, j, k;
    string a = line.substr(0,idx), b = line.substr(idx+1,line.size()-(idx+1));
    bool found;
    for (i = 0; i < b.size(); i++) {
        found = true;
        for (j = 0, k = i; j < a.size(); j++, k = (k+1)%b.size()) {
            if (a[j] != b[k]) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << "True" << endl;
            return;
        }
    }
    cout << "False" << endl;
    return;
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

