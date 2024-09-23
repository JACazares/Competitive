#include <bits/stdc++.h>

using namespace std;

long long Encuentra_xor(int N, vector<int> u, vector<int> v, vector<int> w);

// GRADER
string filename = "sub0.1.in";
int N, T, aux;
long long ANS;
vector <int> U, V, W;

int main() {
    ifstream infile(filename);
    infile >> T;
    for (int t = 1; t <= T; t++) {
        infile >> N;
        for (int i = 0; i < N - 1; i++) {
            infile >> aux;
            U.push_back(aux);
        }
        for (int i = 0; i < N - 1; i++) {
            infile >> aux;
            V.push_back(aux);
        }
        for (int i = 0; i < N - 1; i++) {
            infile >> aux;
            W.push_back(aux);
        }

        infile >> ANS;

        cout << "Caso " << t << ": ";
        switch (ANS == Encuentra_xor(N, U, V, W)) {
            case 1:
                cout << "Respuesta correcta :)\n";
                break;
            default:
                cout << "Respuesta erronea.\n";
                break;
        }

        N = aux = ANS = 0;
        U.clear();
        V.clear();
        W.clear();
    }
    return 0;
}
