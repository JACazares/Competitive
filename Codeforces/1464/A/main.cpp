#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = 1e5 + 5;
int row[MAXN], col[MAXN], vis[MAXN];

int solve(int r, int c)
{
    //cerr << c << "\n";
    if(c == 0)
        return 0;
    if(vis[c])
        return 1;
    vis[c] = 1;
    int ret = solve(col[row[c]], row[c]) + 1;
    row[r] = 0;
    return ret;
}

void solve()
{
    int N, M;
    cin >> N >> M;
    for(int i = 1;  i <= N; i++)
    {
        row[i] = 0;
        col[i] = 0;
        vis[i] = 0;
    }
    for(int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        if(x == y)
            continue;
        row[x] = y;
        col[y] = x;
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
        if(!col[i] || vis[i])
            continue;
        ans += solve(col[i], i);
    }
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
