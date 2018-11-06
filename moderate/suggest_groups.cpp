#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void sort(vector<string> * v) {
    bool swap = true;
    string tmp;
    int i;
    while (swap) {
        swap = false;
        for (i = 0; i < v->size()-1; i++) {
            if (v->at(i).compare(v->at(i+1)) > 0) {
                tmp = v->at(i);
                v->operator[](i) = v->at(i+1);
                v->operator[](i+1) = tmp;
                swap = true;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    vector<string> group_names;
    vector<string> names;
    map<string,vector<string>> friends;
    map<string,vector<string>> groups;
    ifstream f (argv[1]);
    string line, name;
    string buf = "";
    int idx, i, j, k, l;
    while (getline(f,line)) {
        idx = line.find(":");
        vector<string> v;
        name = line.substr(0,idx);
        names.push_back(name);
        friends[name] = v;
        idx++;
        line = line.substr(idx,line.size()-idx);
        idx = line.find(":");
        buf = "";
        for (i = 0; i < idx+1; i++) {
            if (line[i] == ',' || line[i] == ':') {
                friends[name].push_back(buf);
                buf = "";
            } else {
                buf += line[i];
            }
        }
        vector<string> vv;
        groups[name] = vv;
        idx++;
        line = line.substr(idx,line.size()-idx)+",";
        buf = "";
        for (i = 0; i < line.size(); i++) {
            if (line[i] == ',') {
                if (buf.size() > 0) {
                    groups[name].push_back(buf);
                    for (j = 0; j < group_names.size(); j++) {
                        if (group_names.at(j).compare(buf) == 0) {
                            break;
                        }
                    }
                    if (j == group_names.size()) {
                        group_names.push_back(buf);
                    }
                    buf = "";
                }
            } else {
                buf += line[i];
            }
        }
    }
    f.close();
    bool notIn = true;
    double c;
    string out = "";
    sort(&names);
    sort(&group_names);
    for (i = 0; i < names.size(); i++) {
        out = "";
        for (j = 0; j < group_names.size(); j++) {
            notIn = true;
            for (k = 0; k < groups[names.at(i)].size(); k++) {
                if (group_names.at(j).compare(groups[names.at(i)].at(k)) == 0) {
                    notIn = false;
                    break;
                }
            }
            if (notIn) {
                c = 0;
                for (k = 0; k < friends[names.at(i)].size(); k++) {
                    for (l = 0; l < groups[friends[names.at(i)].at(k)].size(); l++) {
                        if (groups[friends[names.at(i)].at(k)].at(l).compare(group_names.at(j)) == 0) {
                            c += 1.0;
                            break;
                        }
                    }
                }
                if (c/friends[names.at(i)].size() >= .5) {
                    out += group_names.at(j) + ",";
                }
            }
        }
        if (out.size() > 0) {
            cout << names.at(i) << ":" << out.substr(0,out.size()-1) << endl;
        }
    }
    return 0;
}

