#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    int idx = line.rfind(","), i, j;
    int l = line.size()-idx;
    for (j = line.size()-1; j > idx; j--) {
        if (line[j] != line[j-l]) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
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

