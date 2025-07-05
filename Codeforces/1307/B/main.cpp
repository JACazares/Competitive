#include <iostream>
#include <algorithm>
#include <cmath>
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
		int N, X;
		cin >> N >> X;
		int a, special = 0, maxim = 0;
		for ( int i = 0; i < N; i++ )
		{
			cin >> a;
			if ( a == X )
				special = 1;
			maxim = max ( maxim, a );
		}
		
		cout.setf ( ios::fixed );
		cout.precision ( 0 );
		if ( special )
			cout << "1\n";
		else if ( 2*maxim >= X )
			cout << "2\n";
		else
			cout << ceil ( (double)(X - 2*maxim) / (double)maxim ) + 2 << "\n";
	}
	return 0;
}
