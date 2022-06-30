#include <iostream>
using namespace std;

int T, dp[105][105][105];
string S;

int DP(int a, int b, int c) {
	if ( a == 0 && b == 0)
		return c;
	if ( a == 0 && c == 0)
		return b;
	if ( b == 0 && c == 0)
		return a;
	
	if( dp[a][b][c] )
		return dp[a][b][c];

	int ans = (1 << 30);
	if ( a > 0 && b > 0 )
		ans = min( ans, DP( a - 1, b - 1, c + 1) );
	if ( a > 0 && c > 0 )
		ans = min( ans, DP( a - 1, b + 1, c - 1) );
	if ( b > 0 && c > 0 )
		ans = min( ans, DP( a + 1, b - 1, c - 1) );
	
	return dp[a][b][c] = ans;
}

int main () {
	cin >> T;
	while ( T-- )
	{
		int numA = 0;
		int numB = 0;
		int numC = 0;

		cin >> S;
		for ( int i = 0; i < S.length(); i++ )
		{
			if ( S[i] == 'a' )
				numA++;
			else if ( S[i] == 'b' )
				numB++;
			else if ( S[i] == 'c' )
				numC++;
		}

		cout << DP(numA, numB, numC) << "\n";
	}
	return 0;
}
