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
	ll T;
	cin >> T;
	while ( T-- )
	{
		ll x, y;
		cin >> x >> y;
		
		if ( x > y )
			swap ( x, y );
		
		ll k = (2*x - y);
		
		if ( k < 0 || k % 3 != 0 )
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
