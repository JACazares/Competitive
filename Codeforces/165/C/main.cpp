#include <iostream>
#define MAXN 1000005
using namespace std;
long long int K, A[MAXN], Res, DS[MAXN], Prefix[MAXN], N;
string S;

int main() {
    cin >> K;
    cin >> S;
    N = S.length();
    for(int i=0; i<=N; i++)
        A[i+1] = S[i]-'0';
    //prefix sum
    Prefix[0] = 0;
    Prefix[1] = A[1];
    for(int i=2; i<=N; i++)
        Prefix[i] = Prefix[i-1]+A[i];
    DS[0] = 1;
    for(int i=1; i<=N; i++) {
        if(Prefix[i]-K >= 0)
            Res+= DS[Prefix[i]-K];
        DS[Prefix[i]]++;
    }
    cout << Res << "\n";
    return 0;
}
