#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    if(N == K)
        cout << "-1";
    else if(N == K+1)
        for(int i =0; i<N; i++)
            cout << i << " ";
    else
    {
        cout << N << " ";
        for(int i =2; i<=K+1; i++)
            cout << i << " ";
        cout << "1 ";
        for(int i =K+2; i<N; i++)
            cout << i << " ";
    }
    return 0;
}
