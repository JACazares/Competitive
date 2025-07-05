#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int T;
	cin >> T;
	while ( T-- )
	{
		ll A, B;
		cin >> A >> B;
		cout << A * (ll)(log10 ( B + 1.0 ) ) << "\n";
	}
	return 0;
}
