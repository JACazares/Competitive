#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7, MAXN = 1005;
ll fact[MAXN + 10], inv[MAXN + 10];

ll binexp ( ll b, int e )
{
	if ( e == 0 )
		return 1;
	if ( e % 2 == 0 )
	{
		ll aux = binexp ( b, e / 2 );
		return (aux * aux) % MOD;
	}
	else
		return (b * binexp ( b, e - 1 )) % MOD;
}

ll choose ( int n, int k )
{
	return ((fact[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N, M;
	cin >> N >> M;
	fact[0] = 1;
	inv[0] = 1;
	for ( int i = 1; i <= N + M; i++ )
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = binexp ( fact[i], MOD - 2 );
	}
	ll ans = 0;
	for ( int a = 1; a <= N; a++ )
		for ( int b = a; b <= N; b++ )
		{
			ans += (choose ( a - 1 + M - 1, a - 1 ) * choose ( N - b + M - 1, N - b )) % MOD;
			ans %= MOD;
		}
	cout << ans << "\n";
	return 0;
}
