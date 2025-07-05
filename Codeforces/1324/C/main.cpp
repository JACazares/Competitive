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
		string S;
		cin >> S;
		int last = -1, ans = 0;
		for ( int i = 0; i < S.length(); i++ )
		{
			if ( S[i] == 'R' )
			{
				ans = max ( ans, i - last );
				last = i;
			}
		}
		ans = max ( ans, (int)S.length() - last );
		cout << ans << "\n";
	}
	return 0;
}
