#include <iostream>
using namespace std;
int N, M, S;

int main() {
    cin >> N >> M;
    while(N > 0 && M > 0) {
        if(N > M) {
            S += N/M;
            N %= M;
        }
        else {
            S += M/N;
            M %= N;
        }
    }
    cout << S;
    return 0;
}
