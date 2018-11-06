#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
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
    line += ",";
    vector<string> words;
    string buf = "", tmp;
    int i, j, k, m = 1, last;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ',') {
            tmp = "";
            tmp += buf[0];
            tmp += buf[buf.size()-1];
            words.push_back(tmp);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    bool n = false, f = false;
    for (i = 0; i < words.size(); i++) {
        vector<int> idx = {i};
        last = 0;
        while (idx.size() > 0) {
            n = false;
            for (j = last; j < words.size(); j++) {
                f = false;
                for (k = 0; k < idx.size(); k++) {
                    if (idx.at(k) == j) {
                        f = true;
                        break;
                    }
                }
                if (!f && words.at(idx.back())[1] == words.at(j)[0]) {
                    n = true;
                    idx.push_back(j);
                    break;
                }
            }
            if (!n) {
                if (idx.size() > m) {
                    m = idx.size();
                }
                last = idx.back()+1;
                idx.pop_back();
            } else {
                last = 0;
            }
        }
    }
    if (m == 1) {
        cout << "None" << endl;
    } else {
        cout << m << endl;
    }
    return;
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

