#include <iostream>
#define MAXN 1000005
#define VARS int mid = (l + r) / 2, lchild = (2 * node) + 1, rchild = (2 * node) + 2

using namespace std;

struct STNode
{
	int len, open, close;
} ST[4 * MAXN];

int N, Q, L, R;
string S;

STNode Node ( int f )
{
	STNode aux;
	aux.len = 0;
	aux.open = (f == 1);
	aux.close = (f == 2);

	return aux;
}

STNode merge ( STNode _a, STNode _b )
{
	STNode aux;
	aux.len = _a.len + _b.len + 2 * min ( _a.open, _b.close );
	aux.open = _b.open + _a.open - min ( _a.open, _b.close );
	aux.close = _a.close + _b.close - min ( _a.open, _b.close );
	
	return aux;
}

void build ( int node = 0, int l = 1, int r = N )
{
	if ( l == r )
	{
		if ( S[l] == '(' )
			ST[node] = Node(1);
		else
			ST[node] = Node(2);
		return;
	}

	VARS;

	build ( lchild, l, mid );
	build ( rchild, mid + 1, r );

	ST[node] = merge ( ST[lchild], ST[rchild] );
}

STNode qry ( int node = 0, int l = 1, int r = N )
{
	if ( L <= l && r <= R )
		return ST[node];
	if ( r < L or R < l )
		return Node(0);
	
	VARS;

	return merge ( qry ( lchild, l, mid ), qry ( rchild, mid + 1, r ) ) ;
}

int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cin >> S;
	S = " " + S;
	
	build ();

	cin >> Q;
	for ( int i = 0; i < Q; i++ )
	{
		cin >> L >> R;
		cout << qry ( ).len << "\n";
	}
	return 0;
}
