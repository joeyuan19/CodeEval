#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

long long nearestPow2(long long n) {
    int c = 0;
    while (n > 1) {
        n = n >> 1;
        c++;
    }
    n = 1;
    for (int i = 0; i < c; i++) {
        n = n << 1;
    }
    return n;
}

char cycle(char c) {
    return (c == '0' ? '1' : (c == '1' ? '2' : (c == '2' ? '0' : '#')));
}

void process(string line) {
    long long n;
    stringstream(line) >> n;
    char c = '0';
    while (n > 0) {
        n =  n - nearestPow2(n);
        c = cycle(c);
    }
    cout << c << endl;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    long long n;
    while (getline(f,line)) {
        process(line);
    }
    f.close();
    return 0;
}
