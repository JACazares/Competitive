#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXN = 200005;

ll N, a[MAXN], arr[MAXN], b[MAXN], BIT[MAXN];

ll qry ( ll pos )
{
	ll res = 0;
	for ( ; pos; pos -= (pos & -pos) )
		res += BIT[pos];
	return res;
}

void upd ( ll pos, ll x )
{
	for ( ; pos <= N; pos += (pos & -pos) )
		BIT[pos] += x;
}

bool ask ( ll pos, ll x )
{
	if ( arr[pos] + qry ( pos ) > x )
		return 1;
	return 0;
}

ll solve ( ll x )
{
	ll s = 1, e = N, mid, val, ans;
	while ( s <= e )
	{
		mid = (s + e) / 2;
		val = ask ( mid, x );
	
		if ( val )
			e = mid - 1;
		else
			ans = mid, s = mid + 1;
	}
	
	upd ( ans + 1, -ans );
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	for ( ll i = 0; i < N; i++ )
		cin >> a[i];
	
	for ( ll i = 2; i <= N; i++ )
		arr[i] = arr[i - 1] + i - 1;

	for ( ll i = N - 1; i >= 0; i-- )
		b[i] = solve ( a[i] );
		
	for ( ll i = 0; i < N; i++ )
		cout << b[i] << " ";
	cout << "\n";
	return 0;
}
