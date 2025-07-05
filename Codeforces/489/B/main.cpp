#include <iostream>
#include <algorithm>
#define MAXN 105
using namespace std;
typedef long long int lld;

int N, M, boy[MAXN], girl[MAXN], ans;

int main () {
	cin >> N;
	for ( int i = 0; i < N; i++ )
		cin >> boy[i];
	
	cin >> M;
	for ( int i = 0; i < M; i++ )
		cin >> girl[i];
	
	sort( boy, boy + N );
	sort( girl, girl + M );

	int boyInd = 0;
	int girlInd = 0;

	while ( boyInd < N && girlInd < M )
	{
		if ( abs( boy[boyInd] - girl[girlInd] ) <= 1)
			boyInd++, girlInd++, ans++;
		else if ( boy[boyInd] >= girl[girlInd] )
			girlInd++;
		else
			boyInd++;
	}
	

	cout << ans << "\n";

	return 0;
}
