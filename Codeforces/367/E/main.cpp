#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 350, MOD = 1e9 + 7;
int N, M, X;
ll DP[2][MAXN][MAXN][2];

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M >> X;
	if ( N > M )
	{
		cout << "0\n";
		return 0;
	}

	DP[(M + 1)&1][0][N][1] = 1;
	// curr_number
	for ( int i = M; i >= 1; i-- )
	{
		// open_intervals
		for ( int j = 0; j <= N; j++ )
		{
			// total_intervals
			for ( int k = j; k <= N; k++ )
			{
				//do nothing
				DP[i&1][j][k][0] = DP[(i+1)&1][j][k][0];
				DP[i&1][j][k][1] = DP[(i+1)&1][j][k][1];
				//open a new interval
				if ( i == X )
					DP[i&1][j][k][0] += DP[(i + 1)&1][j + 1][k + 1][1];
				else
					DP[i&1][j][k][0] += DP[(i + 1)&1][j + 1][k + 1][0];
				DP[i&1][j][k][1] += DP[(i + 1)&1][j + 1][k + 1][1];
				//close an open interval
				if ( j > 0 )
				{
					DP[i&1][j][k][0] += DP[(i + 1)&1][j - 1][k][0];
					DP[i&1][j][k][1] += DP[(i + 1)&1][j - 1][k][1];
				}
				//open & close the first open one
				if ( i == X )
					DP[i&1][j][k][0] += DP[(i + 1)&1][j][k + 1][1];
				else
					DP[i&1][j][k][0] += DP[(i + 1)&1][j][k + 1][0];
				DP[i&1][j][k][1] += DP[(i + 1)&1][j][k + 1][1];
				
				DP[i&1][j][k][0] %= MOD;
				DP[i&1][j][k][1] %= MOD;
			}
		}
	}
	ll fact = 1;
	for ( ll i = 1; i <= N; i++ )
	{
		fact *= i;
		fact %= MOD;
	}
	cout << (DP[1][0][0][0] * fact) % MOD << "\n";
	return 0;
}
