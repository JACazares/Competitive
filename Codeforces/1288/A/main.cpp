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
		int N, D;
		cin >> N >> D;
		
		if ( D <= N )
			cout << "YES\n";
		else
		{
			int ans = 0;
			for ( int i = 1; i <= min ( N, 1000000 ); i++ )
			{
				if ( i + ceil ( (double)D / (i + 1) ) <= N )
				{
					ans = 1;
					break;
				}
			}
			for ( int i = min ( N, 1000 ); i >= 1; i-- )
			{
				int x = (D - i) / i + i;
				if ( x + i <= N )
				{
					ans = 1;
					break;
				}
			}
			
			cout << (ans ? "YES" : "NO") << "\n";
		}
	}
	return 0;
}
