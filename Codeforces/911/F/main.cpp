#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAXN = 200005;

ll N, u, v, node1, node2, vis[MAXN], parent[MAXN], diam, ans, sum, inDiam[MAXN];
vi Graph[MAXN];
vector < pii > result;

pii bfs ( ll node )
{
	/*
	@return
	a pair indicating the vertex furthest away and the distance from node to that vertex
	
	@param
	a node to start the bfs from
	*/
	for ( ll i = 1; i <= N; i++ )
		vis[i] = 0, parent[i] = 0;

	pii aux;
	queue < pii > Q;
	Q.push ( {node, 0} );
	while ( !Q.empty() )
	{
		aux = Q.front();
		Q.pop();
		
		vis[aux.first] = 1;
		parent[aux.first] = aux.second;
		for ( auto i : Graph[aux.first] )
			if ( !vis[i] )
				Q.push ( {i, aux.first} ), vis[i] = 1;
	}
	
	ll diameter = 0;
	for ( ll tmp = aux.first; tmp != node; tmp = parent[tmp] )
		diameter++;
	return {aux.first, diameter};
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	for ( ll i = 0; i < N - 1; i++ )
	{
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}
	
	node1 = bfs ( 1 ).first;
	auto tmp = bfs ( node1 );
	node2 = tmp.first;
	diam = tmp.second;
	
	queue < pair<ll, pii> > Q;
	ll dist = 0;
	for ( ll i = 1; i <= N; i++ )
		vis[i] = 0;
	
	for ( ll node = node2; node != node1; node = parent[node] )
	{
		if ( 2 * dist > diam )
			Q.push ( {node, {dist, node2} } );
		else
			Q.push ( {node, {diam - dist, node1} } );
		dist++;
		inDiam[node] = 1;
		vis[node] = 1;
	}
	inDiam[node1] = 1;
	vis[node1] = 1;
	
	while ( !Q.empty() )
	{
		auto aux = Q.front();
		Q.pop();
		
		if ( !inDiam[aux.first] )
		{
			result.push_back ( {aux.first, aux.second.second} );
			ans += aux.second.first;
		}
		
		vis[aux.first] = 1;
		for ( auto i : Graph[aux.first] )
			if ( !vis[i] )
				Q.push ( {i, {aux.second.first + 1, aux.second.second}} ), vis[i] = 1;
	}
	reverse ( result.begin(), result.end() );
	
	sum = diam * (diam + 1) / 2;
	cout << ans + sum << "\n";
	for ( auto i : result )
		cout << i.first << " " << i.second << " " << i.first << "\n";
	for ( ll node = node2; node != node1; node = parent[node] )
		cout << node1 << " " << node << " " << node << "\n";
	return 0;
}
