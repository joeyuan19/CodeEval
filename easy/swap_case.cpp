#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char swap(char c) {
    if (c >= 'a' && c <= 'z') {
        return c-'a'+'A';
    } else if (c >= 'A' && c <= 'Z') {
        return c-'A'+'a';
    } else {
        return c;
    }
}

void process(string line) {
    for (int i = 0; i < line.size(); i++) {
        cout << swap(line[i]);
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

