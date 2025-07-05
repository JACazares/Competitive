#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 998244353;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N, K;
	cin >> N >> K;
	ll a, ans1 = 0, ans2 = 1, last = -1;
	for ( int i = 0; i < N; i++ )
	{
		cin >> a;
		if ( a > N - K )
		{
			if ( last != -1 )
			{
				ans2 *= (i - last);
				ans2 %= MOD;
			}
			last = i;
			ans1 += a;
		}
	}
	cout << ans1 << " " << ans2 << "\n";
	return 0;
}
