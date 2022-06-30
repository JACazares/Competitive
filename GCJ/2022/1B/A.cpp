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

const int MAXN = (int)1e5 + 5, MAXD = (int)1e6 + 5;
int N, a[MAXN], maxim_left[MAXN], maxim_right[MAXN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> a[i];
    
    maxim_left[0] = 0, maxim_right[N + 1] = 0;
    
    vi left_LIS(N + 2, 0), right_LIS(N + 2, 0);
    for(int i = 1; i <= N; i++)
    {
        left_LIS[i] = left_LIS[i - 1];
        maxim_left[i] = max(maxim_left[i - 1], a[i]);
        if(a[i] >= maxim_left[i - 1])
            left_LIS[i]++;
    }

    for(int i = N; i >= 1; i--)
    {
        right_LIS[i] = right_LIS[i + 1];
        maxim_right[i] = max(maxim_right[i + 1], a[i]);
        if(a[i] >= maxim_right[i + 1])
            right_LIS[i]++;
    }

    int ans = 0;
    for(int i = 0; i <= N; i++)
        ans = max(ans, left_LIS[i] + right_LIS[i + 1]);
    cout << ans << "\n";
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
