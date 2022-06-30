/*
ID: coa21
PROG: teamwork
LANG: C++11
*/
#include <iostream>
#include <fstream>
#define MAXN 10005

#define UPLOAD 1
#if UPLOAD
#define cin ccin
#define cout ccout
#endif

using namespace std;
typedef long long ll;
ifstream ccin("teamwork.in");
ofstream ccout("teamwork.out");

ll N, K, a[MAXN], DP[MAXN], vis[MAXN];

ll dp ( ll i )
{
	if ( i == N )
		return 0;
	
	if ( vis[i] )
		return DP[i];

	ll maxim = 0;
	for ( ll j = 1; j <= K && i + j <= N; j++ )
	{
		maxim = max ( maxim, a[i + j - 1] );
		DP[i] = max ( DP[i], dp ( i + j ) + (j * maxim) );
	}

	vis[i] = 1;
	return DP[i];
}

int main ()
{
	cin >> N >> K;
	for ( ll i = 0; i < N; i++ )
		cin >> a[i];
	
	cout << dp ( 0 ) << "\n";
	return 0;
}
