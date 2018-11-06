#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void insertSorted(vector<int> * v, int value) {
    int i;
    for (i = 0; i < v->size(); i++) {
        if (value < v->at(i)) {
            break;
        }
    }
    v->insert(v->begin()+i,value);
}

void process(string line) {
    int i, l, tmp;
    vector<int> points;
    string buf = "";
    for (i = line.find(";"), l = 0; i < line.size(); l=i+1,i = line.substr(i+1,line.size()-(i+1)).find(";")) {
        buf = line.substr(l,i);
        tmp = buf.find(",");
        stringstream(buf.substr((tmp+1),buf.size()-(tmp+1))) >> tmp;
        insertSorted(&points,tmp);
    }
    tmp = 0;
    for (i = 0; i < points.size()-1; i++) {
        cout << (points.at(i)-tmp) << ",";
        tmp = points.at(i);
    }
    cout << (points.at(points.size()-1)-tmp) << endl;
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

