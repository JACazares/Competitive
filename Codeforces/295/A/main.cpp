#include <iostream>
#define MAXN 100005
using namespace std;
typedef long long int lld;

lld N, M, K, Left, Right;
lld L, R, Upd;
lld from[MAXN], to[MAXN], change[MAXN];
lld a[MAXN], b[MAXN], numbers[MAXN];
lld lazy[4 * MAXN];

void update( lld node, lld Start, lld End )
{
	if ( Start >= L && End <= R )
	{
		lazy[node]+= Upd;
		return;
	}

	if ( Start > R || End < L )
		return;

	lld mid = ( Start + End ) / 2;
	lld lchild = ( 2 * node ) + 1;
	lld rchild = ( 2 * node ) + 2;
	update( lchild, Start, mid );
	update( rchild, mid + 1, End );
}

lld query( lld node, lld Start, lld End, lld lookingFor ) {
	if ( Start == End )
		return lazy[node];

	lld mid = ( Start + End ) / 2;
	lld lchild = ( 2 * node ) + 1;
	lld rchild = ( 2 * node ) + 2;

	if ( lookingFor <= mid )
	{
		return query( lchild, Start, mid, lookingFor ) + lazy[node];
	}
	else
	{
		return query( rchild, mid + 1, End, lookingFor ) + lazy[node];
	}
}

int main () {
	cin >> N >> M >> K;
	for ( lld i = 1; i <= N; i++ )
	{
		cin >> numbers[i];
	}
	for ( lld i = 1; i <= M; i++ )
	{
		cin >> from[i] >> to[i] >> change[i];
	}
	for ( lld i = 0; i < K; i++ )
	{
		cin >> Left >> Right;
		a[Left]++;
		a[Right + 1]--;
	}
	for ( lld i = 1; i <= M; i++ )
	{
		b[i] = b[i - 1];
		b[i] += a[i];
	}

	for ( lld i = 1; i <= M; i++ )
	{
		L = from[i];
		R = to[i];
		Upd = change[i] * b[i];
		update( 0, 1, N );
	}

	for ( lld i = 1; i <= N; i++ )
	{
		cout << numbers[i] + query( 0, 1, N, i) << " ";
	}
	cout << "\n";
	return 0;
}
