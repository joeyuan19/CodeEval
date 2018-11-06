#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void process(vector<unsigned long> * p, string line) {
    int N;
    stringstream(line) >> N;
    unsigned long i, j;
    bool flag = false;
    if (N > p->back()+1) {
        unsigned long s [N];
        for (i = p->back()+2; i <= N; i++) {
            flag = true;
            for (j = 0; j < p->size(); j++) {
                if (i%p->at(j) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                p->push_back(i);
            }
        } 
    }
    for (i = 0; i < p->size()-1; i++) {
        if (p->at(i+1) > N) {
            break;
        }
        cout << p->at(i) << ",";
    }
    cout << p->at(i) << endl;
}

int main(int argc, char *argv[]) {
    vector<unsigned long> p = {2,3,5,7,11,13,17,19};
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        process(&p,line);
    }
    f.close();
    return 0;
}


