#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = (1 << 30);

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int T;
	cin >> T;
	while ( T-- )
	{
		int N;
		cin >> N;
		vi a ( N );
		for ( int i = 0; i < N; i++ )
			cin >> a[i];
		
		int maxim = -INF, minim = INF, possibleAns = 0;
		for ( int i = 1; i < N; i++ )
		{
			if ( a[i - 1] == -1 && a[i] != -1 )
			{
				maxim = max ( maxim, a[i] );
				minim = min ( minim, a[i] );
			}
			if ( a[i] == -1 && a[i - 1] != -1)
			{
				maxim = max ( maxim, a[i - 1] );
				minim = min ( minim, a[i - 1] );
			}
			
			if ( a[i] != -1 && a[i - 1] != -1 )
				possibleAns = max ( possibleAns, abs ( a[i] - a[i - 1] ) );
		}
		
		int K = (maxim + minim) / 2;
		int d = max ( maxim - K, K - minim );
		if ( maxim < minim )
			d = 0;
		cout << max ( d, possibleAns ) << " " << K << "\n";
	}
	return 0;
}
