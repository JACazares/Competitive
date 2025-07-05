#include <iostream>
#include <algorithm>
#include <unordered_map>
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
		int N, ans = 0;
		cin >> N;
		ll x;
		unordered_map < int, int > MP;
		for ( int i = 0; i < N; i++ )
		{
			cin >> x;
			if ( !MP[x] )
				ans++;
			MP[x]++;
		}
		cout << ans << "\n";
	}
	return 0;
}
