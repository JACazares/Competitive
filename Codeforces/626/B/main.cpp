#include <iostream>
using namespace std;
typedef long long int lld;

int N, red, green, blue, DP[200][200][200], ans;
string S;

int dp( int r, int g, int b ) {
	if ( r + g + b == 1 ) {
		if ( r > g  && r > b)
			return 4;
		if ( g > r && g > b )
			return 2;
		if ( b > r && b > g )
			return 1;
	}

	if ( DP[r][g][b] )
		return DP[r][g][b];

	int retVal = 0;

	if ( r > 0 && g > 0 )
		retVal |= dp( r - 1, g - 1, b + 1 );
	if ( r > 0 && b > 0 )
		retVal |= dp( r - 1, g + 1, b - 1 );
	if ( g > 0 && b > 0 )
		retVal |= dp( r + 1, g - 1, b - 1 );
	if ( r > 1 )
		retVal |= dp( r - 1, g, b );
	if ( g > 1 )
		retVal |= dp( r, g - 1, b );
	if ( b > 1 )
		retVal |= dp( r, g, b - 1 );
	
	return DP[r][g][b] = retVal;
}

int main () {
	cin >> N;
	cin >> S;
	for ( int i = 0; i < N; i++ ) {
		if ( S[i] == 'R' )
			red++;
		else if ( S[i] == 'G' )
			green++;
		else if ( S[i] == 'B' )
			blue++;
	}

	ans = dp( red, green, blue );

	if ( ans & (1 << 0) )
		cout << "B";
	if ( ans & (1 << 1) )
		cout << "G";
	if ( ans & (1 << 2) )
		cout << "R";
	
	cout << "\n";
	return 0;
}
