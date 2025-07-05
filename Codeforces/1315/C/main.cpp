#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 105;
int T, N, a[MAXN], b[2*MAXN], used[2*MAXN];
vector<pair<int, pair<int, vi>>> c;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> T;
	while ( T-- )
	{
		cin >> N;
		for ( int i = 1; i <= 2*N; i++ )
		{
			b[i - 1] = 0;
			used[i] = 0;
		}
		for ( int i = 0; i < N; i++ )
		{
			cin >> a[i];
			used[a[i]] = 1;
			b[2*i] = a[i];
		}
		c.clear();
		c.resize ( N );
		for ( int i = 0; i < 2*N; i += 2 )
		{
			c[i/2].second.first = i + 1;
			for ( int j = b[i] + 1; j <= 2*N; j++ )
			{
				if ( used[j] )
					continue;
				c[i/2].first++;
				c[i/2].second.second.push_back ( j );
			}
		}
		sort ( c.begin(), c.end() );
		for ( int i = 0; i < N; i++ )
		{
			for ( auto j : c[i].second.second )
			{
				if ( !used[j] )
				{
					b[c[i].second.first] = j;
					used[j] = 1;
					break;
				}
			}
		}
		
		bool ans = 1;
		for ( int i = 0; i < 2*N; i++ )
			if ( b[i] == 0 )
				ans = 0;

		if ( !ans )
			cout << "-1\n";
		else
		{
			for ( int i = 0; i < 2*N; i++ )
				cout << b[i] << " ";
			cout << "\n";
		}
	}
	return 0;
}
