#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node
{
	Node *l, *r;
	int val, p, sz, delta, ansLazy, idx;
	
	Node ( int x, int id )
	{
		l = r = nullptr;
		val = x;
		p = rand();
		sz = 1;
		delta = 0;
		ansLazy = 0;
		idx = id;
	}
};

typedef Node* pNode;

struct tshirt
{
	int p, q;
	
	bool operator < ( const tshirt& _x ) const
	{
		if ( q == _x.q )
			return p < _x.p;
		return q > _x.q;
	}
};

const int MAXQ = 200005;
ll ans[MAXQ];

int sz ( pNode node )
{
	if ( !node )
		return 0;
	return node -> sz;
}

void updSz ( pNode node )
{
	if ( !node )
		return;
	node -> sz = sz ( node -> l ) + sz ( node -> r ) + 1;
}

void propagate ( pNode treap )
{
	if ( !treap )
		return;
	if ( treap -> delta )
	{
		treap -> val -= treap -> delta;
		if ( treap -> l )
			treap -> l -> delta += treap -> delta;
		if ( treap -> r )
			treap -> r -> delta += treap -> delta;
		treap -> delta = 0;
	}
	if ( treap -> ansLazy )
	{
		ans[treap -> idx] += treap -> ansLazy;
		if ( treap -> l )
			treap -> l -> ansLazy += treap -> ansLazy;
		if ( treap -> r )
			treap -> r -> ansLazy += treap -> ansLazy;
		treap -> ansLazy = 0;
	}
}

void propagate_all ( pNode treap )
{
	if ( !treap )
		return;
	propagate ( treap );
	propagate_all ( treap -> l );
	propagate_all ( treap -> r );
}

void split ( pNode treap, int x, pNode& l, pNode &r )
{
	if ( !treap )
	{
		l = r = nullptr;
		return;
	}
	
	propagate ( treap );
	if ( treap -> val <= x )
	{
		split ( treap -> r, x, treap -> r, r );
		l = treap;
		updSz ( l );
	}
	else
	{
		split ( treap -> l, x, l, treap -> l );
		r = treap;
		updSz ( r );
	}
}

void merge ( pNode l, pNode r, pNode& treap )
{
	propagate ( l );
	propagate ( r );
	if ( !l || !r )
	{
		treap = (l ? l : r);
		return;
	}
	
	if ( l -> p > r -> p )
	{
		merge ( l -> r, r, l -> r );
		treap = l;
	}
	else
	{
		merge ( l, r -> l, r -> l );
		treap = r;
	}
	updSz ( treap );
}

void ins ( pNode& treap, int x, int id )
{
	Node *l, *r;
	pNode newNode = new Node ( x, id );
	split ( treap, x, l, r );
	merge ( l, newNode, l );
	merge ( l, r, treap );
}

void ins ( pNode& treap, pNode x )
{
	Node *l, *r;
	split ( treap, x -> val, l, r );
	merge ( l, x, l );
	merge ( l, r, treap );
}

int getMax ( pNode treap )
{
	if ( !treap )
		return (1 << 30);
	propagate ( treap );
	if ( treap -> r )
		return getMax ( treap -> r );
	return treap -> val;
}

int getMin ( pNode treap )
{
	if ( !treap )
		return 0;
	propagate ( treap );
	if ( treap -> l )
		return getMin ( treap -> l );
	return treap -> val;
}

void careful_merge ( pNode l, pNode r, pNode& treap )
{
	propagate ( l );
	propagate ( r );
	int maximL = getMax ( l ), minimR = getMin ( r );
	while ( l && r && minimR <= maximL ) 
	{
		pNode aux = nullptr;
		split ( r, minimR, aux, r );
		ins ( l, aux );
		minimR = getMin ( r );
	}
	merge ( l, r, treap );
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	srand ( time ( NULL ) );
	int N, Q;
	Node* treap = nullptr;
	cin >> N;
	tshirt a[N + 5];
	for ( int i = 0; i < N; i++ )
		cin >> a[i].p >> a[i].q;
	sort ( a, a + N );
	cin >> Q;
	for ( int i = 0; i < Q; i++ )
	{
		int x;
		cin >> x;
		ins ( treap, x, i );
	}
	for ( int i = 0; i < N; i++ )
	{
		Node *l = nullptr, *r = nullptr;
		split ( treap, a[i].p - 1, l, r );
		if ( r )
		{
			r -> ansLazy++;
			r -> delta = a[i].p;
			propagate ( r );
		}
		careful_merge ( l, r, treap );
	}
	propagate_all ( treap );
	for ( int i = 0; i < Q; i++ )
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
