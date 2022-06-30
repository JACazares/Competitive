#include <iostream>
#define MAXN 50
using namespace std;
long long int N, K, DP[MAXN+5], A[MAXN+5];

long long int Fib(int a) {
    if(a==0) return 0;
    if(a==1) return 1;
    if(a==2) return 2;
    if(DP[a]) return DP[a];
    return DP[a] = Fib(a-1) + Fib(a-2);
}

void Solve(int l, int i) {
    if(l == 0)
        return;
    if(l == 1) {
        A[i] = 1;
        return;
    }
    if(K<=Fib(l-1)) {
        A[i] = 1;
        Solve(l-1, i+1);
        for(int a=i+1; a<N; a++)
            A[a]++;
    }
    else if(K>Fib(l-1)) {
        A[i] = 2, A[i+1] = 1;
		K-= Fib(l-1);
        Solve(l-2, i+2);
        for(int a=i+2; a<N; a++)
            A[a]+=2;
    }
}

int main() {
    cin >> N >> K;
    Solve(N, 0);
    for(int i=0; i<N-1; i++)
        cout << A[i] << " ";
    cout << A[N-1] << "\n";
    return 0;
}
