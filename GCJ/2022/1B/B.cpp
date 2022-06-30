#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 1005, MAXP = 105;
int N, P;
ll a[MAXN][MAXP], DP[MAXN][MAXP];

void solve()
{
    cin >> N >> P;
    ll ans = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < P; j++)
            cin >> a[i][j];
        sort(a[i], a[i] + P);
        ans += a[i][P - 1] - a[i][0];
    }
    
    DP[N][0] = DP[N][1] = 0;
    for(int i = N - 1; i >= 1; i--)
    {
        DP[i][0] = min(abs(a[i-1][0] - a[i][P-1]) + DP[i+1][0], abs(a[i-1][0] - a[i][0]) + DP[i+1][1]);
        DP[i][1] = min(abs(a[i-1][P-1] - a[i][P-1]) + DP[i+1][0], abs(a[i-1][P-1] - a[i][0]) + DP[i+1][1]);
    }
    cout << ans + a[0][0] + DP[1][1] << "\n";
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
