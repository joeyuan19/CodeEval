#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    string remove = "", input = "";
    int i, j;
    for (i = line.size()-1; i >= 0; i--) {
        if (line[i] == ' ') {
            break;
        } else {
            remove = line[i] + remove;
        }
    }
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            break;
        } else {
            for (j = 0; j < remove.size(); j++) {
                if (remove[j] == line[i]) {
                    break;
                }
            }
            if (j == remove.size()) {
                cout << line[i];
            }
        }
    }
    cout << endl;
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

