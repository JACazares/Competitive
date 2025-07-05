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
		int N, D;
		cin >> N >> D;
		vi a ( N );
		for ( int i = 0; i < N; i++ )
			cin >> a[i];
		for ( int i = 1; i < N; i++ )
			while ( a[i] && D >= i )
				a[i]--, a[0]++, D -= i;
		cout << a[0] << "\n";
	}
	return 0;
}
