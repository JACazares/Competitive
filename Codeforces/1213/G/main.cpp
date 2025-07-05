#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 200005;

int N, M, u, v, c, q, p[MAXN], n1, n2;
ll ans, sz[MAXN], a[MAXN], res[MAXN];
vi qry[MAXN];
vector < pair<int, pii> > Edge;

int look ( int node )
{
	if ( p[node] == node )
		return node;
	return p[node] = look ( p[node] );
}

void join ( int _1, int _2 )
{
	sz[look(_1)] += sz[look(_2)];
	p[look(_2)] = look(_1);
}

int main ()
{
	cin >> N >> M;
	for ( int i = 0; i < N - 1; i++ )
	{
		cin >> u >> v >> c;
		Edge.push_back ( {c, {u, v}} );
	}
	for ( int i = 0; i < M; i++ )
		cin >> q, qry[q].push_back ( i );

	for ( int i = 1; i <= N; i++ )
		p[i] = i, sz[i] = 1;
	sort ( Edge.begin(), Edge.end() );
	for ( auto i : Edge )
	{
		u = i.second.first, v = i.second.second, c = i.first;
		
		n1 = look(u), n2 = look(v);
		ans += sz[n1] * sz[n2];
		a[c] = ans;
		
		join ( u, v );
	}
	
	for ( int i = 1; i < MAXN; i++ )
	{
		a[i] = max ( a[i], a[i - 1] );
		for ( auto j : qry[i] )
			res[j] = a[i];
	}
	
	for ( int i = 0; i < M; i++ )
		cout << res[i] << " ";
	cout << "\n";
	return 0;
}
