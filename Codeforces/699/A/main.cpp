#include <bits/stdc++.h>
using namespace std;

long long N, P[200000], minim;
char S[200000];

int main()
{
    cin >> N;
    for(int i =0; i<N; i++)
        cin >> S[i];
    for(int i =0; i<N; i++)
        cin >> P[i];
    for(int i =1; i<N; i++)
        if(S[i] == 'L' && S[i-1] == 'R')
        {
            if(minim == 0)
                minim = (P[i]-P[i-1])/2;
            minim = min(minim, (P[i]-P[i-1])/2);
        }
    if(minim == 0)
        minim = -1;
    cout << minim;
    return 0;
}
