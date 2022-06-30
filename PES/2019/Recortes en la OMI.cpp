#include <iostream>
#include <vector>
#define MAXN 1000005

using namespace std;
typedef long long ll;

int N, K, u, v, parent[MAXN][20], nodesLeft, newNode, used[MAXN], aux;
vector < int > Graph[MAXN];

void dfs ( int node, int p = 0 )
{
	parent[node][0] = p;
	for ( auto i : Graph[node] )
		if ( i != p )
			dfs ( i, node );
}

int dist ( int node )
{
	int k = 19;
	while ( k >= 0 && used[parent[node][k]] ) k--;

	if ( k < 0 )
		return 1;
	return (1 << k) + dist ( parent[node][k] );
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> K;
	for ( int i = 0; i < N - 1; i++ )
	{
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}

	dfs ( N );

	for ( int k = 1; k < 20; k++ )
		for ( int i = 1; i <= N; i++ )
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
	
	used[0] = 1;
	used[N] = 1;
	nodesLeft = N - K - 1;
	for ( int i = N - 1; i >= 1; i-- )
	{
		if ( used[i] )
			continue;

		if ( dist ( i ) <= nodesLeft )
		{
			newNode = i;
			while ( !used[newNode] )
			{
				used[newNode] = 1;
				nodesLeft--;
				newNode = parent[newNode][0];
			}
		}
	}

	for ( int i = 1; i <= N; i++ )
		if ( !used[i] )
			cout << i << " ";
	cout << "\n";
	return 0;
}
