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

const int MAXN = 1005, MAXK = 25;
int N, M, K, specialA, specialB, a[MAXN];
int par[MAXN], cost[MAXN][MAXN], Graph[MAXN][MAXN];
vector<pair<int, pii>> edges;

int look(int node)
{
	if(par[node] == node)
		return node;
	return par[node] = look(par[node]);
}

void join(int nodeA, int nodeB)
{
	par[look(nodeA)] = look(nodeB);
}

void findMST()
{
	for(int i = 1; i <= N; i++)
		par[i] = i;
		
	sort(all(edges));
	for(auto i : edges)
	{
		int c = i.first, u = i.second.first, v = i.second.second;
		if(look(u) != look(v))
		{
			join(u, v);
			Graph[u][v] = 1;
			Graph[v][u] = 1;
			cost[u][v] = c;
			cost[v][u] = c;
		}
	}
}

int vis[MAXN], maxim, cycA, cycB;

int find_cyc(int node, int p = 0)
{
	if(vis[node])
		return node;
	vis[node] = 1;
	
	int ret = -1;
	for(int i = 1; i <= N; i++)
		if(i != p && Graph[node][i])
		{
			int aux = find_cyc(i, node);
			ret = max(ret, aux);
			
			if(aux > -1 && cost[node][i] > maxim)
			{
				maxim = cost[node][i];
				cycA = node;
				cycB = i;
			}
		}
	
	if(ret == node)
		return -1;
	return ret;
}

ll sum[MAXN];

ll dfs(int node, int p = 0)
{
	ll ans = 0;
	sum[node] = a[node];
	for(int i = 1; i <= N; i++)
		if(i != p && Graph[node][i])
		{
			ans += dfs(i, node);
			sum[node] += sum[i];
			if((i == specialA || i == specialB) && (node == specialA || node == specialB))
				ans += (ll)sum[i] * (ll)cost[node][i];
		}
	return ans;
}

int main()
{
	cin >> N >> M >> K;
	if(K > 1 || N > 1000)
	{
		cout << "0\n";
		return 0;
	}
		
	for(int i = 0; i < M; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		edges.pb({c, {u, v}});
	}
	cin >> specialA >> specialB;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	
	findMST();
	
	Graph[specialA][specialB] = 1;
	Graph[specialB][specialA] = 1;
	find_cyc(1);
	
	cost[specialA][specialB] = maxim;
	cost[specialB][specialA] = maxim;
	Graph[cycA][cycB] = 0;
	Graph[cycB][cycA] = 0;
	
	cout << dfs(1) << "\n";
	return 0;
}
