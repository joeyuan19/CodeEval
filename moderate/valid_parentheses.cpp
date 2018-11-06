#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    string stack = "";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == '(' || line[i] == '[' || line[i] == '{') {
            stack += line[i];
        } else if (line[i] == ')') {
            if (stack.size() > 0 && stack[stack.size()-1] == '(') {
                stack = stack.substr(0,stack.size()-1);
            } else {
                cout << "False" << endl;
                return;
            }
        } else if (line[i] == ']') {
            if (stack.size() > 0 && stack[stack.size()-1] == '[') {
                stack = stack.substr(0,stack.size()-1);
            } else {
                cout << "False" << endl;
                return;
            }
        } else if (line[i] == '}') {
            if (stack.size() > 0 && stack[stack.size()-1] == '{') {
                stack = stack.substr(0,stack.size()-1);
            } else {
                cout << "False" << endl;
                return;
            }
        }
    }
    if (stack.size() == 0) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
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
