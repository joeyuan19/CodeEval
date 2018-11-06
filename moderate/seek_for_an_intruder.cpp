#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string to_string(int n) {
    ostringstream ss;
    ss << n;
    return ss.str();
}

string to_string(long n) {
    ostringstream ss;
    ss << n;
    return ss.str();
}

string to_string(unsigned long n) {
    ostringstream ss;
    ss << n;
    return ss.str();
}

bool isOctal(string n) {
    for (int i = 0; i < n.size(); i++) {
        if (n[i] < '0' || n[i] > '7') {
            return false;
        }
    }
    return true;
}

unsigned long fromOct(string o) {
    unsigned long p = 1;
    unsigned long a = 0;
    for (int i = o.size()-1; i >= 0; i--) {
        a += ((int)(o[i]-'0'))*p;
        p = p*8;
    }
    return a;
}

bool isHex(string h) {
    string n;
    if (h[0] == '0' && (h[1] == 'x' || h[1] == 'X')) {
        n = h.substr(2,h.size()-2);
    } else {
        n = h;
    }
    for (int i = 0; i < n.size(); i++) {
        if ( !( (n[i] >= '0' && n[i] <= '9') || (n[i] >= 'a' && n[i] <= 'f') || (n[i] >= 'A' && n[i] <= 'F')) ) {
            return false;
        }
    }
    return true;
}

unsigned long fromHex(string h) {
    unsigned long p = 1;
    unsigned long a = 0;
    for (int i = h.size()-1; i >= 0; i--) {
        if (h[i] >= '0' && h[i] <= '9') {
            a += ((int)(h[i]-'0'))*p;
        } else if (h[i] >= 'a' && h[i] <= 'f') {
            a += (10+(int)(h[i]-'a'))*p;
        } else if (h[i] >= 'A' && h[i] <= 'F') {
            a += (10+(int)(h[i]-'A'))*p;
        }
        p = p*16;
    }
    return a;
}

bool isBinary(string n) {
    for (int i = 0; i < n.size(); i++) {
        if (n[i] != '0' && n[i] != '1') {
            return false;
        }
    }
    return true;
}

int fromBin(string b) {
    int p = 1;
    int a = 0;
    for (int i = b.size()-1; i >= 0; i--) {
        if (b[i] == '1') {
            a += p;
        }
        p = p*2;
    }
    return a;
}

bool isDec(string n) {
    for (int i = 0; i < n.size(); i++) {
        if (n[i] < '0' || n[i] > '9') {
            return false;
        }
    }
    return true;
}

unsigned long fromDec(string d) {
    unsigned long a;
    stringstream(d) >> a;
    return a;
}

string toBin(unsigned long n) {
    const int size = sizeof(n)*sizeof(unsigned long);
    string out = "";
    bool s = false;
    for (int i = 0; i < size; i++) {
        bool bit = n >> (size-1);
        if (bit) {
            s = true;
        }
        if (s) {
            out.push_back(bit+'0');
        }
        n<<=1;
    }
    if (!out.size()) {
        out.push_back('0');
    }
    return out;
}

string getValidBinary(string ip) {
    if (ip.size() < 25 || !isBinary(ip)) {
        return "";
    }
    string buf = "";
    int tmp;
    buf = ip.substr(ip.size()-8,8);
    tmp = fromBin(buf);
    if (tmp < 0 || tmp > 254) {
        return "";
    }
    string out = "." + to_string(tmp);
    buf = "";
    int itr = 1;
    for (int i = ip.size()-9; i >= 0; i--) {
        if (buf.size() == 8) {
            tmp = fromBin(buf);
            if (tmp < 0 || tmp > 255) {
                return "";
            }
            buf = ip[i];
            out = "." + to_string(tmp) + out;
            itr++;
            if (itr > 3) {
                return "";
            }
        } else {
            buf = ip[i] + buf;
        }
    }
    tmp = fromBin(buf);
    if (tmp < 1 || tmp > 255) {
        return "";
    }
    return to_string(tmp) + out;
}


string getValidOctal(string ip) {
    if (!isOctal(ip) || ip.size() > 11 || ip.size() < 9 || (ip.size() == 11 && ip[0] > '3')) {
        return "";
    }
    return getValidBinary(toBin(fromOct(ip)));
}

