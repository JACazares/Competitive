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
int N, M, cyc;
bool vis[MAXN];
vi Graph[MAXN];

int find_cycle(int node, int p = 0)
{
	if(vis[node])
		return node;
	vis[node] = 1;
	
	int ret = -1;
	for(auto i : Graph[node])
		if(i != p)
			ret = max(ret, find_cycle(i, node));
	
	if(ret > -1)
		cyc++;
	if(ret == node)
		ret = -1;
	return ret;
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
	
	int ans = M;
	// do stuff
	
	if(N == M)
	{
		cyc = 0;
		find_cycle(1);

		if(cyc % 2 == 0)
			ans = M - 1;
	}
	
	// stop doing stuff
	cout << ans << "\n";
	
	for(int i = 1; i <= N; i++)
	{
		Graph[i].clear();
		vis[i] = 0;
	}
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
