#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
ll ans;
vi depth, sz;
vector<vi> Graph;

void pre ( int node, int p = 0 )
{
	depth[node] = depth[p] + 1;
	ans += depth[node] - 1;
	sz[node] = 1;
	for ( auto i : Graph[node] )
		if ( i != p )
		{
			pre ( i, node );
			sz[node] += sz[i];
		}
}

ll solve ( int node, ll k, int p = 0 )
{
	ll res = k;
	for ( auto i : Graph[node] )
	{
		if ( i == p )
			continue;
		ll aux = k - sz[i] + (N - sz[i]);
		res = max ( res, solve ( i, aux, node ) );
	}
	return res;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	Graph.resize ( N + 5 );
	for ( int i = 0; i < N - 1; i++ )
	{
		int u, v;
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}
	
	depth.resize ( N + 5 );
	sz.resize ( N + 5 );
	pre ( 1 );
	
	cout << solve ( 1, ans ) + N << "\n";
	return 0;
}
