#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	const int INF = (1 << 30);
	int N, M;
	cin >> N >> M;
	vector<vi> Graph(N + 5), invGraph(N + 5);
	for ( int i = 0; i < M; i++ )
	{
		int u, v;
		cin >> u >> v;
		Graph[u].push_back ( v );
		invGraph[v].push_back ( u );
	}
	int K;
	cin >> K;
	vi p(K);
	for ( int i = 0; i < K; i++ )
		cin >> p[i];
	
	vi Q, dist(N + 5);
	Q.push_back ( p[K - 1] );
	for ( int i = 1; i <= N; i++ )
		dist[i] = INF;
	dist[p[K - 1]] = 0;
	for ( int i = 0; i < Q.size(); i++ )
	{
		int aux = Q[i];
		for ( auto j : invGraph[aux] )
			if ( dist[j] == INF )
			{
				dist[j] = dist[aux] + 1;
				Q.push_back ( j );
			}
	}
	
	int minim = 0, maxim = 0;
	for ( int i = 0; i < K - 1; i++ )
	{
		if ( dist[p[i + 1]] == dist[p[i]] - 1 )
		{
			int shortestPaths = 0;
			for ( auto j : Graph[p[i]] )
				if ( dist[j] == dist[p[i]] - 1 )
					shortestPaths++;
			if ( shortestPaths > 1 )
				maxim++;
		}
		else
		{
			minim++;
			maxim++;
		}
	}
	cout << minim << " " << maxim << "\n";
	return 0;
}
