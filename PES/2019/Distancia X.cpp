#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 300005
#define pii pair < int, int >

using namespace std;
typedef long long ll;

struct edge
{
	int u, v, c;

	bool operator < ( const edge _a ) const
	{
		if ( c == _a.c )
		{
			if ( u == _a.u )
				return v < _a.v;
			return u < _a.u;
		}
		return (c < _a.c);
	}
};

int N, M, X, x, y;
pii parent[MAXN];
ll ans;
edge arista[MAXN];

//Union-Find Basic Operations
int look ( int node )
{
	if ( parent[node].first == node )
		return node;

	return parent[node].first = look ( parent[node].first );
}

void join ( int _a, int _b )
{
	parent[look ( _b)].second += parent[look ( _a )].second;
	parent[look ( _a )].first = look ( _b );
}

int main ()
{
	cin >> N >> M >> X;
	for ( int i = 1; i <= N; i++ )
		parent[i] = {i, 1};
	for ( int i = 0; i < M; i++ )
		cin >> arista[i].u >> arista[i].v >> arista[i].c;
	
	sort ( arista, arista + M );

	for ( int i = 0; i < M; i++ )
	{
		if ( arista[i].c > X )
			break;

		x = look ( arista[i].u );
		y = look ( arista[i].v );
		if ( x != y )
		{
			if ( arista[i].c == X )
				ans += parent[x].second * parent[y].second;
			join ( arista[i].u, arista[i].v );
		}
	}

	cout << ans << "\n";
	return 0;
}
