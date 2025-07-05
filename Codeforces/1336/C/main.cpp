#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3005, MOD = 998244353;
ll DP[MAXN][MAXN], DP2[MAXN][MAXN][2];

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string S, T;
    cin >> S >> T;
    int N = S.length(), M = T.length();
    S = " " + S;
    T = " " + T;
    
    for(int i = M + 1; i <= N + 1; i++)
        DP[i][0] = 1;
    for(int i = N; i >= 1; i--)
    {
        for(int b = 0; b <= N; b++)
        {
            //put F
            if(b > M || S[i] == T[b])
                DP[i][b] += DP[i + 1][b - 1];
            DP[i][b] %= MOD;
            //put B
            if(i + b > M || S[i] == T[i + b])
                DP[i][b] += DP[i + 1][b];
            DP[i][b] %= MOD;
        }
    }
    
    ll ans = 0;
    for(int b = 0; b <= N; b++)
    {
        ans += DP[1][b];
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
