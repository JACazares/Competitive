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
		int N, a, b;
		cin >> N >> a >> b;
		int x, maxim1 = 0, maxim2 = 0;
		for ( int i = 0; i < a; i++ )
			cin >> x, maxim1 = max ( maxim1, x );
		for ( int i = 0; i < b; i++ )
			cin >> x, maxim2 = max ( maxim2, x );
		cout << (maxim1 > maxim2 ? "YES" : "NO") << "\n";
	}
	return 0;
}
