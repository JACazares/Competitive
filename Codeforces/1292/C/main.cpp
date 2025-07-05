#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3e3 + 5;
int N, sz[MAXN][MAXN], vis[MAXN][MAXN];
ll DP[MAXN][MAXN];
vi Graph[MAXN];

void pre(int node, int root, int p = 0)
{
    sz[node][root] = 1;
    for(auto i : Graph[node])
        if(i != p)
        {
            pre(i, root, node);
            sz[node][root] += sz[i][root];
        }
}

ll solve(int l, int r, int pl, int pr)
{
    if(vis[l][r])
        return DP[l][r];
    
    ll ans = 0;
    for(auto i : Graph[l])
        if(i != pl)
            ans = max(ans, solve(i, r, l, pr));
    for(auto i : Graph[r])
        if(i != pr)
            ans = max(ans, solve(l, i, pl, r));
    ans += (sz[r][l] * sz[l][r]);
    vis[l][r] = 1;
    return DP[l][r] = ans;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    for(int i = 1; i <= N; i++)
        pre(i, i);
    ll ans = 0;
    for(int i = 1; i <= N; i++)
        for(auto j : Graph[i])
            ans = max(ans, solve(i, j, j, i));
    cout << ans << "\n";
    return 0;
}
