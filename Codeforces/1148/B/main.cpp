#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	int N, M, t1, t2, K;
	cin >> N >> M >> t1 >> t2 >> K;
	int a[N], b[M];
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	for ( int i = 0; i < M; i++ )
		cin >> b[i];
	
	int pos = 0, ans = 0;
	for ( int i = 0; i <= min ( N - 1, K ); i++ )
	{
		pos = lower_bound ( b, b + M, a[i] + t1 ) - b;
		if ( pos + K - i < M )
			ans = max ( ans, b[pos + K - i] + t2 );
		else
		{
			ans = -1;
			break;
		}
	}
	
	if ( K >= min ( N, M ) )
		ans = -1;
	
	cout << ans << "\n";
	return 0;
}
