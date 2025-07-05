#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vp;

const ll MAXN = 500005;

ll N, K, brother[MAXN], val[MAXN];
vp Graph[MAXN];

void pre ( ll node, ll p, ll x )
{
	ll u = 0;
	val[node] = x;
	for ( auto i : Graph[node] )
	{
		if ( i.first != p )
		{
			pre ( i.first, node, i.second );
			if ( u )
				brother[u] = i.first;
			u = i.first;
		}
	}
}

ll dp ( ll node, ll k, ll f, ll p )
{
	ll ans = 0;
	for ( auto i : Graph[node] )
	{
		if ( i.first != p )
		{
			if ( K - f - 1 >= 0 )
				ans = max ( dp ( i.first, K - f - 1, 1, node ) + val[i.first], dp ( i.first, K - f, 0, node ) );
			else
				ans = dp ( i.first, K - f, 0, node );

			break;
		}
	}
	
	if ( brother[node] && k > 0 )
		ans += max ( dp ( brother[node], k - 1, 1, p ) + val[brother[node]], dp ( brother[node], k, 0, p ) );
	else if ( brother[node] )
		ans += dp ( brother[node], k, 0, p );
	
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	ll Q;
	cin >> Q;
	while ( Q-- )
	{
		cin >> N >> K;
		
		ll u, v, c;
		for ( ll i = 0; i < N - 1; i++ )
		{
			cin >> u >> v >> c;
			Graph[u].push_back ( {v, c} );
			Graph[v].push_back ( {u, c} );
		}
		
		pre ( 1, 0, 0 );
		cout << dp ( 1, K, 0, 0 ) << "\n";

		for ( ll i = 1; i <= N; i++ )
			Graph[i].clear(), brother[i] = 0, val[i] = 0;
	}
	return 0;
}
