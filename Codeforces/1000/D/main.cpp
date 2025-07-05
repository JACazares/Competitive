#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MOD = 998244353, MAXN = 1e3 + 5;
ll binomial[MAXN][MAXN];

ll choose ( int n, int k )
{
	if ( binomial[n][k] )
		return binomial[n][k];
	if ( n == 0 || k == 0 || n == k )
		return 1;
	return binomial[n][k] = (choose ( n - 1, k - 1 ) + choose ( n - 1, k ) ) % MOD;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	vi a(N);
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	vl DP(N+5);
	DP[N] = 1;
	ll ans = 0;
	for ( int i = N - 1; i >= 0; i-- ) 
	{
		if ( a[i] <= 0 )
			continue;
		for ( int j = i + a[i] + 1; j <= N; j++ )
		{
			DP[i] += (choose(j - i - 1, a[i]) * DP[j]) % MOD;
			DP[i] %= MOD;
		}
		ans += DP[i];
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}
