#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 200005, MOD = 998244353;

int N, M;
ll fact[MAXN], inv[MAXN];

ll binexp ( ll n, int b )
{
	if ( b == 0 )
		return 1;
	if ( b % 2 == 0 )
	{
		ll aux = binexp ( n, b / 2 );
		return (aux * aux) % MOD;
	}
	else
		return (binexp(n, b - 1) * n) % MOD;
}

ll choose ( ll n, ll k )
{
	return ((fact[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M;
	fact[0] = 1;
	for ( ll i = 1; i <= M; i++ )
		fact[i] = (fact[i - 1] * i) % MOD;
	for ( int i = 0; i <= M; i++ )
		inv[i] = binexp ( fact[i], MOD - 2 );
	if ( N == 2 )
		cout << "0\n";
	else
	{
		ll ans = ((choose ( M, N - 1 ) * (N - 2)) % MOD * (binexp ( 2, N - 3 ))) % MOD;
		cout << ans << "\n";
	}
	return 0;
}
