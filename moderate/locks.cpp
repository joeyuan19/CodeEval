#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void process(string line) {
    int N, M, idx = line.find(" ");
    stringstream(line.substr(0,idx)) >> N;
    stringstream(line.substr(idx+1,line.size()-(idx+1))) >> M;
    bool doors [N];
    int n, m;
    for (n = 0; n < N; n++) {
        doors[n] = true;
    }
    for (m = 0; m < M-1; m++) {
        for (n = 1; n < N; n += 2) {
            doors[n] = false;
        }
        for (n = 2; n <= N; n += 3) {
            doors[n] = !doors[n];
        }
    }
    doors[N-1] = !doors[N-1];
    int c = 0;
    for (n = 0; n < N; n++) {
        if (doors[n]) {
            c++;
        }
    }
    cout << c << endl;
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

