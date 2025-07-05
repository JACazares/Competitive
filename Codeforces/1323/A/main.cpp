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
		vi a ( N ), even, odd;
		for ( int i = 0; i < N; i++ )
		{
			cin >> a[i];
			if ( a[i] % 2 == 0 )
				even.push_back ( i + 1 );
			else
				odd.push_back ( i + 1 );
		}
		
		if ( even.size() )
			cout << "1\n" << even[0] << "\n";
		else if ( odd.size() > 1 )
			cout << "2\n" << odd[0] << " " << odd[1] << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}
