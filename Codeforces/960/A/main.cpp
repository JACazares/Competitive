#include <iostream>

using namespace std;
typedef long long int lld;

int cnt[3], changes;
string S;
bool ans = 1;

int main ()
{
	cin >> S;
	for ( int i = 0; i < S.length(); i++ )
		cnt[S[i] - 'a']++;

	if ( !(cnt[2] == cnt[0] or cnt[2] == cnt[1]))
		ans = 0;
	
	if ( S[0] != 'a' )
		ans = 0;

	for ( int i = 1; i < S.length(); i++ )
	{
		if ( S[i] != S[i - 1] )
		{
			if ( S[i] == 'b' && S[i - 1] != 'a' )
				ans = 0;
			else if ( S[i] == 'c' && S[i - 1] != 'b' )
				ans = 0;
			changes++;
		}
	}

	if ( changes != 2 )
		ans = 0;
	
	if ( ans )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
