/*
ID: coa21
PROG: gathering
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 100005
#define VARS int lchild = (2 * node) + 1, rchild = (2 * node) + 2, mid = (l + r) / 2;

#define UPLOAD 1
#if UPLOAD
#define cin ccin
#define cout ccout
#endif

using namespace std;
typedef long long ll;
ifstream ccin("gathering.in");
ofstream ccout("gathering.out");

int N, M, u, v, A, B, K, disc[MAXN], finish[MAXN], t;
int lazy[4 * MAXN];
vector < int > Graph[MAXN], children[MAXN];

//Linearize the tree
void dfs ( int node, int parent )
{
	disc[node] = ++t;

	for ( auto i : Graph[node] )
	{
		if ( i == parent )
			continue;

		dfs ( i, node );
		children[node].push_back ( i );
	}
	
	finish[node] = t;
}

//Update a range of the ST, nodes that CAN'T be the root
void upd ( int L, int R, int node = 0, int l = 1, int r = N )
{
	if ( L <= l && r <= R )
	{
		lazy[node] = 1;
		return;
	}

	if ( r < L or R < l )
		return;
	
	VARS;
	
	upd ( L, R, lchild, l, mid );
	upd ( L, R, rchild, mid + 1, r );
}

//Ask a query for one position of the ST
int qry ( int pos, int node = 0, int l = 1, int r = N, int f = 0 )
{
	f |= lazy[node];

	if ( l == pos && r == pos )
		return (f ? 0 : 1 );
	if ( r < pos or pos < l )
		return 1;
	
	VARS;
	
	return min ( qry ( pos, lchild, l, mid, f ), qry ( pos, rchild, mid + 1, r, f ) );
}

//Find the first vertex in the path from u to v
int findK ( int x, int y )
{
	int s = 0, e = children[x].size() - 1, mid;

	while ( s <= e )
	{
		mid = (s + e) / 2;

		if ( disc[y] < disc[children[x][mid]] )
			e = mid - 1;
		else if ( disc[y] > finish[children[x][mid]] )
			s = mid + 1;
		else
			return children[x][mid];
	}
	return children[x][mid];
}

int main ()
{
	cin >> N >> M;
	for ( int i = 0; i < N - 1; i++ )
	{
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}

	dfs ( 1, 0 );

	for ( int i = 0; i < M; i++ )
	{
		cin >> A >> B;
		
		// is B in the subtree of A?
		if ( disc[A] <= disc[B] && disc[B] <= finish[A] )
		{
			//only the subtree of K can be the root
			//K = first node from a -> b

			K = findK ( A, B );

			upd ( 1, disc[K] - 1 );
			upd ( finish[K] + 1, N );
		}
		else
		{
			//the subtree of A can't be the root
			upd ( disc[A], finish[A] );
		}
	}

	for ( int i = 1; i <= N; i++ )
		cout << qry ( disc[i] ) << "\n";
	return 0;
}