string getValidDottedBinary(string ip) {
    if (ip.size() != 35 || ip[8] != '.' || ip[17] != '.' || ip[26] != '.') {
        return "";
    }
    string buf = ip.substr(0,8);
    if (!isBinary(buf)) {
        return "";
    }
    int tmp = fromBin(buf);
    if (tmp < 1 || tmp > 255) {
        return "";
    }
    string out = to_string(tmp) + ".";
    int itr = 0;
    buf = "";
    for (int i = 9; i < ip.size(); i++) {
        if (ip[i] == '.') {
            if (buf.size() != 8) {
                return "";
            }
            tmp = fromBin(buf);
            if (tmp < 0 || tmp > 255) {
                return "";
            }
            out += to_string(tmp) + ".";
            buf = "";
        } else if (ip[i] == '0' || ip[i] == '1') {
            buf += ip[i];
        } else {
            return "";
        }
    }
    if (buf.size() != 8) {
        return "";
    }
    tmp = fromBin(buf);
    if (tmp < 0 || tmp > 254) {
        return "";
    }
    return out + to_string(tmp);
}

string getValidDottedOctal(string ip) {
    if (ip.size() != 19 || ip[4] != '.' || ip[9] != '.' || ip[14] != '.') {
        return "";
    }
    unsigned long tmp;
    string buf = ip.substr(0,4);
    if (!isOctal(buf)) {
        return "";
    }
    tmp = fromOct(buf);
    if (tmp > 255 || tmp < 1) {
        return "";
    }
    string out = to_string(tmp) + ".";
    buf = "";
    int itr = 1;
    for (int i = 5; i < ip.size(); i++) {
        if (ip[i] == '.') {
            if (itr >= 3) {
                return "";
            }
            tmp = fromOct(buf);
            if (tmp > 255 || tmp < 0) {
                return "";
            }
            out += to_string(tmp) + ".";
            buf = "";
            itr++;
        } else if (ip[i] >= '0' && ip[i] <= '7') {
            buf += ip[i];
        } else {
            return "";
        }
    }
    if (itr != 3 || buf.size() != 4) {
        return "";
    }
    tmp = fromOct(buf);
    if (tmp > 254 || tmp < 0) {
        return "";
    }
    return out + to_string(tmp);
}

string getValidHex(string ip) {
    if (ip[0] != '0' || (ip[1] != 'x' && ip[1] != 'X')) {
        return "";
    }
    ip = ip.substr(2,ip.size()-2);
    if (!isHex(ip) || ip.size() > 8 || ip.size() < 7) {
        return "";
    }
    return getValidBinary(toBin(fromHex(ip)));
}

string getValidDottedHex(string ip) {
    if (ip.size() < 15 || ip.size() > 19 || ip[0] != '0' || (ip[1] != 'x' && ip[1] != 'X')) {
        return "";
    }
    int idx = ip.find(".");
    if (idx == string::npos) {
        return "";
    }
    string buf = ip.substr(0,idx);
    if (!isHex(buf)) {
        return "";
    }
    unsigned long tmp = fromHex(buf);
    if (tmp < 1 || tmp > 255) {
        return "";
    }
    string out = to_string(tmp) + ".";
    int itr = 1;
    buf = "";
    for (int i = idx+1; i < ip.size(); i++) {
        if (ip[i] == '.') {
            if (itr >= 3 || buf[0] != '0' || (buf[1] != 'x' && buf[1] != 'X') || buf.size() < 3) {
                return "";
            }
            tmp = fromHex(buf);
            if (tmp < 0 || tmp > 255) {
                return "";
            }
            out += to_string(tmp) + ".";
            itr++;
            buf = "";
        } else if ( ip[i] == 'X' || ip[i] == 'x' || (ip[i] >= '0' && ip[i] <= '9') || (ip[i] >= 'a' && ip[i] <= 'f')) {
            buf += ip[i];
        } else {
            return "";
        }
    }
    if (itr != 3 || buf.size() < 3 || buf[0] != '0' || (buf[1] != 'x' && buf[1] != 'X')) {
        return "";
    }
    tmp = fromHex(buf);
    if (tmp < 0 || tmp > 254) {
        return "";
    }
    return out + to_string(tmp);
}

string getValidDecimal(string ip) {
    if (ip.size() > 10 || ip.size() < 8 || !isDec(ip) || (ip.size() == 10 && ip[0] > '4')) {
        return "";
    }
    return getValidBinary(toBin(fromDec(ip)));
}

string getValidDottedDecimal(string ip) {
    if (ip.size() > 15 || ip.size() < 7) {
        return "";
    }
    int idx = ip.find(".");
    if (idx == string::npos) {
        return "";
    }
    string buf = ip.substr(0,idx);
    if (!isDec(buf)) {
        return "";
    }
    unsigned long tmp = fromDec(buf);
    if (tmp < 1 || tmp > 255) {
        return "";
    }
    int itr = 1;
    buf = "";
    for (int i = idx+1; i < ip.size(); i++) {
        if (ip[i] == '.') {
            if (itr >= 3 || buf.size() == 0) {
                return "";
            }
            tmp = fromDec(buf);
            if (tmp < 0 || tmp > 255) {
                return "";
            }
            itr++;
            buf = "";
        } else if (ip[i] >= '0' && ip[i] <= '9') {
            buf += ip[i];
        } else {
            return "";
        }
    }
    if (itr != 3 || buf.size() == 0) {
        return "";
    }
    tmp = fromDec(buf);
    if (tmp < 0 || tmp > 254) {
        return "";
    }
    return ip;
}

