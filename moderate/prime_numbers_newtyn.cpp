#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void extend(vector<unsigned long> * p, unsigned long N) {
    unsigned long last = p->back()+2;
    unsigned long size = N-last;
    unsigned long s [size];
    unsigned long i, j;
    for (i = 0; i < size; i++) {
        s[i] = 0;
    }
    for (i = 0; i < p->size(); i++) {
        for (j = p->at(i)*(last%p->at(i) == 0 ? last/p->at(i) : last/p->at(i)); j < N; j += p->at(i)) {
            s[j-last]++;
        }
    }
    for (i = last; i*i <= N; i += 2) {
        if (s[i-last] == 0) {
            for (j = 2*i; j < N; j += i) {
                s[j-last]++;
            }
        }
    }
    for (i = 0; i < size; i++) {
        if (s[i] == 0) {
            p->push_back(last+i);
        }
    }
}

void process(vector<unsigned long> * primes, string line) {
    int N;
    stringstream(line) >> N;
    if (primes->back() < N) {
        extend(primes,N);
    }
    unsigned long i;
    for (i = 0; i < primes->size()-1; i++) {
        if (primes->at(i+1) >= N) {
            break;
        }
        cout << primes->at(i) << ",";
    } cout << primes->at(i) << endl;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    vector<unsigned long> p = {2,3};
    while (getline(f,line)) {
        process(&p,line);
    }
    f.close();
    return 0;
}

