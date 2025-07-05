#include <iostream>
#define MAXN 100007
#define MOD 1000000007
using namespace std;
typedef long long int lld;

lld T, K, DP[MAXN], ans, a, b;

lld dp ( int x )
{
	if ( x == 0 )
		return 1;
	
	if ( DP[x] > -1 )
		return DP[x];
	
	if ( x >= K )
		return DP[x] = ( ( dp( x - K ) % MOD ) + ( dp( x - 1 ) % MOD ) ) % MOD;
	else
		return DP[x] = dp( x - 1 ) % MOD;
}

int main ()
{
	cin >> T >> K;
	for ( int i = 1; i <= 100005; i++ )
		DP[i] = -1;
	DP[100005] = dp( 100005 );

	for ( int i = 1; i <= 100005; i++ )
		DP[i] += DP[i - 1];

	for ( int i = 0; i < T; i++ )
	{
		cin >> a >> b;
		if ( DP[a - 1] <= DP[b] )
			ans = ( DP[b] - DP[a - 1] ) % MOD;
		else
			ans = ( ( DP[b] + MOD ) - DP[a - 1] ) % MOD;
		cout << ans << "\n";
	}
	return 0;
}
