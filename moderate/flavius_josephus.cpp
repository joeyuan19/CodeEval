#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void process(string line) {
    int i = line.find(","), j;
    int n, m;
    stringstream(line.substr(0,i)) >> n;
    stringstream(line.substr(i+1)) >> m;
    vector<int> v;
    for (i = 0; i < n; i++) {
        v.push_back(i);
    }
    i = m-1;
    while (v.size() > 1) {
        cout << v.at(i) << " ";
        v.erase(v.begin()+i);
        i = (i-1+m)%v.size();
    }
    cout << v.back() << endl;
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

