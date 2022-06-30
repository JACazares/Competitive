#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

const int MAXN = (int)1e5 + 2, MAXV = 102;
int N, V;
ll p[MAXN];
vi Graph[MAXN];

int par[MAXN];
//what is the sum of all of my children's p_i's
ll sum[MAXN];

void pre(int node, int _p = 0)
{
	par[node] = _p;
	for(auto i : Graph[node])
		if(i != _p)
		{
			pre(i, node);
			sum[node] += p[i];
		}
}

pli DP_down[MAXN][MAXV][2];

ll down(int node, int v, bool f)
{
	if(DP_down[node][v][f].second)
		return DP_down[node][v][f].first;
	if(v == 0)
		return 0;
	
	for(auto i : Graph[node])
		if(i != par[node])
		{
			if(f == 0)
			{
				ll aux = max(down(i, v, 0), down(i, v, 1));
				if(aux > DP_down[node][v][f].first)
					DP_down[node][v][f] = {aux, i};
			}
			else if(f == 1)
			{
				ll aux = max(down(i, v-1, 0), down(i, v-1, 1)) + sum[node];
				if(aux > DP_down[node][v][f].first)
					DP_down[node][v][f] = {aux, i};
			}
		}
	
	return DP_down[node][v][f].first;
}

ll DP_up[MAXN][MAXV][2];

ll up(int node, int v, int f)
{
	if(DP_up[node][v][f])
		return DP_up[node][v][f];
	if(v == 0)
		return 0;
	if(node == 1)
	{
		if(f == 1)
			return sum[node];
		return 0;
	}
	
	ll ans = 0;
	if(f == 0)
	{
		ans = max(ans, up(par[node], v, 0));
		
		ans = max(ans, up(par[node], v, 1) - p[node]);
		
		if(DP_down[par[node]][v][0].second == node)
		{
			for(auto i : Graph[par[node]])
				if(i != par[par[node]] && i != node)
					ans = max(ans, max(DP_down[i][v][0].first, DP_down[i][v][1].first));
		}
		else
			ans = max(ans, DP_down[par[node]][v][0].first);
			
		if(DP_down[par[node]][v][1].second == node)
		{
			for(auto i : Graph[par[node]])
				if(i != par[par[node]] && i != node)
				{
					ans = max(ans, max(DP_down[i][v-1][0].first, DP_down[i][v-1][1].first)
									+ sum[par[node]] - p[node] + p[par[par[node]]]);
				}
		}
		else
			ans = max(ans, DP_down[par[node]][v][1].first - p[node] + p[par[par[node]]]);
	}
	else if(f == 1)
	{
		ll use = sum[node] + p[par[node]];
		ans = max(ans, up(par[node], v-1, 0) + use);
		
		ans = max(ans, up(par[node], v-1, 1) + use - p[node]);
		
		if(DP_down[par[node]][v-1][0].second == node)
		{
			for(auto i : Graph[par[node]])
				if(i != par[par[node]] && i != node)
					ans = max(ans, max(DP_down[i][v-1][0].first, DP_down[i][v-1][1].first) + use);
		}
		else
			ans = max(ans, DP_down[par[node]][v-1][0].first + use);
			
		if(v-1 > 0)
		{
			if(DP_down[par[node]][v-1][1].second == node)
			{
				for(auto i : Graph[par[node]])
					if(i != par[par[node]] && i != node)
					{
						ans = max(ans, max(DP_down[i][v-2][0].first, DP_down[i][v-2][1].first)
										+ sum[par[node]] - p[node] + use + p[par[par[node]]]);
					}
			}
			else
				ans = max(ans, DP_down[par[node]][v-1][1].first - p[node] + use + p[par[par[node]]]);
		}
	}
	
	DP_up[node][v][f] = ans;
	return DP_up[node][v][f];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> V;
	for(int i = 1; i <= N; i++)
		cin >> p[i];
	for(int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	
	pre(1);
	
	for(int i = 1; i <= N; i++)
		for(int v = 1; v <= V; v++)
		{
			down(i, v, 0);
			down(i, v, 1);
		}
	
	ll ans = 0;
	for(int i = 1; i <= N; i++)
	{
		ans = max(ans, max(DP_down[i][V][0].first, DP_down[i][V][1].first
													+ (V > 0 ? p[par[i]] : 0)));
	}
	for(int i = 2; i <= N; i++)
		ans = max(ans, max(up(i, V, 0), up(i, V, 1)));
	cout << ans << "\n";
	return 0;
}
