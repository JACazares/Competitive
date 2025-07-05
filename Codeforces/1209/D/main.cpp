#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

int N, K, u, v, ans, p[MAXN];

int look ( int node )
{
	if ( p[node] == node )
		return node;
	return p[node] = look ( p[node] );
}

void join ( int nodeA, int nodeB )
{
	p[look(nodeB)] = look ( p[nodeA] );
}

int main ()
{
	cin >> N >> K;
	for ( int i = 1; i <= N; i++ )
		p[i] = i;
	for ( int i = 0; i < K; i++ )
	{
		cin >> u >> v;
		if ( look(u) != look(v) )
			join ( u, v );
		else
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
