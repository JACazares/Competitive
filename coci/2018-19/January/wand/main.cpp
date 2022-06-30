#include <iostream>
#include <vector>
#define MAXN 100005

using namespace std;
typedef long long ll;

ll N, M, u, v, ans, visited[MAXN];
vector < ll > Graph[MAXN];

void dfs ( ll node )
{
	for ( auto i : Graph[node] )
		if ( !visited[i] )
			visited[i] = 1, dfs ( i );
}

int main ()
{
	cin >> N >> M;
	for ( ll i = 0; i < M; i++ )
	{
		cin >> u >> v;
		Graph[v].push_back ( u );
	}

	dfs ( 1 );
	
	if ( Graph[1].size() == 0 )
		visited[1] = 1;

	for ( ll i = 1; i <= N; i++ )
		cout << visited[i];
	cout << "\n";
	return 0;
}
