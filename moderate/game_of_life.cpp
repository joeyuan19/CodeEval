#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 100;
const int M = 100;

int main(int argc, char *argv[]) {
    int board [N][M];
    int last [N][M];
    ifstream f (argv[1]);
    string line;
    int n = 0, i, j, tmp;
    while (getline(f,line)) {
        for (i = 0; i < line.size(); i++) {
            tmp = line[i] == '*' ? 1 : 0;
            board[n][i] = tmp;
            last[n][i] = tmp;
        }
        n++;
    }
    f.close();
    int s, l, k;
    int runs = 10;
    for (n = 0; n < runs; n++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                s = 0;
                for (l = -1; l < 2; l++) {
                    for (k = -1; k < 2; k++) {
                        if (!( (l == 0 && k == 0) || (i+l) < 0 || (i+l) > N-1 || (j+k) < 0 || (j+k) > M-1 )) {
                            s += last[i+l][j+k];
                        }
                    }
                }
                if (last[i][j] == 1) {
                    if (s < 2) {
                        board[i][j] = 0;
                    } else if (s > 3) {
                        board[i][j] = 0;
                    }
                } else if (s == 3) {
                    board[i][j] = 1;
                }
            }
        }
        if (n < runs-1) {
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    last[i][j] = board[i][j];
                }
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cout << (board[i][j] == 1 ? '*' : '.');
        }
        cout << endl;
    }
    return 0;
}

