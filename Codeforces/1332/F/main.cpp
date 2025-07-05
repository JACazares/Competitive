#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAXN = 3e5 + 5, MOD = 998244353;
ll N, DP[MAXN][2][2];
vector<vi> Graph;

ll dp(ll node, ll ind, ll sub, ll p)
{
    if(DP[node][ind][sub])
        return DP[node][ind][sub];

    ll add = 1, sum = 1, stay = 1;
    if(ind)
        add = 0;
    for(auto i : Graph[node])
    {
        if(i == p)
            continue;

        add *= (dp(i, 1, 1, node) + dp(i, 0, 0, node));
        add %= MOD;
        stay *= (dp(i, 0, 1, node) + dp(i, 0, 0, node));
        stay %= MOD;

        sum *= dp(i, 0, 0, node);
        sum %= MOD;
    }
    if(!sub)
        add -= sum;
    DP[node][ind][sub] = add + stay;
    DP[node][ind][sub] %= MOD;
    return DP[node][ind][sub];
}

int main ()
{
    ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
    cin >> N;
    Graph.resize(N+1);
    for(ll i = 0; i < N - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    
    cout << ((dp(1, 0, 0, 0) - 1) + MOD) % MOD << "\n";
    return 0;
}
