#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool palindrome ( string a )
{
	for ( int i = 0, j = a.length() - 1; i < j; i++, j-- )
		if ( a[i] != a[j] )
			return false;
	return true;
}

bool palindrome ( string a, string b )
{
	for ( int i = 0, j = b.length() - 1; i < a.length(); i++, j-- )
		if ( a[i] != b[j] )
			return false;
	return true;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N, M;
	cin >> N >> M;
	vi palin ( N, 0 );
	vector<string> S ( N );
	for ( int i = 0; i < N; i++ )
		cin >> S[i], palin[i] = palindrome ( S[i] );
	string ansL, ansR;
	vi used ( N, 0 );
	for ( int i = 0; i < N; i++ )
		for ( int j = i + 1; j < N; j++ )
			if ( !used[j] && palindrome ( S[i], S[j] ) )
			{
				ansL = ansL + S[i];
				ansR = S[j] + ansR;
				used[j] = 1;
				break;
			}
	
	for ( int i = 0; i < N; i++ )
		if ( !used[i] && palin[i] )
		{
			ansL += S[i];
			used[i] = 1;
			break;
		}
	cout << ansL.length() + ansR.length() << "\n";
	cout << ansL << ansR << "\n";
	return 0;
}
