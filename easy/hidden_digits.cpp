#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    bool any = false;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] >= 'a' && line[i] <= 'j') {
            cout << ((int)(line[i]-'a'));
            any = true;
        } else if (line[i] >= '0' && line[i] <= '9') {
            cout << line[i];
            any = true;
        }
    }
    if (any) {
        cout << endl;
    } else {
        cout << "NONE" << endl;
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

