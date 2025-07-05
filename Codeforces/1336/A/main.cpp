#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
ll N, K, ans[MAXN], sz[MAXN];
vi Graph[MAXN];

void solve(int node, int p = 0, int d = 0)
{
    ans[node] = d;
    for(auto i : Graph[node])
        if(i != p)
        {
            solve(i, node, d + 1);
            ans[node] -= sz[i];
            sz[node] += sz[i];
        }
    sz[node]++;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    solve(1);
    sort(ans + 1, ans + N + 1, greater<int>());
    
    ll res = 0;
    for(int i = 1; i <= K; i++)
        res += ans[i];
    cout << res << "\n";
    return 0;
}
