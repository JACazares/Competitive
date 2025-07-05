#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
int N, c[MAXN], par[MAXN], best_d[MAXN], best_u[MAXN], vis[MAXN];
vi Graph[MAXN];

void solve_d ( int node, int p = 0 )
{
	par[node] = p;
	for ( auto i : Graph[node] )
		if ( i != p )
		{
			solve_d ( i, node );
			best_d[node] += max ( best_d[i], 0 );
		}
	best_d[node] -= c[node];
}

int solve_u ( int node )
{
	if ( node == 1 )
		return -c[node];
	if ( vis[node] )
		return best_u[node];

	vis[node] = 1;
	best_u[node] = solve_u(par[node]) + best_d[par[node]] + c[par[node]];
	if ( best_d[node] > 0 )
		best_u[node] -= best_d[node];
	best_u[node] = max ( best_u[node], 0 );
	best_u[node] -= c[node];
	return best_u[node];
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	for ( int i = 1; i <= N; i++ )
	{
		cin >> c[i];
		if ( c[i] == 1 )
			c[i] = -1;
		else
			c[i] = 1;
	}
	
	for ( int i = 0; i < N - 1; i++ )
	{
		int u, v;
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}
	
	solve_d ( 1 );
	for ( int i = 1; i <= N; i++ )
	{
		solve_u ( i );
		cout << best_d[i] + solve_u ( i ) + c[i] << " ";
	}
	cout << "\n";
	return 0;
}
