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
		string S;
		cin >> N >> S;
		
		int cnt = 0;
		vi sz;
		for ( auto i : S )
		{
			cnt++;
			if ( i == '<' )
				sz.push_back ( cnt ), cnt = 0;
		}
		sz.push_back ( cnt + 1 ), cnt = 0;
		
		vector < vi > smallest ( sz.size() ), greatest ( sz.size() );
		for ( int i = 0; i < greatest.size(); i++ )
			smallest[i].resize ( sz[i] );
		for ( int i = 0; i < greatest.size(); i++ )
			greatest[i].resize ( sz[i] );

		cnt = N;
		for ( int i = 0; i < sz.size(); i++ )
		{
			if ( sz[i] == 1 )
				continue;
			smallest[i][0] = cnt--;
			for ( int j = i - 1; sz[j] == 1; j-- )
				smallest[j][0] = cnt--;
		}
		for ( int j = sz.size() - 1; sz[j] == 1; j-- )
			smallest[j][0] = cnt--;
		for ( int i = 0; i < sz.size(); i++ )
			for ( int j = 1; j < sz[i]; j++ )
				smallest[i][j] = cnt--;

		cnt = 1;
		for ( int i = 0; i < sz.size(); i++ )
			for ( int j = sz[i] - 1; j >= 0; j-- )
				greatest[i][j] = cnt++;
		
		for ( auto i : smallest )
			for ( auto j : i )
				cout << j << " ";
		cout << "\n";

		for ( auto i : greatest )
			for ( auto j : i )
				cout << j << " ";
		cout << "\n";
	}
	return 0;
}
