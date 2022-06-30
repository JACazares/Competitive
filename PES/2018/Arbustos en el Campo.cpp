#include <iostream>
#include <algorithm>
#define MAXN 1005
using namespace std;

typedef long long int lld;

int N, L, cnt, rInd, lInd, DP[MAXN][MAXN][2];
lld a[MAXN], ans;

lld dp( int l, int r, bool f )
{
	if ( l == 0 && r == N + 1 )
		return 0;
	
	if ( DP[l][r][f] )
		return DP[l][r][f];

	lld pos;
	if ( !f )
		pos = a[l + 1];
	else
		pos = a[r - 1];
	
	if ( l == 0 )
		return DP[l][r][f] = dp ( l, r + 1, 1 ) + ( ( N + l - r + 1 ) * ( a[r] - pos ) );
	else if ( r == N + 1 )
		return DP[l][r][f] = dp ( l - 1, r, 0 ) + ( ( N + l - r + 1 ) * ( pos - a[l] ) );
	else
		return DP[l][r][f] = min( dp( l - 1, r, 0) + ( ( N + l - r + 1 ) * ( pos - a[l] ) ), dp ( l, r + 1, 1 ) + ( ( N + l - r + 1 ) * ( a[r] - pos ) ) ); 
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L;
	for ( int i = 1; i <= N; i++ )
		cin >> a[i];
		
	sort ( a + 1, a + N + 1 );
	
	cnt = N, lInd = 0, rInd = N + 1;

	for ( int i = 1; i <= N; i++ )
	{
		if ( a[i] <= L )
			lInd = i;
		else
		{
			rInd = i;
			break;
		}
	} 

	if ( lInd < 1 )
	{
		ans += ( (cnt--) * (a[1] - L) );
		for ( int i = 2; i <= N; i++ )
			ans += ( (cnt--) * (a[i] - a[i - 1]) );
	}
	else if ( rInd > N )
	{
		ans += ( (cnt--) * (L - a[N]) );
		for ( int i = N - 1; i >= 1; i-- )
			ans += ( (cnt--) * (a[i + 1] - a[i]) );
	}
	else
	{
		ans = min( dp( lInd - 1, rInd, 0 ) + (N * (L - a[lInd]) ), dp( lInd, rInd + 1, 1 ) + (N * (a[rInd] - L) ) );
	}
	
	cout << ans << "\n";
	return 0;
}
