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
		int N, sum = 0, ans = 0, a = 0;
		cin >> N;
		for ( int i = 0; i < N; i++ )
		{
			cin >> a, sum += a;
			if ( a == 0 )
				sum++, ans++;
		}
		if ( sum == 0 )
			ans++;
		cout << ans << "\n";
	}
	return 0;
}
