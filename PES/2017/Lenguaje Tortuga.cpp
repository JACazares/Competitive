#include <iostream>
#define MAXN 105
#define INF (1 << 30)

using namespace std;
typedef long long ll;

int C, DP1[MAXN][MAXN][2], DP2[MAXN][MAXN][2];
string S;

int dp1 ( int i, int l, bool d )
{
	if ( i == S.length() )
	{
		if ( l % 2 == 0 )
			return 0;
		return -INF;
	}
	
	if ( DP1[i][l][d] )
		return DP1[i][l][d];
	
	int dist = (d ? -1 : 1 );
	if ( l > 0 )
	{
		if ( S[i] == 'F' )
			DP1[i][l][d] = max ( dp1 ( i + 1, l, d ) + dist, dp1 ( i + 1, l - 1, !d ) );
		else
			DP1[i][l][d] = max ( dp1 ( i + 1, l, !d ), dp1 ( i + 1, l - 1, d ) + dist );
	}
	else
	{
		if ( S[i] == 'F' )
			DP1[i][l][d] = dp1 ( i + 1, l, d ) + dist;
		else
			DP1[i][l][d] = dp1 ( i + 1, l, !d);
	}

	return DP1[i][l][d];
}

int dp2 ( int i, int l, bool d )
{
	if ( i == S.length() )
	{
		if ( l % 2 == 0 )
			return 0;
		return INF;
	}
	
	if ( DP2[i][l][d] )
		return DP2[i][l][d];
	
	int dist = (d ? -1 : 1 );
	if ( l > 0 )
	{
		if ( S[i] == 'F' )
			DP2[i][l][d] = min ( dp2 ( i + 1, l, d ) + dist, dp2 ( i + 1, l - 1, !d ) );
		else
			DP2[i][l][d] = min ( dp2 ( i + 1, l, !d ), dp2 ( i + 1, l - 1, d ) + dist );
	}
	else
	{
		if ( S[i] == 'F' )
			DP2[i][l][d] = dp2 ( i + 1, l, d ) + dist;
		else
			DP2[i][l][d] = dp2 ( i + 1, l, !d);
	}

	return DP2[i][l][d];
}


int main ()
{
	cin >> S;
	cin >> C;

	cout << max ( dp1 ( 0, C, 0 ), dp2 ( 0, C, 0 ) * -1 ) << "\n";
	return 0;
}
