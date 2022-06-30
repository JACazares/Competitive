#include <iostream>
#define VARS ll lchild = (2 * node) + 1, rchild = (2 * node) + 2, mid = (l + r) / 2
#define MAXN 100005
#define MOD 1000000007

using namespace std;
typedef long long ll;

struct Alphabet
{
	ll A[26];

	Alphabet operator + ( const Alphabet _a ) const
	{
		Alphabet aux;
		for ( ll i = 0; i < 26; i++ )
			aux.A[i] = A[i] + _a.A[i];

		return aux;
	}

	void shift ( ll _x )
	{
		Alphabet aux;
		for ( ll i = 0; i < 26; i++ )
			aux.A[(i + _x) % 26] = A[i];
		for ( ll i = 0; i < 26; i++ )
			A[i] = aux.A[i];
	}

	ll ask ( )
	{
		ll aux = 0;
		for ( ll i = 0; i < 26; i++ )
			if ( A[i] )
				aux++;
		return aux;
	}
};


ll N, Q, type, x, lazy[4 * MAXN];
ll L, R, p2[MAXN], ans, C;
string S;
Alphabet ST[4 * MAXN];

Alphabet create(char _a)
{
	Alphabet aux;
	for ( ll i = 0; i < 26; i++ )
		aux.A[i] = 0;
	if ( _a != '-' )
		aux.A[_a - 'a']++;
	return aux;
}

void build ( ll node, ll l, ll r )
{
	if ( l == r )
	{
		ST[node] = create ( S[l] );
		return;
	}
	
	VARS;

	build ( lchild, l, mid );
	build ( rchild, mid + 1, r );

	ST[node] = ST[lchild] + ST[rchild];
}

void propagate ( ll node, ll l, ll r )
{
	lazy[node] %= 26;
	if ( lazy[node] )
	{
		ST[node].shift ( lazy[node] );

		if ( l < r )
		{
			VARS;
			lazy[lchild] += lazy[node];
			lazy[rchild] += lazy[node];
			lazy[lchild] %= 26;
			lazy[rchild] %= 26;
		}

		lazy[node] = 0;
	}
}

void update ( ll node, ll l, ll r )
{
	propagate ( node, l, r );

	if ( r < L || R < l )
		return;
	
	VARS;
	if ( L <= l && r <= R )
	{
		lazy[node] += x;
    	lazy[node] %= 26;
		propagate ( node, l, r );
		return;
	}

	update ( lchild, l, mid );
	update ( rchild, mid + 1, r );

	ST[node] = ST[lchild] + ST[rchild];
}

Alphabet query ( ll node, ll l, ll r )
{
	propagate ( node, l, r );

	if ( r < L || R < l )
		return create ( '-' );
	
	if ( L <= l && r <= R )
		return ST[node];
	
	VARS;
	
	return query ( lchild, l, mid ) + query ( rchild, mid + 1, r );
}

int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	cin >> S;

	p2[0] = 1;
	for ( ll i = 1; i <= N; i++ )
		p2[i] = (p2[i - 1] * 2LL) % MOD;

	build ( 0, 0, N - 1 );
	
	for ( ll i = 0; i < Q; i++ )
	{
		cin >> type >> L >> R;
		if ( type == 1 )
		{
			cin >> x;
			x %= 26;
			update ( 0, 0, N - 1 );
		}
		else if ( type == 2 )
		{
			C = query ( 0, 0, N - 1 ).ask();
			ans = ( (C + 1) * (p2[(R - L + 1) - C]) ) % MOD;
			ans = (ans - 1 + MOD) % MOD;

			cout << ans << "\n";
		}
	}
	return 0;
}
