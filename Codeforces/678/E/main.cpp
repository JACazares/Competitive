#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ld> vd;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	ld p[N + 5][N + 5];
	for ( int i = 1; i <= N; i++ )
		for ( int j = 1; j <= N; j++ )
			cin >> p[i][j];

	vector<vd> DP ( (1 << N), vd(N + 1, 0 ) );
	DP[(1<<N) - 1][1] = 1;
	for ( int mask = (1 << N) - 2; mask >= 0; mask-- )
	{
		for ( int i = 1; i <= N; i++ )
		{
			for ( int j = 1; j <= N; j++ )
			{
				if ( !(mask & (1 << (j - 1))) )
				{
					ld aux = p[i][j]*DP[mask | (1 << (j-1))][i] + p[j][i]*DP[mask | (1 << (j-1))][j];
					DP[mask][i] = max ( DP[mask][i], aux );
				}
			}
		}
	}

	ld ans = 0;
	for ( int i = 1; i <= N; i++ )
		ans = max ( ans, DP[(1 << (i-1))][i] );
	cout.setf ( ios::fixed );
	cout.precision ( 10 );
	cout << ans << "\n";
	return 0;
}
