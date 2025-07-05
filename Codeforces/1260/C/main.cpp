#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll gcd ( ll a, ll b )
{
	if ( b == 0 )
		return a;
	return gcd ( b, a % b );
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	ll T;
	cin >> T;
	while ( T-- )
	{
		ll r, b, k;
		cin >> r >> b >> k;
		
		if ( r > b )
			swap ( r, b );
		
		bool ans = 0;
		for ( ll i = 1; i <= min ( 1000LL, r / gcd ( r, b ) ); i++ )
			if ( (b*i - 1)/r - (b*(i - 1))/r >= k )
			{
				ans = 1;
				break;
			}
		
		cout << (ans ? "REBEL" : "OBEY") << "\n";
	}
	return 0;
}
