#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void process(string line) {
    string list, swaps;
    int mid = line.find(" : ");
    int tmp, tmp2, tmp3;
    list = line.substr(0,mid);
    swaps = line.substr(mid+3,line.size()-(mid+3));
    vector<int> nums;
    int i;
    string buf = "", buf2 = "";
    for (i = 0; i <= list.size(); i++) {
        if ((i == list.size() || list[i] == ' ') && buf.size() > 0) {
            stringstream(buf) >> tmp;
            nums.push_back(tmp);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    buf = "";
    buf2 = "";
    bool second = false;
    for (i = 0; i <= swaps.size(); i++) {
        if ((i == swaps.size() || swaps[i] == ',') && buf.size() > 0) {
            stringstream(buf) >> tmp;
            stringstream(buf2) >> tmp2;
            tmp3 = nums.at(tmp);
            nums[tmp] = nums.at(tmp2);
            nums[tmp2] = tmp3;
            second = !second;
            buf = "";
            buf2 = "";
        } else if (swaps[i] == ' ') {
        } else if (swaps[i] == '-') {
            second = !second;
        } else if (second) {
            buf2 += swaps[i];
        } else {
            buf += swaps[i];
        }
    }
    for (i = 0; i < nums.size(); i++) {
        cout << nums.at(i);
        if (i != nums.size()-1) {
            cout << " ";
        }
    }
    cout << endl;
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

