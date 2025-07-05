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
		int N;
		cin >> N;
		vi a ( N );
		int ans = 1;
		for ( int i = 0; i < N; i++ )
		{
			cin >> a[i];
			if ( a[i] % 2 != a[0] % 2 )
				ans = 0;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}
