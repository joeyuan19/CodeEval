#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void process(string line) {
    string buf = "", words = "", nums = "";
    int i, j;
    for (i = 0; i <= line.size(); i++) {
        if (line[i] == ',') {
            for (j = 0; j < buf.size(); j++) {
                if ( !(buf[j] <= '9' && buf[j] >= '0') ) {
                    words += buf + ",";
                    break;
                }
            }
            if (j == buf.size()) {
                nums += buf + ",";
            }
            buf = "";
        } else if (('0' <= line[i] && '9' >= line[i]) || ('A' <= line[i] && 'Z' >= line[i]) || ('a' <= line[i] && 'z' >= line[i])) {
            buf += line[i];
        }
    }
    if (buf.size() > 0) {
        for (j = 0; j < buf.size(); j++) {
            if (!(buf[j] <= '9' && buf[j] >= '0')) {
                words += buf + ",";
                break;
            }
        }
        if (j == buf.size()) {
            nums += buf + ",";
        }
        buf = "";
    }
    if (words[words.size()-1] == ',') {
        words = words.substr(0,words.size()-1);
    }
    if (nums[nums.size()-1] == ',') {
        nums = nums.substr(0,nums.size()-1);
    }
    if (nums.size() > 0 && words.size() > 0) {
        cout << (words + "|" + nums) << endl;
    } else if (nums.size() > 0) {
        cout << nums << endl;
    } else if (words.size() > 0) {
        cout << words << endl;
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

