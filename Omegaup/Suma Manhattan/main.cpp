#include <bits/stdc++.h>
using namespace std;

long long int N, X[500010], Y[500010], sX, sY, SumX, SumY, Result;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
        sX+= X[i];
        sY+= Y[i];
    }
    sort(X, X+N);
    sort(Y, Y+N);
    for(int i = 0; i < N-1; i++)
    {
        SumX+= abs(sX-(X[i]*(N-i)))%1000000007;
        sX-= X[i];
        SumY+= abs(sY-(Y[i]*(N-i)))%1000000007;
        sY-= Y[i];
    }
    Result = SumX+SumY;
    cout << Result%1000000007;
    return 0;
}
