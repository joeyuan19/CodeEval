#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool balanced(string stack, int level = 0) {
    if (stack.size() == 0) {
        return true;
    } else if (stack.back() == ')') {
        for (int i = stack.size()-2; i >= 0; i--) {
            if (stack[i] == '(' &&
                    balanced(stack.substr(i+1,stack.size()-i-2),level+1) &&
                    balanced(stack.substr(0,i),level+1)) {
                return true;
            }
        }
        if (stack.size() > 1 && stack[stack.size()-2] == ':') {
            return balanced(stack.substr(0,stack.size()-2),level+1);
        } else {
            return false;
        }
    } else if (stack.back() == '(' && stack.size() > 1 && stack[stack.size()-2] != ':') {
        return false;    
    } else {
        return balanced(stack.substr(0,stack.size()-1),level+1);
    }
    return false;
}

void process(string line) {
    if (balanced(line)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
