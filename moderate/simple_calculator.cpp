#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void compute(vector<string> * stack);

bool isNumber(string s) {
    int i, d = 0;
    if (s[0] == '-') {
        i = 1;
    } else {
        i = 0;
    }
    for (; i < s.size(); i++) {
        if (s[i] == '.' || (s[i] <= '9' && s[i] >= '0')) {
        } else {
            return false;
        }
    }
    return true;
}

string STZ(string s) {
    int n = s.find(".");
    if (n != string::npos) {
        while (s.back() == '0') {
            s.pop_back();
        }
        if (s.back() == '.') {
            s.pop_back();
        }
    }
    return s;
}

string format(string s) {
    int dec = 5;
    int idx = s.find(".");
    if (idx != string::npos) {
        if (s.size()-idx <= dec) {
            return STZ(s);
        } else {
            if (s[idx+dec+1] >= '5' && s[idx+dec+1] <= '9') {
                int itr = 0;
                while (idx+dec-itr >= 0 && s[idx+dec-itr] == '9') {
                    s[idx+dec-itr] = '0';
                    itr++;
                    if (itr == dec) {
                        itr++;
                    }
                }
                if (idx+dec-itr < 0) {
                    s = "1"+s;
                    idx++;
                } else {
                    s[idx+dec-itr] = s[idx+dec-itr]+1;
                }
            }
            return STZ(s.substr(0,idx+dec+1));
        }
    } else {
        return s;
    }
}

string to_string(long double x) {
    ostringstream ss;
    ss << x;
    return ss.str();
}

bool isValid(char c) {
    switch (c) {
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '^':
            return true;
        default:
            return false;
    
    }
}

bool isValid(string s) {
    if (s.size() != 1) {
        return false;
    } else {
        return isValid(s[0]);
    }
}

bool isOperator(string s) {
    return s.compare("^") == 0 || s.compare("-") == 0 || s.compare("+") == 0 || s.compare("*") == 0 || s.compare("/") == 0;
}

void print(vector<string> * v) {
    for (int i = 0; i < v->size(); i++) {
        cout << v->at(i) << " ";
    } cout << endl;
}


void p(vector<string> * stack) {
    int i = 0;
    while (i < stack->size()) {
        if (stack->at(i).compare("(") == 0) {
            string buf = "(";
            stack->erase(stack->begin()+i);
            vector<string> sub;
            while (buf.size() > 0 && i < stack->size()) {
                if (stack->at(i).compare(")") == 0) {
                    buf.pop_back();
                    if (buf.size() > 0) {
                        sub.push_back(stack->at(i));
                    }
                    stack->erase(stack->begin()+i);
                } else {
                    if (stack->at(i).compare("(") == 0) {
                        buf += "(";
                    }
                    sub.push_back(stack->at(i));
                    stack->erase(stack->begin()+i);
                }
            }
            compute(&sub);
            stack->insert(stack->begin()+i,sub.back());
        } else {
            i++;
        }
    }
}

string exp(string X, string E) {
    long double x, e, r;
    stringstream(X) >> x;
    stringstream(E) >> e;
    r = pow(x,e);
    return to_string(r);
}

void e(vector<string> * stack) {
    int i = 0;
    while (i < stack->size()) {
        if (stack->at(i).compare("^") == 0) {
            string r = exp(stack->at(i-1),stack->at(i+1));
            stack->erase(stack->begin()+i+1);
            stack->erase(stack->begin()+i);
            stack->erase(stack->begin()+i-1);
            stack->insert(stack->begin()+i-1,r);
        } else {
            i++;
        }
    }
}

string mul(string A, string B) {
    long double a, b, r;
    stringstream(A) >> a;
    stringstream(B) >> b;
    r = a*b;
    return to_string(r);
}

string div(string A, string B) {
    long double a, b, r;
    stringstream(A) >> a;
    stringstream(B) >> b;
    r = a/b;
    return to_string(r);
}

void md(vector<string> * stack) {
    int i = 0;
    while (i < stack->size()) {
        if (stack->at(i).compare("/") == 0) {
            string r = div(stack->at(i-1),stack->at(i+1));
            stack->erase(stack->begin()+i+1);
            stack->erase(stack->begin()+i);
            stack->erase(stack->begin()+i-1);
            stack->insert(stack->begin()+i-1,r);
        } else if (stack->at(i).compare("*") == 0) {
            string r = mul(stack->at(i-1),stack->at(i+1));
            stack->erase(stack->begin()+i+1);
            stack->erase(stack->begin()+i);
            stack->erase(stack->begin()+i-1);
            stack->insert(stack->begin()+i-1,r);
        } else {
            i++;
        }
    }
}

string add(string A, string B) {
    long double a, b, r;
    stringstream(A) >> a;
    stringstream(B) >> b;
    r = a+b;
    return to_string(r);
}

string sub(string A, string B) {
    double a, b, r;
    stringstream(A) >> a;
    stringstream(B) >> b;
    r = a-b;
    return to_string(r);
}

void as(vector<string> * stack) {
    int i = 0;
    while (i < stack->size()) {
        if (stack->at(i).compare("+") == 0) {
            string r = add(stack->at(i-1),stack->at(i+1));
            stack->erase(stack->begin()+i+1);
            stack->erase(stack->begin()+i);
            stack->erase(stack->begin()+i-1);
            stack->insert(stack->begin()+i-1,r);
        } else if (stack->at(i).compare("-") == 0) {
            string r = sub(stack->at(i-1),stack->at(i+1));
            stack->erase(stack->begin()+i+1);
            stack->erase(stack->begin()+i);
            stack->erase(stack->begin()+i-1);
            stack->insert(stack->begin()+i-1,r);
        } else {
            i++;
        }
    }
}

void um(vector<string> * stack) {
    int i = 0;
    while (i < stack->size()) {
        if (stack->at(i).compare("-") == 0 && isNumber(stack->at(i+1)) && (i == 0 || isValid(stack->at(i-1)))) {
            stack->operator[](i+1) = mul("-1",stack->at(i+1));
            stack->erase(stack->begin()+i);
        } else {
            i++;
        }
    }
}

void compute(vector<string> * stack) {
    while (stack->size() > 1) {
        cout << "start: ";
        print(stack);
        um(stack);
        cout << "unary minus: ";
        print(stack);
        p(stack);
        cout << "(): ";
        print(stack);
        e(stack);
        cout << "^: ";
        print(stack);
        md(stack);
        cout << "*/: ";
        print(stack);
        as(stack);
        cout << "+-: ";
        print(stack);
    }
}

string compute(string phrase) {
    string buf = "";
    vector<string> stack;
    for (int i = 0; i < phrase.size(); i++) {
        if ((phrase[i] >= '0' && phrase[i] <= '9') || phrase[i] == '.') {
            while (i < phrase.size() && ((phrase[i] >= '0' && phrase[i] <= '9') || phrase[i] == '.')) {
                buf += phrase[i];
                i++;
            }
            stack.push_back(buf);
            buf = "";
            i--;
        } else if (isValid(phrase[i])) {
            buf = "";
            buf += phrase[i];
            stack.push_back(buf);
            buf = "";
        }
    }
    compute(&stack);
    return stack.back();
}


void process(string line) {
    cout << format(compute(line)) << endl;
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

