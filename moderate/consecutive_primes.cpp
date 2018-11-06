#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool prime(int n) {
    if (n%2 == 0) {
        return false;
    } else {
        for (int i = 3; i*i <= n; i += 2) {
            if (n%i == 0) {
                return false;
            }
        }
        return true;
    }
}

void sortFrom(std::vector<int> * v, int startFrom) {
    int tmp, i;
    bool swapMade = true;
    while (swapMade) {
        swapMade = false;
        for (i = startFrom; i < v->size()-1; i++) {
            if (v->at(i) > v->at(i+1)) {
                tmp = v->at(i);
                v->at(i) = v->at(i+1);
                v->at(i+1) = tmp;
                swapMade = true;
            }
        }
    }
}

bool permute(std::vector<int> * v) {
    int i, j, tmp;
    int md, mi;
    for (i = v->size()-1; i > 0; i--) {
        if (v->at(i) > v->at(i-1)) {
            tmp = v->at(i-1);
            for (j = v->size()-1; j > 0; j--) {
                if (v->at(j) > v->at(i-1)) {
                    break;
                } 
            }
            v->operator[](i-1) = v->at(j);
            v->operator[](j) = tmp;
            sortFrom(v,i);
            return true;
        }
    }
    return false;
}

void process(string line) {
    int N, i, s = 0;
    stringstream(line) >> N;
    vector<int> n;
    for (i = 0; i < N; i++) {
        n.push_back(i);
    }
    bool p = false;
    while (true) {
        p = true;
        for (i = 0; i <= N; i++) {
            if (!prime(n.at(i%N)+n.at((i+1)%N))) {
                p = false;
                break;
            }
        }
        if (p) {
            s++;
        }
        if (!permute(&n)) {
            break;
        }
    }
    cout << s/N << endl;
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

