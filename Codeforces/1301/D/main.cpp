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
	int N, M, K;
	cin >> N >> M >> K;
	if  ( K > 4*N*M - 2*N - 2*M )
	{
		cout << "NO\n";
		return 0;
	}
	
	vector < pair < int, string > > ans;
	if ( M - 1 > 0 && K >= M - 1 )
		ans.push_back ( {M - 1, "R"} ), K -= (M - 1);
	else if ( M - 1 > 0 && K > 0 )
		ans.push_back ( {K, "R"} ), K = 0;
		
	if ( M - 1 > 0 && K >= M - 1 )
		ans.push_back ( {M - 1, "L"} ), K -= (M - 1);
	else if ( M - 1 > 0 && K > 0 )
		ans.push_back ( {M - 1, "L"} ), K = 0;
		
	for ( int i = 0; i < N - 1; i++ )
	{
		if ( K >= 1 )
			ans.push_back ( {1, "D"} ), K -= 1;
	
		if ( M - 1 > 0 && K >= 3*(M - 1) )
			ans.push_back ( {M - 1, "RUD"} ), K -= 3*(M - 1);
		else if ( M - 1 > 0 && K > 0 )
		{
			if ( K >= 3 )
				ans.push_back ( {K / 3, "RUD"} ), K %= 3;

			if ( K == 1 )
				ans.push_back ( {1, "R"} );
			else if ( K == 2 )
				ans.push_back ( {1, "RU"} );
			K = 0;
		}
		
		if ( M - 1 > 0 && K >= M - 1 )
			ans.push_back ( {M - 1, "L"} ), K -= (M - 1);
		else if ( M - 1 > 0 && K > 0 )
			ans.push_back ( {K, "L"} ), K = 0;
	}
	
	if ( K > 0 )
		ans.push_back ( {K, "U"} ), K = 0;
	
	cout << "YES\n";
	cout << ans.size() << "\n";
	for ( auto i : ans )
		cout << i.first << " " << i.second << "\n";
	return 0;
}
