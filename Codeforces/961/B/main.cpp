#include <iostream>
#define MAXN 100005

using namespace std;
typedef long long int lld;

lld N, K, a[MAXN], t[MAXN], b[MAXN], ans, segTree[4 * MAXN], finalAns;

void create ( int node, int l, int r )
{
	if ( l == r )
	{
		segTree[node] = b[l];
		return;
	}

	int lchild = ( 2 * node ) + 1;
	int rchild = ( 2 * node ) + 2;
	int mid = ( l + r ) / 2;

	create ( lchild, l, mid );
	create ( rchild, mid + 1, r );
	segTree[node] = segTree[lchild] + segTree[rchild];
}

int query ( int node, int l, int r, int L, int R )
{
	if ( L <= l && r <= R )
		return segTree[node];
	if ( r < L or R < l )
		return 0;

	int lchild = ( 2 * node ) + 1;
	int rchild = ( 2 * node ) + 2;
	int mid = ( l + r ) / 2;

	return query ( lchild, l, mid, L, R ) + query ( rchild, mid + 1, r, L, R );
	
}

int main ()
{
	cin >> N >> K;
	for ( lld i = 0; i < N; i++ )
		cin >> a[i];
	for ( lld i = 0; i < N; i++ )
		cin >> t[i], b[i] = ( t[i] ? 0 : a[i] );
	
	for ( lld i = 0; i < N; i++ )
		if ( t[i] )
			ans += a[i];
	
	create ( 0, 0, N - 1 );
	
	for ( lld i = 0; i <= N - K; i++ )
		finalAns = max ( finalAns, ans + query ( 0, 0, N - 1, i, i + K - 1 ) );
	
	cout << finalAns << "\n";
	return 0;
}
