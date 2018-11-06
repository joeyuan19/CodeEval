#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    int idx = line.find(";");
    string before = line.substr(0,idx)+" ", after = line.substr(idx+1,line.size()-(idx+1))+" ";
    int print [before.size()];
    int i = 0, j = 0, k = 0, l = 0;
    for (i = 0; i < before.size(); i++) {
        if (before[i] == ' ') {
            if (i > 0 && before[i-1] == ' ') {
                print[i] = 2;
            } else {
                print[i] = 1;
            }
        } else {
            print[i] = 0;
        }
    }
    bool match = false;
    for (i = 0; i < before.size(); i++) {
        k = 0;
        match = true;
        while (i+k < before.size() && j+k < after.size()) {
            if (after[j+k] == ' ') {
                for (l = 0; l < k; l++) {
                    print[i+l] = 1;
                }
                j = j + k + 1;
                i = i + before.substr(i,before.size()-i).find(" ");
                break;
            } else if (after[j+k] != before[i+k]) {
                match = false;
                break;
            } 
            k++;
        }
        if (j >= after.size()) {
            break;
        }
    }
    if (j < after.size()) {
        cout << "I cannot fix history" << endl;
    } else {
        for (i = 0; i < before.size()-1; i++) {
            if (print[i] == 1) {
                cout << before[i];
            } else if (print[i] == 2) {
                // pass
            } else {
                cout << "_";
            }
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    string line;
    ifstream f (argv[1]);
    while (getline(f,line)) {
        process(line);
    }
    f.close();
    return 0;
}
