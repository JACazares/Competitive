#include <iostream>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;
const ll MOD = 998244353;
int N;
ll a[MAXN], DP[MAXN][2];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
        
    DP[N - 1][0] = (a[N - 1])%MOD;
    DP[N - 1][1] = (a[N - 1] - 1)%MOD;
    for(int i = N - 2; i >= 0; i--)
    {
        // 0 -- free
        // 1 -- restricted
        if(a[i] >= a[i + 1])
        {
            DP[i][0] = (a[i+1]*DP[i+1][1]%MOD + (a[i]-a[i+1])*DP[i+1][0]%MOD)%MOD;
            DP[i][1] = ((a[i+1]-1)*DP[i+1][1]%MOD + (a[i]-a[i+1])* DP[i+1][0]%MOD)%MOD;
        }
        else
        {
            DP[i][0] = a[i]*DP[i+1][1]%MOD;
            DP[i][1] = (a[i]-1)*DP[i+1][1]%MOD;
        }
    }
    cout << DP[0][0] << "\n";
    return 0;
}
