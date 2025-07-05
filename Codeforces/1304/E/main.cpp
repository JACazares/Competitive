#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 100005, LOG = 22;

int N, p[MAXN][LOG], depth[MAXN];
vi Graph[MAXN];

void pre ( int node, int _p = 0 )
{
	p[node][0] = _p;
	depth[node] = depth[_p] + 1;
	for ( auto i : Graph[node] )
		if ( i != _p )
			pre ( i, node );
}

int lca ( int a, int b )
{
	if ( depth[a] > depth[b] )
		swap ( a, b );
	for ( int i = LOG - 1; i >= 0; i-- )
		if ( depth[p[b][i]] >= depth[a] )
			b = p[b][i];
	
	if ( a == b )
		return a;
	
	for ( int i = LOG - 1; i >= 0; i-- )
		if ( p[a][i] != p[b][i] )
			a = p[a][i], b = p[b][i];
	return p[a][0];
}

int dist ( int a, int b )
{
	return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

int len ( int x, int y )
{
	return dist ( x, y ) + 1;
}

int find_cycle ( int x, int y, int a )
{
	int l = lca ( x, y );
	
	if ( lca ( a, l ) == l )
	{
		int t1 = lca ( a, x ), t2 = lca ( a, y );
		return (depth[t1] > depth[t2] ? t1 : t2);
	}
	else
		return l;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	for ( int i = 0; i < N - 1; i++ )
	{
		int u, v;
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}
	pre ( 1 );
	for ( int k = 1; k < LOG; k++ )
		for ( int i = 1; i <= N; i++ )
			p[i][k] = p[p[i][k - 1]][k - 1];
	int Q;
	cin >> Q;
	int x, y, a, b, k;
	int d, c1, c2;
	for ( int q = 0; q < Q; q++ )
	{
		cin >> x >> y >> a >> b >> k;
		
		d = dist ( a, b );
		if ( k >= d && d % 2 == k % 2 )
			cout << "YES\n";
		else
		{
			c1 = find_cycle ( x, y, a );
			c2 = find_cycle ( x, y, b );
			d = dist ( a, c1 ) + dist ( c2, b ) + dist ( c1, c2 );
			if ( k >= d && d % 2 == k % 2 )
				cout << "YES\n";
			else
			{
				d = dist ( a, c1 ) + dist ( c2, b ) + (len ( x, y ) - dist ( c1, c2 ));
				if ( k >= d && d % 2 == k % 2 )
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
	return 0;
}
