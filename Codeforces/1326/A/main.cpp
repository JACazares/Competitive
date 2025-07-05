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
		if ( N == 1 )
			cout << "-1\n";
		else
		{
			cout << "2";
			for ( int i = 1; i < N; i++ )
				cout << "3";
			cout << "\n";
		}
	}
	return 0;
}
