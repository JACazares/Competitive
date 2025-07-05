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
	int T;
	cin >> T;
	while ( T-- )
	{
		ll N, M;
		cin >> N >> M;
		ll avg = (N - M)/(M + 1);
		ll mod = (N - M) % (M + 1);
		ll squares = (mod) * ((avg + 1) * (avg + 2)) / 2 + (M + 1 - mod) * ((avg) * (avg + 1)) / 2;
		ll ans = (N*(N + 1) / 2) - squares;
		cout << ans << "\n";
	}
	return 0;
}
