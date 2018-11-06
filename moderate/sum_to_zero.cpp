#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int sum(vector<int> * v, vector<int> * idx) {
    int s = 0;
    for (int i = 0; i < idx->size(); i++) {
        s += v->at(idx->at(i));
    }
    return s;
}

void process(string line) {
    line += ",";
    vector<int> v;
    int i, j, k, c = 0, tmp;
    string buf = "";
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            stringstream(buf) >> tmp;
            v.push_back(tmp);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    for (i = 0; i < v.size(); i++) {
        vector<int> idx = {i};
        tmp = i+1;
        while (idx.size() > 0) {
            for (j = tmp; j < v.size(); j++) {
                idx.push_back(j);
                if (idx.size() == 4 && sum(&v,&idx) == 0) {
                    c++;
                }
            }
            tmp = idx.back()+1;
            idx.pop_back();
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

