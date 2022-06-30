/*
ID: coa21
PROG: dining
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define MAXN 50005
#define pii pair < int, int >

#define UPLOAD 1
#if UPLOAD
#define cin ccin
#define cout ccout
#endif

using namespace std;
typedef long long ll;
ifstream ccin("dining.in");
ofstream ccout("dining.out");

int N, M, K, u, v, c, idx, y, x[MAXN];
bool visited[MAXN];
pii aux;
vector < pii > Graph[MAXN];
priority_queue < pii > PQ;

void busqueda ( int node )
{
	PQ.push ( {0, node} );

	while ( !PQ.empty() )
	{
		aux = PQ.top();
		PQ.pop();

		if ( visited[aux.second] )
			continue;

		visited[aux.second] = 1;

		x[aux.second] = -aux.first;

		for ( auto i : Graph[aux.second] )
			if ( !visited[i.second] )
				PQ.push ( {aux.first - i.first, i.second} );
	}
}

int main ()
{
	cin >> N >> M >> K;
	for ( int i = 0; i < M; i++ )
	{
		cin >> u >> v >> c;
		
		Graph[u].push_back ( {c, v} );
		Graph[v].push_back ( {c, u} );
	}

	busqueda ( N );

	for ( int i = 0; i < K; i++ )
	{
		cin >> idx >> y;
		PQ.push ( {y - x[idx], idx} );
	}

	for ( int i = 1; i <= N; i++ )
		visited[i] = 0;

	while ( !PQ.empty() )
	{
		aux = PQ.top();
		PQ.pop();
		
		if ( visited[aux.second] or x[aux.second] < -aux.first )
			continue;
		visited[aux.second] = 1;

		for ( auto i : Graph[aux.second] )
			if ( !visited[i.second] )
				PQ.push ( {aux.first - i.first, i.second} );
	}

	for ( int i = 1; i < N; i++ )
		cout << visited[i] << "\n";
	return 0;
}
