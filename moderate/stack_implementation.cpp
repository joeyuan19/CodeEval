#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Stack {
    vector<string> s;
    public:
        Stack() {
            s.clear();
        };
        void push(string x) {
            s.push_back(x);
        };
        string pop() {
            string tmp = s.back();
            s.pop_back();
            return tmp;
        };
        int size() {
            return s.size();
        };
        bool isEmpty() {
            return s.size() == 0;
        };
};

void process(string line) {
    line = line + " ";
    string buf = "", out = "";
    int i;
    Stack s;
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            s.push(buf);
            buf = "";
        } else {
            buf += line[i];
        }
    }
    for (i = 0; s.size() > 2; i++) {
        if (i%2 == 0) {
            cout << s.pop() << " ";
        } else {
            s.pop();
        }
    }
    if (i%2 == 0) {
        cout << s.pop() << endl;
    } else {
        s.pop();
        cout << s.pop() << endl;
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

