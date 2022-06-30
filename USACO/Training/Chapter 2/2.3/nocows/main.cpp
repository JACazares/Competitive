/*
ID: josecaz1
PROG: nocows
LANG: C++11
*/
#include <iostream>
#include <fstream>
#define MOD 9901

#define UPLOAD 0

#if UPLOAD
#define cin fin
#define cout fout
#endif

using namespace std;
typedef long long int lld;
ifstream fin("nocows.in");
ofstream fout("nocows.out");

lld N, K, dp[205][105];

lld numWays ( lld nodes, lld height )
{
	if ( nodes == 1 && height == 1 )
		return 1;
	if ( nodes % 2 == 0 || height == 0)
		return 0;

	if ( dp[nodes][height] > -1 )
		return dp[nodes][height];
	
	lld left, right, ans = 0;
	nodes--;
	for ( int i = 1; i <= nodes; i += 2 )
	{
		left = 0, right = 0;
		left = numWays ( i, height - 1 );
		right = numWays ( nodes - i, height - 1 );

		ans += ( ( left % MOD ) * ( right % MOD ) ) % MOD;
		ans %= MOD;

		left = 0, right = 0;
		left = numWays ( i, height - 1 );
		for ( int h = 2; h < height; h++ )
			right += numWays ( nodes - i, height - h );

		ans += ( ( left % MOD ) * ( right % MOD ) ) % MOD;
		ans %= MOD;

		//if ( i != nodes - i )
		//{
			left = 0, right = 0;
			for ( int h = 2; h < height; h++ )
				left += numWays ( i, height - h );
			right = numWays ( nodes - i, height - 1 );

			ans += ( ( left % MOD ) * ( right % MOD ) ) % MOD;
			ans %= MOD;
		//}
	}

	return dp[nodes + 1][height] = ans;
}

int main ()
{
	cin >> N >> K;

	for ( lld i = 0; i <= N; i++ )
		for ( lld j = 0; j <= K; j++ )
			dp[i][j] = -1;

	cout << numWays ( N, K ) << "\n";
	return 0;
}
