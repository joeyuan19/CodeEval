#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool prime(int n) {
    if (n > 3) {
        for (int i = 3; i*i <= n; i += 2) {
            if (n%i == 0) {
                return false;
            }
        }
    } else {
        return true;
    }
    return true;
}

void process(string line) {
    int a, b;
    int idx = line.find(",");
    stringstream(line.substr(0,idx)) >> a;
    stringstream(line.substr(idx+1,line.size()-(idx+1))) >> b;
    int n = 0;
    if (a == 2) {
        n++;
        a++;
    }
    for (int i = (a%2 == 0 ? a+1 : a); i <= (b%2 == 0 ? b-1 : b); i += 2) {
        if (prime(i)) {
            n++;
        }
    }
    cout << n << endl;
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

