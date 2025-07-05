#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	ll u, v;
	cin >> u >> v;
	if ( u > v )
	{
		cout << "-1\n";
		return 0;
	}
	ll _sum, _xor, n = 0;
	vi ans ( 70, 0 );
	for ( ll i = 0; i <= 61; i++ )
	{
		_sum = ((v & (1LL << i)) ? 1 : 0);
		_xor = ((u & (1LL << i)) ? 1 : 0);
		
		if ( _sum == 0 && _xor == 1 )
		{
			ll cnt = 0, last = i - 1;
			if ( last < 0 )
			{
				cout << "-1\n";
				return 0;
			}
			for ( ll j = i + 1; j <= 61; j++ )
			{
				if ( v & (1LL << j) )
				{
					v -= (1LL << j);
					cnt = j - 1;
					break;
				}
			}
			
			ans[last] += 2;
			for ( ll j = i; j <= cnt; j++ )
			{
				if ( !(u & (1LL << j)) )
					ans[last] += (1LL << (j - last));
				else
				{
					ans[j]++;
					u -= (1LL << j);
				}
				last = j;
			}
		}
		else if ( _sum == 1 && _xor == 0 )
		{
			if ( i - 1 < 0 )
			{
				cout << "-1\n";
				return 0;
			}
			ans[i - 1] += 2;
		}
		else if ( _sum == 1 && _xor == 1 )
			ans[i]++;
	}
	for ( ll i = 0; i <= 61; i++ )
		n = max ( n, ans[i] );
	
	vector<ll> res ( n );
	for ( ll i = 0; i <= 61; i++ )
		for ( ll j = 0; j < ans[i]; j++ )
			res[j] += (1LL << i);

	cout << n << "\n";
	for ( ll i = 0; i < n; i++ )
		cout << res[i] << " ";
	cout << "\n";
	return 0;
}
