#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAXN = 200005;

ll N, M, w[MAXN], total[MAXN], sz[MAXN], component[MAXN], visited[MAXN], cnt, numCC = 1;
ll id[MAXN], low[MAXN] , ans[MAXN], maxSz[MAXN], leafTotal, maxLeaf, totSum[MAXN];
vi Graph[MAXN], Tree[MAXN];
map < pii, ll > bridge;

void dfs ( ll node, ll p = -1 )
{
	id[node] = low[node] = cnt++;
	visited[node] = 1;
	for ( auto i : Graph[node] )
	{
		if ( i == p )
			continue;

		if ( !visited[i] )
		{
			dfs ( i, node );
			low[node] = min ( low[node], low[i] );
			if ( low[i] > id[node] )
				bridge[{i, node}] = 1, bridge[{node, i}] = 1;
		}
		else
			low[node] = min ( low[node], id[i] );
	}
}

void find_bridges()
{
	cnt = 0;
	for ( ll i = 1; i <= N; i++ )
		id[i] = -1, low[i] = -1;
	for ( ll i = 1; i <= N; i++ )
		if ( !visited[i] )
			dfs ( i );
}

void pall ( ll node, ll color )
{
	total[color] += w[node];
	sz[color]++;
	component[node] = color;
	visited[node] = 1;
	for ( auto i : Graph[node] )
	{
		if ( visited[i] )
			continue;

		if ( bridge[{node, i}] == 1 )
		{
			numCC++;
			Tree[color].push_back ( numCC );
			Tree[numCC].push_back ( color );
			pall ( i, numCC );
		}
		else
			pall ( i, color );
	}
}

void SCC()
{
	for ( ll i = 1; i <= N; i++ )
		visited[i] = 0;
	find_bridges();
	for ( ll i = 1; i <= N; i++ )
		visited[i] = 0;
	numCC = 0;
	for ( ll i = 1; i <= N; i++ )
		if ( !visited[i] )
			pall ( i, ++numCC );
}

void solve1 ( ll node, ll p = -1 )
{
	maxSz[node] = sz[node];
	totSum[node] = total[node];
	for ( auto i : Tree[node] )
	{
		if ( i == p )
			continue;
		solve1 ( i, node );
		ans[node] = max ( ans[node], ans[i] );
		maxSz[node] = max ( maxSz[node], maxSz[i] );
		totSum[node] += totSum[i];
	}
	ans[node] += total[node];
}

void solve2 ( ll node, ll p = -1 )
{
	if ( maxSz[node] == 1 )
	{
		leafTotal += totSum[node];
		maxLeaf = max ( maxLeaf, ans[node] );
		return;
	}

	for ( auto i : Tree[node] )
		if ( i != p )
			solve2 ( i, node );
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M;
	ll tot = 0;
	for ( ll i = 1; i <= N; i++ )
		cin >> w[i], tot += w[i];
	
	ll u, v;
	for ( ll i = 0; i < M; i++ )
	{
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}
	
	ll s;
	cin >> s;
	
	SCC();
	solve1 ( component[s] );
	solve2 ( component[s] );
	
	cout << tot - leafTotal + maxLeaf << "\n";
	return 0;
}
