#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	string S;
	cin >> S;
	vl MP ( 26, 0 );
	MP[S[0] - 'a']++;
	vector < vl > ans ( 26, vl ( 26, 0 ) );
	for ( int i = 1; i < S.length(); i++ )
	{
		for ( char c = 'a'; c <= 'z'; c++ )
			ans[c - 'a'][S[i] - 'a'] += MP[c - 'a'];
		MP[S[i] - 'a']++;
	}
	ll res = 0;
	for ( int i = 0; i < 26; i++ )
	{
		res = max ( res, MP[i] );
		for ( int j = 0; j < 26; j++ )
			res = max ( res, ans[i][j] );
	}
	cout << res << "\n";
	return 0;
}
