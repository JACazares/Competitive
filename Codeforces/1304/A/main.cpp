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
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if ( y >= x && (y - x) % (a + b) == 0 )
			cout << (y - x) / (a + b) << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}
