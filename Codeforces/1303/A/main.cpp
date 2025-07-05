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
		int n = 0;
		for ( auto i : S )
			if ( i == '0' )
				n++;
		if ( n == S.length() )
		{
			cout << "0\n";
			continue;
		}
		for ( int i = 0; i < S.length(); i++ )
		{
			if ( S[i] == '0' )
				n--;
			else
				break;
		}

		for ( int i = S.length() - 1; i >= 0; i-- )
		{
			if ( S[i] == '0' )
				n--;
			else
				break;
		}
		
		cout << n << "\n";
	}
	return 0;
}
