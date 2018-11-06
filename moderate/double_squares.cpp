#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

void process(string line) {
    long N;
    stringstream(line) >> N;
    int i, j, c = 0;
    long double n;
    for (i = 0; i*i <= N; i++) {
        n = sqrt(N - i*i);
        if (i > n) {
            break;
        } else if (((int)n) == n) {
            c++;
        }
    }
    cout << c << endl;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    getline(f,line);
    while (getline(f,line)) {
        process(line);
    }
    f.close();
    return 0;
}

