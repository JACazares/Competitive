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
		ll a, b, x, y;
		cin >> a >> b >> x >> y;
		ll ans;
		ans = max ( max ( x * b, (a-x-1) * b ), max ( y * a, (b-y-1) * a ) );
		cout << ans << "\n";
	}
	return 0;
}
