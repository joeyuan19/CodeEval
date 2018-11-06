#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string trim(string s) {
    int start = s.find_first_not_of(" \n\t\v\f\r");
    int end   = s.find_last_not_of(" \n\t\v\f\r");
    return s.substr(start,end-start+1);
}

string LCS(string s) {
    string a, b, tmp, m_tmp;
    int div = s.find(";");
    a = s.substr(0,div);
    b = s.substr(div+1,s.size()-div-1);
    int last, i, j, k, m = 0;
    for (k = 0; k < a.size(); k++) {
        last = b.find(a[k]);
        if (last != string::npos) {
            tmp = "";
            for (i = k; i < a.size(); i++) {
                for (j = last; j < b.size(); j++) {
                    if (a[i] == b[j]) {
                        last = j;
                        tmp += a[i];
                        break;
                    }
                }
            }
            tmp = trim(tmp);
            if (tmp.size() > m) {
                m_tmp = tmp;
                m = tmp.size();
            }
        }
    }
    return m_tmp;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    while (getline(f,line)) {
        if (line.size() > 0) {
            cout << LCS(line) << endl;
        }
    }
    f.close();
    return 0;
}
