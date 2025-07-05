#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	const int MOD = 1e9 + 7;
	int N, K;
	cin >> N >> K;
	ll a[N + 5];
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	sort ( a, a + N );
	
	vector<vector<vl>> DP ( 2, vector<vl> ( N + 5, vl ( K + 5, 0 ) ) );
	for ( int k = 0; k <= K; k++ )
		DP[N&1][0][k] = 1;
	for ( int i = N - 1; i >= 0; i-- )
	{
		for ( int j = 0; j <= N; j++ )
		{
			for ( int k = 0; k <= K; k++ )
			{
				ll val = 0;
				if ( i < N - 1 )
					val = (a[i+1] - a[i]);

				DP[i&1][j][k] = 0;
				// open a new group
				if ( i < N - 1 && k + val*(j + 1) <= K )
					DP[i&1][j][k] += DP[(i + 1)&1][j + 1][k + (val)*(j + 1)];
				DP[i&1][j][k] %= MOD;
				// close an existing group
				if ( j > 0 && k + val*(j - 1) <= K )
					DP[i&1][j][k] += DP[(i + 1)&1][j - 1][k + (val)*(j - 1)] * j;
				DP[i&1][j][k] %= MOD;
				// be a group by myself
				if ( k + val*j <= K )
					DP[i&1][j][k] += DP[(i + 1)&1][j][k + (val)*j];
				DP[i&1][j][k] %= MOD;
				// become part of a group, not closing it
				if ( j > 0 && k + val*j <= K )
					DP[i&1][j][k] += DP[(i + 1)&1][j][k + (val)*j] * j;
				DP[i&1][j][k] %= MOD;
			}
		}
	}
	
	cout << DP[0][0][0] << "\n";
	return 0;
}
