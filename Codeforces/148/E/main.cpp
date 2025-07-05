#include <iostream>
#include <algorithm>
#include <vector>
#define max_cool(a, b) (a > b ? a : b)
#define min_cool(a, b) (a < b ? a : b)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	ll N, M;
	cin >> N >> M;

	ll n[N], a[N][100];
	for ( ll i = 0; i < N; i++ )
	{
		cin >> n[i];
		for ( ll j = 0; j < n[i]; j++ )
			cin >> a[i][j];
	}
	
	ll dp1[101][101][101], pre[N][101];
	for ( ll i = 0; i < N; i++ )
	{
		pre[i][0] = 0;
		for ( ll l = 0; l < n[i]; l++ )
			for ( ll r = l; r < n[i]; r++ )
				dp1[1][l][r] = max_cool(a[i][l], a[i][r]);
		pre[i][1] = dp1[1][0][n[i] - 1];

		for ( ll k = 2; k <= n[i]; k++ )
		{
			for ( ll l = 0; l < n[i]; l++ )
				for ( ll r = l + k - 1; r < n[i]; r++ )
					dp1[k][l][r] = max_cool ( dp1[k - 1][l + 1][r] + a[i][l],
											dp1[k - 1][l][r - 1] + a[i][r] );
			pre[i][k] = dp1[k][0][n[i] - 1];
		}
	}
	
	ll dp2[N + 1][M + 1];
	const ll INF = (1LL << 60LL);
	dp2[N][0] = 0;
	for ( ll k = 1; k <= M; k++ )
		dp2[N][k] = -INF;
	for ( ll i = N - 1; i >= 0; i-- )
		for ( ll k = 0; k <= M; k++ )
		{
			dp2[i][k] = 0;
			for ( ll j = 0; j <= min_cool ( n[i], k ); j++ )
				dp2[i][k] = max_cool ( dp2[i][k], dp2[i + 1][k - j] + pre[i][j] );
		}
	cout << dp2[0][M] << "\n";
	return 0;
}
