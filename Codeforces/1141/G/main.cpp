#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

const int MAXN = 200005;

int N, K, u, v, deg[MAXN], color[MAXN], bad[MAXN];
vp Graph[MAXN], degree;

void dfs ( int node, int lastColor, int p = 0 )
{
	if ( bad[node] )
	{
		for ( auto i : Graph[node] )
			if ( i.first != p )
				dfs ( i.first, lastColor, node ), color[i.second] = lastColor;
	}
	else
	{
		int col = 1;
		for ( auto i : Graph[node] )
			if ( i.first != p )
			{
				if ( col == lastColor )
					col++;
				dfs ( i.first, col, node );
				color[i.second] = col;
				col++;
			}
	}
}

int main ()
{
    ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> K;
	for ( int i = 0; i < N - 1; i++ )
	{
		cin >> u >> v;
		Graph[u].push_back ( {v, i} );
		Graph[v].push_back ( {u, i} );
		deg[u]++, deg[v]++;
	}
	
	for ( int i = 1; i <= N; i++ )
		degree.push_back ( {deg[i], i} );
	sort ( degree.begin(), degree.end(), greater < pii > () );
	
	for ( int i = 0; i < K; i++ )
		bad[degree[i].second] = 1;

	if ( bad[1] )
		dfs ( 1, 1 );
	else
		dfs ( 1, 0 );
		
	cout << degree[K].first << "\n";
	for ( int i = 0; i < N - 1; i++ )
		cout << color[i] << " ";
	cout << "\n";
	return 0;
}
