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

const int MAXN = (int)1e5 + 5;
const ll MOD = (ll)1e9 + 7;
int N, M, levels;
ll lev[MAXN], sum[2];
vi Graph[MAXN];

void dfs(int node, int p = 0, int d = 0)
{
	levels = max(levels, d);
	lev[d]++;
	for(auto i : Graph[node])
		if(i != p)
			dfs(i, node, d + 1);
}

ll binexp(ll b, ll e)
{
	if(e == 0)
		return 1;
	
	if(e&1)
		return (b*binexp(b, e-1))%MOD;
	else
	{
		ll aux = binexp(b, e/2);
		return (aux*aux)%MOD;
	}
}

void solve()
{
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	
	ll ans = 1;
	// do stuff
	
	if(M == N - 1)
	{
		dfs(1);
		
		for(int i = 1; i <= levels; i++)
		{
			ans *= (binexp(binexp(2, lev[i - 1]) - 1, lev[i]) + MOD)%MOD;
			//cerr << (binexp(binexp(2, lev[i - 1]) - 1, lev[i]) + MOD)%MOD << "\n";
			ans %= MOD;
		}
	}
	
	// stop doing stuff
	cout << ans << "\n";
	
	for(int i = 1; i <= N; i++)
	{
		Graph[i].clear();
		lev[i] = 0;
	}
	for(int i = 0; i <= 1; i++)
		sum[i] = 0;
	levels = 0;
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
