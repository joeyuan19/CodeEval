#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string to_string(long double n) {
    ostringstream ss;
    ss << n;
    return ss.str();
}

class MapPoint {
    public:
        double distance;
        double angle;
};

class Result {
    public:
        long double time;
        int racer;
};

string format(double long n) {
    string s = to_string(n);
    int idx = s.find(".");
    if (s.size()-idx == 1) {
        return s+"00";
    } else if (s.size()-idx == 2) {
        return s+"0";
    } else if (s.size()-idx == 3) {
        return s;
    } else {
        if (s[idx+3] >= '5' && s[idx+3] <= '9') {
            int itr = 0;
            while (idx+2-itr >= 0 && s[idx+2-itr] == '9') {
                s[idx+2-itr] = '0';
                itr++;
                if (itr == 2) {
                    itr++;
                }
            }
            if (idx+2-itr < 0) {
                s = "1"+s;
                idx++;
            } else {
                s[idx+2-itr] = s[idx+2-itr]+1;
            }
        }
        return s.substr(0,idx+3);
    }
}

void sort(vector<Result> * v) {
    bool swap = true;
    int racer_tmp, i;
    long double time_tmp;
    while (swap) {
        swap = false;
        for (i = 0; i < v->size()-1; i++) {
            if (v->at(i).time > v->at(i+1).time) {
                racer_tmp = v->at(i).racer;
                time_tmp  = v->at(i).time;

                v->at(i).racer = v->at(i+1).racer;
                v->at(i).time  = v->at(i+1).time;
                
                v->at(i+1).racer = racer_tmp;
                v->at(i+1).time  = time_tmp;
                
                swap = true;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream f (argv[1]);
    string line;
    vector<MapPoint> track;
    getline(f,line);
    int i;
    string buf = "";
    bool dd = true;
    line += " ";
    for (i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            if (dd) {
                MapPoint p;
                track.push_back(p);
                stringstream(buf) >> track.back().distance;
            } else {
                stringstream(buf) >> track.back().angle;
            }
            buf = "";
            dd = !dd;
        } else {
            buf += line[i];
        }
    }
    map<int,long double> speed;
    map<int,long double> acc;
    map<int,long double> dec;
    int cars = 0, itr, n;
    long double tmp;
    while (getline(f,line)) {
        line += " ";
        itr = 0;
        buf = "";
        for (i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                if (itr == 0) {
                    stringstream(buf) >> n;
                } else if (itr == 1) {
                    stringstream(buf) >> tmp;
                    speed[n] = tmp/(60.*60.);
                } else if (itr == 2) {
                    stringstream(buf) >> tmp;
                    acc[n] = tmp;
                } else if (itr == 3) {
                    stringstream(buf) >> tmp;
                    dec[n] = tmp;
                }
                buf = "";
                itr++;
            } else {
                buf += line[i];
            }
        }
        cars++;
    }
    f.close();
    long double vi, vf, t, dt, dx, a, d, m;
    vector<Result> results;
    for (i = 1; i < cars+1; i++) {
        vi = 0;
        t = 0;
        m = speed[i];
        a = m/acc[i];
        d = -m/dec[i];
        for (n = 0; n < track.size(); n++) {
            dt = (m - vi)/a;
            dx = vi*dt + .5*a*dt*dt;
            t += dt;
            
            vf = m*(1.0 - (track[n].angle/180.0));
            dt = (vf - m)/d;
            t += dt;
            dx += m*dt + .5*d*dt*dt;
            
            dt = (track[n].distance-dx)/m;
            t += dt;
            
            vi = vf;
        }
        Result r;
        r.time = t;
        r.racer = i;
        results.push_back(r);
    }
    sort(&results);
    for (i = 0; i < results.size(); i++) {
        cout << results.at(i).racer << " " << format(results.at(i).time) << endl;
    }
    return 0;
}

