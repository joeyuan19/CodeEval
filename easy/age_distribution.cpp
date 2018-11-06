#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void range(int n) {
    if (n < 0) {
        cout << "This program is for humans" << endl;
    } else if (n < 3) {
        cout << "Still in Mama's arms" << endl;
    } else if (n < 5) {
        cout << "Preschool Maniac" << endl;
    } else if (n < 12) {
        cout << "Elementary school" << endl;
    } else if (n < 15) {
        cout << "Middle school" << endl;
    } else if (n < 19) {
        cout << "High school" << endl;
    } else if (n < 23) {
        cout << "College" << endl;
    } else if (n < 65) {
        cout << "Working for the man" << endl;
    } else if (n < 100) {
        cout << "The Golden Years" << endl;
    } else {
        cout << "This program is for humans" << endl;
    }
}

void process(string line) {
    int tmp;
    stringstream(line) >> tmp;
    range(tmp);
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

