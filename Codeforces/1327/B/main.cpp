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
		int a[N + 5];
		vi list[N + 5], used ( N + 1, 0 ), married ( N + 1, 0 );
		for ( int i = 1; i <= N; i++ )
		{
			cin >> a[i];
			for ( int j = 0; j < a[i]; j++ )
			{
				int x;
				cin >> x;
				list[i].push_back ( x );
			}
			sort ( list[i].begin(), list[i].end() );
			for ( int j = 0; j < a[i]; j++ )
			{
				if ( !used[list[i][j]] )
				{
					used[list[i][j]] = 1;
					married[i] = 1;
					break;
				}
			}
		}
		bool ans = 0;
		for ( int i = 1; i <= N; i++ )
		{
			if ( !married[i] )
			{
				for ( int j = 1; j <= N; j++ )
				{
					if ( !used[j] )
					{
						cout << "IMPROVE\n";
						cout << i << " " << j << "\n";
						break;
					}
				}
				ans = 1;
				break;
			}
		}
		if ( !ans )
			cout << "OPTIMAL\n";
	}
	return 0;
}
