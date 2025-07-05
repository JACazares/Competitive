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
	int N, H, L, R;
	cin >> N >> H >> L >> R;
	vi a ( N );
	for ( int i = 0; i < N; i++ )
		cin >> a[i];

	vector<vi> DP ( N + 5, vi ( H + 5, 0 ) );
	for ( int i = N - 1; i >= 0; i-- )
	{
		for ( int h = 0; h < H; h++ )
		{
			int a1 = 0, b1 = 0;
			if ( L <= (h + a[i]) % H && (h + a[i]) % H <= R )
				a1++;
			if ( L <= (h + a[i] - 1) % H && (h + a[i] - 1) % H <= R )
				b1++;

			DP[i][h] = max ( DP[i + 1][(h + a[i]) % H] + a1, DP[i + 1][(h + a[i] - 1) % H] + b1 );
		}
	}
	cout << DP[0][0] << "\n";
	return 0;
}
