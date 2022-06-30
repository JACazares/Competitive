/*
ID: josecaz1
PROG: money
LANG: C++11
*/
#include <iostream>
#include <fstream>
#define MAXN 10005
#define MAXV 30

#define UPLOAD 1
#if UPLOAD
#define cin ccin
#define cout ccout
#endif

using namespace std;
typedef long long int lld;
ifstream ccin( "money.in");
ofstream ccout("money.out");

lld V, N, a[MAXV], DP[MAXN][MAXV];

lld dp ( lld n, lld i ) 
{
	if ( n == 0 )
		return 1;
	if ( i == V || n <= 0) 
		return 0;
	if ( DP[n][i] > -1 )
		return DP[n][i];
	return DP[n][i] = dp ( n - a[i], i ) + dp ( n, i + 1 );
}

int main ()
{
	cin >> V >> N;
	for ( int i = 0; i < V; i++ )
		cin >> a[i];
	
	for ( int i = 0; i <= N; i++ )
		for ( int j = 0; j <= V; j++ )
			DP[i][j] = -1;
	
	cout << dp ( N, 0 ) << "\n";
	return 0;
}
