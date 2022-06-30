#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define MAXN 100005
#define pnode node*
using namespace std;
typedef long long int lld;

struct orden
{
	lld p, f;
};

struct node
{
	lld val, prioridad, cont;
	pnode l; pnode r;

	node ( lld x )
	{
		l = NULL;
		r = NULL;
		val = x;
		prioridad = rand();
	}
} *root;

lld N, M, leastElem;
orden olimpico[MAXN], joel[MAXN];
lld ans;

bool cmp( orden a, orden b )
{
	return a.f > b.f;
}

void split( pnode tree, lld key, pnode &l, pnode &r)
{
	if ( tree == NULL )
	{
		l = NULL;
		r = NULL;
		return;
	}

	if ( key <= tree -> val ) 
	{
		split( tree -> l, key, l, tree -> l);
		r = tree;
		return;
	}
	else
	{
		split( tree -> r, key, tree -> r, r );
		l = tree;
		return;
	}
}

void merge( pnode &tree, pnode l, pnode r)
{
	if ( l == NULL)
	{
		tree = r;
		return;
	}
	else if ( r == NULL )
	{
		tree = l;
		return;
	}
	else if ( l -> prioridad > r -> prioridad )
	{
		merge(  l -> r, l -> r, r );
		tree = l;
		return;
	}
	else
	{
		merge( r -> l, l, r -> l );
		tree = r;
		return;
	}
}

void del(pnode &tree, lld element )
{
	pnode left;
	pnode right;
	pnode elem;

	split ( tree, element, left, right );
	split ( right, element + 1, elem, right );

	if ( elem -> r == NULL && elem -> l == NULL )
	{
		merge( tree, left, right );
	}
	else
	{
		merge ( elem, elem -> l, elem -> r );
		merge ( right, elem, right );
		merge ( tree, left, right );
	}
}

void insert( pnode &tree, lld element )
{
	pnode l; pnode r;

	pnode newNode = new node ( element );
	split( tree, element, l, r );
	merge( r, newNode, r );
	merge( tree, l, r );
}

lld Left ( pnode tree )
{
	if ( tree -> l == NULL )
		return tree -> val;
	return Left( tree -> l );
}

int main ()
{
	srand( time(NULL) );

	cin >> N >> M;
	for ( lld i = 0; i < N; i++ )
		cin >> olimpico[i].p >> olimpico[i].f;
	for ( lld i = 0; i < M; i++ )
		cin >> joel[i].p >> joel[i].f;

	sort( olimpico, olimpico + N, cmp );
	sort( joel, joel + M, cmp );
	
	lld cnt = 0;
	
	for ( lld i = 0; i < N; i++ )
	{
		for ( ; joel[cnt].f >= olimpico[i].f && cnt < M; cnt++ )
		{
			insert( root, joel[cnt].p );
			//cout << "inserted " << joel[cnt].p << "\n";
		}

		pnode left; pnode right;

		split ( root, olimpico[i].p, left, right );

		if ( right == NULL )
		{
			cout << "-1\n";
			return 0;
		}
		else
		{
			leastElem = Left ( right );
			del ( right, leastElem );
			merge ( root, left, right );
			//cout << "deleted " << leastElem << "\n";
			ans += leastElem;
		}
	}

	cout << ans << "\n";
	
	return 0;
}
