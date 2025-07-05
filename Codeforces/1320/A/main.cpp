#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	ll ans = 0;
	map < int, ll > MP;
	for ( int i = 0; i < N; i++ )
	{
		int x;
		cin >> x;
		MP[x - i] += x;
		ans = max ( ans, MP[x - i] );
	}
	cout << ans << "\n";
	return 0;
}
