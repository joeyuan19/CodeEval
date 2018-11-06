#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    int N = 10000, i, j, last;
    int s [N];
    for (i = 0; i < N; i++) {
        s[i] = 0;
    }
    for (i = 3; i*i <= N; i += 2) {
        for (j = 2*i; j <= N; j += i) {
            s[j]++;
        }
    }
    while (getline(f,line)) {
        stringstream(line) >> N;
        if (N > 2) {
            last = 2;
        }
        for (i = 3; i < N; i += 2) {
            if (s[i] == 0) {
                cout << last << ",";
                last = i;
            }
        }
        cout << last << endl;
    }
    f.close();
    return 0;
}

