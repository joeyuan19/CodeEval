#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void process(string line) {
    int letters [26], i;
    for (i = 0; i < 26; i++) {
        letters[i] = 0;
    }
    for (i = 0; i < line.size(); i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            letters[((int)(line[i]-'a'))] = 1;
        } else if (line[i] >= 'A' && line[i] <= 'Z') {
            letters[((int)(line[i]-'A'))] = 1;
        }
    }
    string out = "";
    for (i = 0; i < 26; i++) {
        if (letters[i] == 0) {
            out += ((char)('a'+i));
        }
    }
    if (out.size() > 0) {
        cout << out << endl;
    } else {
        cout << "NULL" << endl;
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

