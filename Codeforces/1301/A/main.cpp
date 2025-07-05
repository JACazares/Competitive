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
		string a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for ( int i = 0; i < a.length(); i++ )
			if ( a[i] == c[i] || b[i] == c[i] )
				ans++;
		cout << (ans == a.length() ? "YES" : "NO") << "\n";
	}
	return 0;
}
