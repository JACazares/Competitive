#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100005
#define mp make_pair

using namespace std;
typedef long long int lld;

int N, M, u, v, parent1[MAXN], parent2[MAXN], parent[MAXN], low[MAXN], disc[MAXN], cnt;
int parent3[MAXN];
bool visited[MAXN];
vector < int > Graph[MAXN];
vector < pair < int, int > > ans;

int find1 ( int _a )
{
	if ( parent1[_a] == _a )
		return _a;
	return parent1[_a] = find1 ( parent1[_a] );
}

int find2 ( int _a )
{
	if ( parent2[_a] == _a )
		return _a;
	return parent2[_a] = find2 ( parent2[_a] );
}

int find3 ( int _a )
{
	if ( parent3[_a] == _a )
		return _a;
	return parent3[_a] = find3 ( parent3[_a] );
}

void union1 ( int _a, int _b )
{
	parent1[find1(_a)] = find1(_b);
}

void union2 ( int _a, int _b )
{
	parent2[find2(_a)] = find2(_b);
}

void union3 ( int _a, int _b )
{
	parent3[find3(_a)] = find3(_b);
}

void dfs ( int node )
{
	visited[node] = 1;
	low[node] = cnt;
	disc[node] = cnt++;

	for ( auto i : Graph[node] )
	{
		if ( !visited[i] )
		{
			parent[i] = node;
			dfs ( i );
			low[node] = min ( low[node], low[i] );
			if ( disc[node] < low[i] )
				ans.push_back ( mp ( min ( node, i ), max ( node, i ) ) );
		}
		else if ( i != parent[node] )
			low[node] = min ( low[node], disc[i] );
	}
}

int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for ( int i = 1; i <= N; i++ )
		parent1[i] = i, parent2[i] = i, parent3[i] = i;

	for ( int i = 0; i < M; i++ )
	{
		cin >> u >> v;
		if ( find1(u) != find1(v) )
		{
			Graph[u].push_back ( v );
			Graph[v].push_back ( u );
			union1 ( u, v );
		}
		else if ( find2(u) != find2(v) )
		{
			Graph[u].push_back ( v );
			Graph[v].push_back ( u );
			union2 ( u, v );
		}
		else if ( find3(u) != find3(v) )
		{
			Graph[u].push_back ( v );
			Graph[v].push_back ( u );
			union3 ( u, v );
		}
	}

	for ( int i = 1; i <= N; i++ )
		if ( !visited[i] )
			dfs ( i );
	
	sort ( ans.begin(), ans.end() );

	for ( auto i : ans )
		cout << i.first << " " << i.second << "\n";

	return 0;
}
