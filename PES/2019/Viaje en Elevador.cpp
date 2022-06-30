#include <iostream>
#define MAXN 5005
#define MAXK 5005
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

int N, a, b, K, pref[MAXN][2], DP[MAXN][2], l, r;

int main ()
{
	cin >> N >> a >> b >> K;

	for ( int k = 0; k <= K; k++ )
	{
		pref[0][k%2] = 0;
		for ( int i = 1; i <= N; i++ )
		{
			pref[i][k%2] = pref[i - 1][k%2];
			if ( k == 0 )
			{
				if ( i != b )
				{
					DP[i][k%2] = 1;
					pref[i][k%2] += 1;
				}
			}
			else
			{
				if ( i < b )
				{
					r = b - 1;
					l = max ( (2 * i) - b, 0 );
				}
				else if ( i > b )
				{
					r = min ( (2 * i) - b - 1, N );
					l = b;
				}
				
				DP[i][k%2] = (((pref[r][(k - 1)%2] - pref[l][(k - 1)%2] + MOD) % MOD) - DP[i][(k - 1)%2] + MOD) % MOD;
				DP[i][k%2] = (DP[i][k%2] + MOD) % MOD;

				pref[i][k%2] += DP[i][k%2];
				pref[i][k%2] %= MOD;
			}
		}
	}

	/*for ( ll i = 1; i <= N; i++ )
	{
		for ( ll k = K - 1; k <= K; k++ )
			cout << DP[i][k%2] << " ";
		cout << "\n";
	}*/
	cout << (DP[a][K%2] + MOD) % MOD << "\n";
	return 0;
}
