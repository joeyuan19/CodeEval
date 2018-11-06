#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> splitInt(string s) {
    string buf = "";
    vector<int> v;
    int tmp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            stringstream(buf) >> tmp;
            v.push_back(tmp);
            buf = "";
        } else {
            buf += s[i];
        }
    }
    stringstream(buf) >> tmp;
    v.push_back(tmp);
    return v;
}

vector<string> splitWord(string s) {
    string buf = "";
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(buf);
            buf = "";
        } else {
            buf += s[i];
        }
    }
    v.push_back(buf);
    return v;
}

int findInt(vector<int> * v, int n) {
    for (int i = 0; i < v->size(); i++) {
        if (v->at(i) == n) {
            return i;
        }
    }
    return -1;
}

void printDecoded(string s) {
    int i = s.rfind(';');
    string encoded = s.substr(0,i);
    string indexes = s.substr(i+1,s.size()-(i+1));
    vector<string> words;
    words = splitWord(encoded);
    vector<int> idx;
    idx = splitInt(indexes);
    for (i = 1; i <= idx.size()+1; i++) {
        if (findInt(&idx,i) < 0) {
            idx.push_back(i);
            break;
        }
    }
    string out = "";
    for (i = 1; i < idx.size()+1; i++) {
        out += words.at(findInt(&idx,i)) + " ";
    }
    cout << out.substr(0,out.size()-1) << endl;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        printDecoded(line);
    }
    return 0;
}
