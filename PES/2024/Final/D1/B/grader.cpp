#include "Laberinto.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> mover(int x);

vector<int> Pista(int N, vector<vector<int>> Laberinto);

void Juego(vector<int> P);

// GRADER

// las posiciones de inicio y fin son: [n - 2][1] -> [1][n - 2]

// mover:
// 0, abajo:     [x][y] -> [x + 1][y]
// 1, derecha:   [x][y] -> [x][y + 1]
// 2, arriba:    [x][y] -> [x - 1][y]
// 3, izquierda: [x][y] -> [x][y - 1]

string filename = "sub0.1.in";
int cnt, X, Y, N, PJ, M, P, T;
vector<vector<int>> Lab;

vector<int> estado() {
    vector<int> v = {0, 0, 0, 0};
    if (Lab[Y + 1][X]) v[0] = 1;
    if (Lab[Y][X + 1]) v[1] = 1;
    if (Lab[Y - 1][X]) v[2] = 1;
    if (Lab[Y][X - 1]) v[3] = 1;
    return v;
}

vector<int> mover(int x) {
    vector<int> v = estado();
    if (x == -1 || x == 4) return v;
    cnt++;
    if (x == 0 && v[x] == 1) Y++;
    if (x == 1 && v[x] == 1) X++;
    if (x == 2 && v[x] == 1) Y--;
    if (x == 3 && v[x] == 1) X--;
    return estado();
}

int evalua() {
    int ans = 2*(M + 2) - P;
    ans *= 100;
    ans /= (2*(M + 2) - PJ);
    ans = min(max(ans, 0), 100);
    return ans;
}

int main() {
    ifstream infile(filename);
    infile >> T;
    for (int t = 1; t <= T; t++) {

        infile >> N;

        Lab = vector<vector<int>> (N, vector<int> (N, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                infile >> Lab[i][j];

        infile >> M >> PJ;

        X = 1;
        Y = N - 2;
        cnt = 0;

        auto vv = Pista(N, Lab);
        P = vv.size();
        Juego(vv);

        cout << "Caso " << t << ": " << evalua() << "%\n";

        Lab.clear();
    }
    return 0;
}
