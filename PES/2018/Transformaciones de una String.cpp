#include <iostream>
#define MAXN 100000
#define CREATE_VARS int mid = (l + r) / 2, lchild = (2 * node) + 1, rchild = (2 * node) + 2

using namespace std;
typedef long long int lld;

struct Node
{
	int let[30];

	Node sum ( Node _a )
	{
		Node ret;
		for ( int i = 0; i < 26; i++ )
			ret.let[i] = let[i] + _a.let[i];	
		return ret;
	}

	void out ()
	{
		for ( int i = 0; i < 26; i++ )
			if ( let[i] )
				cout << (char)(i + 'a');
	}
};

int N, K, tipo, s, e, lazy[4 * MAXN];
string a;
Node Q, ST[4 * MAXN], BLANK;

void propagate ( int node, int l, int r )
{
	if ( lazy[node] != -1 )
	{
		ST[node] = BLANK;
		ST[node].let[lazy[node]] += (r - l + 1); 

		CREATE_VARS;
	
		if ( l != r )
		{
			lazy[lchild] = lazy[node];
			lazy[rchild] = lazy[node];
		}

		lazy[node] = -1;
	}
}

void create ( int node, int l, int r )
{
	if ( l == r )
	{
		ST[node].let[a[l] - 'a']++;
		return;
	}

	CREATE_VARS;

	create ( lchild, l, mid );
	create ( rchild, mid + 1, r );

	ST[node] = ST[lchild].sum ( ST[rchild] );
}

Node query ( int node, int l, int r, int L, int R )
{
	propagate ( node, l, r );

	if ( L <= l && r <= R )
		return ST[node];
	
	if ( r < L || R < l )
		return BLANK;
	
	CREATE_VARS;

	return query ( lchild, l, mid, L, R ).sum ( query ( rchild, mid + 1, r, L, R ) );
}

void update ( int node, int l, int r, int L, int R, int val )
{
	propagate ( node, l, r );

	if ( L <= l && r <= R )
	{
		lazy[node] = val;
		propagate ( node, l, r );
		return;
	}

	if ( r < L || R < l )
		return;
	
	CREATE_VARS;

	update ( lchild, l, mid, L, R, val );
	update ( rchild, mid + 1, r, L, R, val );

	ST[node] = ST[lchild].sum ( ST[rchild] );
}

int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	cin >> a;

	for ( int i = 0; i < 4 * N; i++ )
		lazy[i] = -1;
	
	for ( int i = 0; i < 26; i++ )
		BLANK.let[i] = 0;

	create ( 0, 0, N - 1 );

	for ( int i = 0; i < K; i++ )
	{
		cin >> tipo >> s >> e;
		s--, e--;
		if ( tipo == 1 )
		{
			Q = query ( 0, 0, N - 1, s, e );
			for ( int c = 0; c < 26; c++ )
			{
				if ( Q.let[c] )
				{
					update ( 0, 0, N - 1, s, s + Q.let[c] - 1, c );
					s += Q.let[c];
				}
			}
		}
		else
		{
			Q = query ( 0, 0, N - 1, s, e );
			for ( int c = 25; c >= 0; c-- )
			{
				if ( Q.let[c] )
				{
					update ( 0, 0, N - 1, s, s + Q.let[c] - 1, c );
					s += Q.let[c];
				}
			}
		}
	}

	for ( int i = 0; i < N; i++ )
		query ( 0, 0, N - 1, i, i ).out();
	
	cout << "\n";
	return 0;
}
