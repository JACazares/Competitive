#include <bits/stdc++.h>
using namespace std;

long double N, V, R, D[2005], Sum, tempTimeMaxVelocity, timeReqMaxVelocity, timeReqMinVelocity, Result;

int main()
{
    cin >> N >> V >> R;
    for(int i = 0; i < N; i++)
    {
        cin >> D[i];
        Sum+= D[i];
    }
    for(int i = 0; i < N; i++)
    {
        tempTimeMaxVelocity = D[i]/V;
        for(int j = 0; j < Sum; j+= R)
        {
            if(tempTimeMaxVelocity <= j)
            {
                timeReqMaxVelocity = j;
                break;
            }
        }
        timeReqMinVelocity = D[i]/timeReqMaxVelocity;
        Result = max(Result, timeReqMinVelocity);
    }
    cout << fixed << setprecision(9) << Result;
    return 0;
}
