#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class sub {
    string val;
    int idx;
};

bool valid(string s) {
    if (s.size() == 2) {
        return (s[0] == '1' && s[1] >= '0' && s[1] <= '9') || (s[0] == '2' && s[1] >= '0' && s[1] <= '6');
    } else if (s.size() == 1) {
        return s[0] >= '0' && s[0] <= '9';
    } else {
        return false;
    }
}


void process(string line) {
    int i, j, k;
    vector<string> stack = {line.substr(0,1)};
    int size = 1;
    sub tmp;
    int c = 0;
    while (stack.size() > 0) {
        if (!valid(stack.back())) {
            if (size < line.size() && stack.back().size() == 1) {
                stack.back() += line[size];
                size++;
            } else {
                while (stack.size() > 0 && stack.back().size() == 2) {
                    size -= 2;
                    stack.pop_back();
                }
                if (stack.size() > 0) {
                    stack.back() += line[size];
                    size++;
                }
            }
        } else if (size == line.size()) {
            c++;
            if (stack.back().size() == 1) {
                stack.pop_back();
                size--;
            }
            while (stack.size() > 0 && stack.back().size() == 2) {
                size -= 2;
                stack.pop_back();
            }
            if (stack.size() > 0) {
                stack.back() += line[size];
                size++;
            }
        } else {
            stack.push_back(line.substr(size,1));
            size++;
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

