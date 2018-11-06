#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void print(vector<int> * v) {
    for (int i = 0; i < v->size(); i++) {
        cout << v->at(i);
    }
    cout << endl;
}

vector<int> toVector(int n) {
    vector<int> v;
    int tmp = n;
    while (tmp > 0) {
        v.insert(v.begin(),tmp%10);
        tmp = tmp/10;
    }
    return v;
}

void reverse(vector<int> * v) {
    int tmp;
    for (int i = 0; i < v->size()/2; i++) {
        tmp = v->at(i);
        v->operator[](i) = v->at(v->size()-1-i);
        v->operator[](v->size()-1-i) = tmp;
    }
}

bool palindrome(vector<int> * v) {
    for (int i = 0; i < v->size()/2; i++) {
        if (v->at(i) != v->at(v->size()-1-i)) {
            return false;
        }
    }
    return true;
}

void add(vector<int> * a, vector<int> * b) {
    int tmp = 0, s = 0;
    int i, j;
    for (i = a->size()-1, j = b->size()-1; j >= 0; i--, j--) {
        if (i >= 0) {
            s = a->at(i) + b->at(j) + tmp;
            a->operator[](i) = s%10;
            tmp = s/10;
        } else {
            s = b->at(j) + tmp;
            a->insert(a->begin(),s%10);
            tmp = s/10;
        }
    }
    while (tmp > 0) {
        if (i >= 0) {
            s = a->at(i) + tmp;
            a->operator[](i) = s%10;
            tmp = s/10;
            i--;
        } else {
            s = tmp;
            a->insert(a->begin(),s%10);
            tmp = s/10;
        }
    }
}

void reverseAndAdd(vector<int> * a) {
    vector<int> tmp;
    int start = false;
    for (int i = a->size()-1; i >= 0; i--) {
        if (start) {
            tmp.push_back(a->at(i));
        } else if (!start && a->at(i) != 0) {
            start = true;
            tmp.push_back(a->at(i));
        }
    }
    add(a,&tmp);
}

bool isLycheral(int N, int limit) {
    vector<int> n;
    n = toVector(N);
    int i;
    for (i = 0; i < limit; i++) {
        reverseAndAdd(&n);
        if (palindrome(&n)) {
            cout << (i+1) << " ";
            print(&n);
            return false;
        }
    }
    return true;
}

void process(string line) {
    int tmp;
    stringstream(line) >> tmp;
    isLycheral(tmp,100);
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
