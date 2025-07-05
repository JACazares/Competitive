#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 998244353;

ll binexp ( ll b, int e )
{
	if ( e == 0	)	return 1;
	if ( e % 2 == 1 )	return (b * binexp ( b, e - 1 )) % MOD;
	else
	{
		ll aux = binexp ( b, e / 2 );
		return (aux * aux) % MOD;
	}
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	ll N;
	cin >> N;
	for ( ll i = 1; i <= N; i++ )
	{
		ll ans = 0;
		if ( N - i - 2 >= 0 )
		{
			ans += (((N - i - 1) * 810LL) % MOD * binexp ( 10, N - i - 2 )) % MOD;
			ans += (180 * binexp ( 10, N - i - 1 )) % MOD;
		}
		else if ( N - i - 1 >= 0 )
			ans += (180 * binexp ( 10, N - i - 1 )) % MOD;
		else if ( N - i >= 0 )
			ans += 10;
		ans %= MOD;
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}
