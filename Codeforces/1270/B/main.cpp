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
		int ans = -1;
		vi a ( N );
		for ( int i = 0; i < N; i++ )
		{
			cin >> a[i];
			if ( i )
			{
				ll dif = a[i] - a[i - 1];
				if ( abs ( dif ) >= 2 )
					ans = i;
			}
		}
		if ( ans != -1 )
			cout << "YES\n" << ans << " " << ans + 1 << "\n";
		else
			cout << "NO\n";
	}
	return 0;
}
