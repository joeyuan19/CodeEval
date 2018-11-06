#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void process(string line) {
    long n1,n2;
    int idx = line.find("+");
    if (idx != string::npos) {
        stringstream(line.substr(0,((int)(line[idx-1]-'a'+1)))) >> n1;
        idx = ((int)(line[idx+1]-'a'));
        stringstream(line.substr(idx,((int)(line[line.size()-1]-'a'+1))-idx)) >> n2;
        cout << n1+n2 << endl;
    } else {
        idx = line.find("-");
        stringstream(line.substr(0,((int)(line[idx-1]-'a'+1)))) >> n1;
        idx = ((int)(line[idx+1]-'a'));
        stringstream(line.substr(idx,((int)(line[line.size()-1]-'a'+1))-idx)) >> n2;
        cout << n1-n2 << endl;
    }
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

