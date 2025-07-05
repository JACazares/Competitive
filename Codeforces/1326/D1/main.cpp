#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
	
string S;

bool isPalin ( int l, int r )
{
	for ( int i = l, j = r; i < j; i++, j-- )
		if ( S[i] != S[j] )
			return false;
	return true;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int T;
	cin >> T;
	while ( T-- )
	{
		cin >> S;
		int lpnt, rpnt;
		for ( lpnt = 0, rpnt = S.length() - 1; lpnt < rpnt; lpnt++, rpnt-- )
			if ( S[lpnt] != S[rpnt] )
				break;
		
		if ( lpnt >= rpnt )
		{
			cout << S << "\n";
			continue;
		}
		int middleL = lpnt;
		for ( int i = lpnt; i <= rpnt; i++ )
			if ( isPalin ( lpnt, i ) )
				middleL = i;
		int middleR = rpnt;
		for ( int i = rpnt; i >= lpnt; i-- )
			if ( isPalin ( i, rpnt ) )
				middleR = i;
		
		if ( middleL - lpnt > rpnt - middleR )
		{
			for ( int i = 0; i <= middleL; i++ )
				cout << S[i];
			for ( int i = rpnt + 1; i < S.length(); i++ )
				cout << S[i];
			cout << "\n";
		}
		else
		{
			for ( int i = 0; i < lpnt; i++ )
				cout << S[i];
			for ( int i = middleR; i < S.length(); i++ )
				cout << S[i];
			cout << "\n";
		}
	}
	return 0;
}
