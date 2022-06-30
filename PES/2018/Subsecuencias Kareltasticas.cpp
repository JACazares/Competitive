#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MAXN 300005
#define MOD 1000000007
using namespace std;

typedef long long int lld;

lld N, a[MAXN], Q, pos, x, ans, finalAns, posL, posM, posR, xL, xM, xR;
unordered_map < lld, lld > MAP;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for ( lld i = 1; i <= N; i++ )
	{
		cin >> a[i];
		x = a[i];
		xL = MAP[x - 1];
		xM = MAP[x]++;
		xR = MAP[x + 1];
		if ( xM >= max ( xL, xR ) )
			ans++;
		if ( xM < min ( xL, xR ) )
			ans--;
	}
	//cout << ans << "\n";

	cin >> Q;
	for ( lld i = 1; i <= Q; i++ )
	{
		cin >> pos >> x;

		//cout << posL << " " << posM << " " << posR << "\n";
		//cout << xL << " " << xM << " " << xR << "\n";
		posL = MAP[a[pos] - 1];
		posM = MAP[a[pos]]--;
		posR = MAP[a[pos] + 1];
		
		if ( posM > max ( posL, posR ) )
			ans--;
		if ( posM <= min ( posL, posR ) )
			ans++;

		xL = MAP[x - 1];
		xM = MAP[x]++;
		xR = MAP[x + 1];
		if ( xM >= max ( xL, xR ) )
			ans++;
		if ( xM < min ( xL, xR ) )
			ans--;
	
		a[pos] = x;

		//cout << ans << "\n";
			
		finalAns += ( ( i * ( ans % MOD ) )  % MOD );
		finalAns %= MOD;
	}

	cout << finalAns << "\n";
	return 0;
}
