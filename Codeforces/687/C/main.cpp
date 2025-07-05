#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N, K;
	cin >> N >> K;
	vi a ( N );
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	vector<vector<vi>> DP ( 2, vector<vi> ( K + 5, vi ( K + 5, 0 ) ) );
	DP[N&1][0][0] = 1;
	for ( int i = N - 1; i >= 0; i-- )
	{
		for ( int j = 0; j <= K; j++ )
		{
			for ( int k = 0; k <= K; k++ )
			{
				if ( j - a[i] >= 0 )
					DP[i&1][j][k] += DP[(i + 1)&1][j - a[i]][k];
				if ( k - a[i] >= 0 )
					DP[i&1][j][k] += DP[(i + 1)&1][j][k - a[i]];
				DP[i&1][j][k] += DP[(i + 1)&1][j][k];
				DP[i&1][j][k] = min ( DP[i&1][j][k], 1 );
			}
		}
	}
	
	vi ans;
	for ( int i = 0; i <= K; i++ )
		if ( DP[0][i][K - i] )
			ans.push_back ( i );
	cout << ans.size() << "\n";
	for ( auto i : ans )
		cout << i << " ";
	cout << "\n";
	return 0;
}
