#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int scoreChar(char c) {
    if (c >= 'a' && c <= 'z') {
        return ((int)(c-'a'));
    } else if (c >= 'A' && c <= 'Z') {
        return ((int)(c-'A'));
    } else {
        return 26;
    }
}

vector<int> freqTable(string s) {
    vector<int> h (27,0), f (27,0);
    int i, j;
    for (i = 0; i < s.size(); i++) {
        h[scoreChar(s[i])] += 1;
    }
    int score = 26;
    for (i = s.size(); i >= 0; i--) {
        for (j = 0; j < h.size()-1; j++) {
            if (h.at(j) == i) {
                f[j] = score;
                score--;
            }
        }
    }
    return f;
}

int process(string line) {
    vector<int> f;
    f = freqTable(line);
    int s = 0, tmp;
    for (int i = 0; i < line.size(); i++) {
        s += f.at(scoreChar(line[i]));
    }
    return s;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        cout << process(line) << endl;
    }
    f.close();
    return 0;
}

