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
		string A, B;
		cin >> A >> B;
		if ( A < B )
		{
			cout << A << "\n";
			continue;
		}
		
		int lpnt = 0;
		for ( ; lpnt < min ( A.length(), B.length() ); lpnt++ )
			if ( A[lpnt] != B[lpnt] )
				break;
		
		if ( lpnt == A.length() && A.length() < B.length() )
		{
			cout << A << "\n";
			continue;
		}
		if ( lpnt == B.length() )
		{
			cout << "---\n";
			continue;
		}
		
		bool ans = 0;
		for ( int i = lpnt + 1; i < A.length(); i++ )
		{
			swap ( A[lpnt], A[i] );
			if ( A < B )
			{
				ans = 1;
				cout << A << "\n";
				break;
			}
			swap ( A[lpnt], A[i] );
		}
		if ( !ans )
			cout << "---\n";
	}
	return 0;
}
