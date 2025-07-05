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
		for ( int i = 0; i < N; i++ )
			cin >> a[i];
		
		int ans = 0;
		for ( int i = 0; i < N - 2; i++ )
			for ( int j = i + 2; j < N; j++ )
				if ( a[i] == a[j] )
					ans = 1;
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}