void addValidIPs(map<string,int> * ips, string ip) {
    // Binary
    string rip = "";
    if ((rip = getValidBinary(ip)).size() > 0) {
        if (ips->find(rip) == ips->end()) {
            ips->operator[](rip) = 1;
        } else {
            ips->operator[](rip)++;
        }
    }
    // Dotted Binary
    rip = "";
    if ((rip = getValidDottedBinary(ip)).size() > 0) {
        if (ips->find(rip) == ips->end()) {
            ips->operator[](rip) = 1;
        } else {
            ips->operator[](rip)++;
        }
    }
    // Octal
    rip = "";
    if ((rip = getValidOctal(ip)).size() > 0) {
        if (ips->find(rip) == ips->end()) {
            ips->operator[](rip) = 1;
        } else {
            ips->operator[](rip)++;
        }
    }
    // Dotted Octal
    rip = "";
    if ((rip = getValidDottedOctal(ip)).size() > 0) {
        if (ips->find(rip) == ips->end()) {
            ips->operator[](rip) = 1;
        } else {
            ips->operator[](rip)++;
        }
    }
    // Hex
    rip = "";
    if ((rip = getValidHex(ip)).size() > 0) {
        if (ips->find(rip) == ips->end()) {
            ips->operator[](rip) = 1;
        } else {
            ips->operator[](rip)++;
        }
    }
    // Dotted Hex
    rip = "";
    if ((rip = getValidDottedHex(ip)).size() > 0) {
        if (ips->find(rip) == ips->end()) {
            ips->operator[](rip) = 1;
        } else {
            ips->operator[](rip)++;
        }
    }
    // Decimal
    rip = "";
    if ((rip = getValidDecimal(ip)).size() > 0) {
        if (ips->find(rip) == ips->end()) {
            ips->operator[](rip) = 1;
        } else {
            ips->operator[](rip)++;
        }
    }
    // Dotted Decimal
    rip = "";
    if ((rip = getValidDottedDecimal(ip)).size() > 0) {
        if (ips->find(rip) == ips->end()) {
            ips->operator[](rip) = 1;
        } else {
            ips->operator[](rip)++;
        }
    }
}

bool isValidChar(char c) {
    return (c >= '0' && c <= '9') || c == '.' || c == 'x' || c == 'X' || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int compare(string IP1, string IP2) {
    string ip1 = IP1 + ".", ip2 = IP2 + ".";
    int li = -1, lj = -1, i, j;
    int n1, n2;
    while (i != string::npos && j != string::npos) {
        i = ip1.find(".",li+1);
        j = ip2.find(".",lj+1);
        stringstream(ip1.substr(li+1,i-(li+1))) >> n1;
        stringstream(ip2.substr(lj+1,j-(lj+1))) >> n2;
        if (n1 > n2) {
            return 1;
        } else if (n1 < n2) {
            return -1;
        }
        li = i;
        lj = j;
    }
    if (i == string::npos && j == string::npos) {
        return 0;
    } else if (i == string::npos) {
        return 1;
    } else if (j == string::npos) {
        return -1;
    } else {
        return 0;
    }
}

void sort(vector<string> * ips) {
    bool swap = true;
    string tmp;
    int i;
    while (swap) {
        swap = false;
        for (i = 0; i < ips->size()-1; i++) {
            if (compare(ips->at(i),ips->at(i+1)) > 0) {
                tmp = ips->at(i);
                ips->operator[](i) = ips->at(i+1);
                ips->operator[](i+1) = tmp;
                swap = true;
            }
        }
    }
}

void process(string text) {
    text += " ";
    map<string,int> ips;
    string buf = "", ip;
    int i, j;
    for (i = 0; i < text.size(); i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            buf = "";
            j = i;
            while (buf.size() <= 35 && isValidChar(text[j])) {
                buf += text[j];
                j++;
            }
            addValidIPs(&ips, buf);
        }
    }
    int m = 0;
    vector<string> max;
    for (map<string,int>::iterator itr = ips.begin(); itr != ips.end(); ++itr) {
        if (m < itr->second) {
            m = itr->second;
        }
    }
    for (map<string,int>::iterator itr = ips.begin(); itr != ips.end(); ++itr) {
        if (m == itr->second) {
            max.push_back(itr->first);
        }
    }
    sort(&max);
    for (i = 0; i < max.size()-1; i++) {
        cout << max.at(i) << " ";
    }
    cout << max.at(i) << endl;
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line, text = "";
    while (getline(f,line)) {
        text += line;
    }
    f.close();
    process(text);
    return 0;
}

