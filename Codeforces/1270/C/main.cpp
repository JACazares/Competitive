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
		ll x, xor_sum = 0, sum = 0;
		for ( int i = 0; i < N; i++ )
			cin >> x, xor_sum ^= x, sum += x;
		
		cout << "2\n";
		cout << xor_sum << " " << xor_sum + sum << "\n";
	}
	return 0;
}
