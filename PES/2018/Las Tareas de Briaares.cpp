#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define MAXN 100005

using namespace std;

typedef long long int lld;

lld N, K, a[MAXN], finalans, ans, pref[MAXN];
lld lpnt, rpnt, cnt, diff;
double L, R;
lld minim;

int main()
{
	cin >> N >> K;
	for ( lld i = 0; i < N; i++ )
		cin >> a[i];
	sort ( a, a + N );
	for ( lld i = 0; i < N; i++ )
	{
		if ( i )
			pref[i] = pref[i - 1];
		pref[i] += a[i];
	}
	
	K = K - 1;
	lpnt = 0, rpnt = K;
	L = lpnt, R = rpnt;
	cnt = (K & 1);
	for ( lld i = floor( (L + R) / 2 ), j = ceil( (L + R) / 2 ); j <= R && i >= L; j++, i-- )
	{
		if ( j - i > 1 )
			diff += abs(a[j] - a[j-1]) + abs(a[i+1] - a[i]);
		else if (j - i == 1 )
			diff += abs(a[j] - a[j-1]);
		ans += (cnt * diff);
		cnt += 2;
	}
	minim = ans;
	
	//cout << ans << "\n";
	
	for ( lpnt = 1; lpnt < N - K; lpnt++ )
	{
		rpnt++;
		ans = ans + (K * a[lpnt - 1]) + (K * a[rpnt]) - (2 * (pref[rpnt - 1] - pref[lpnt - 1]));
		//cout << ans << "\n";
		minim = min( minim, ans );
	}
	
	cout << minim << "\n";
	
	return 0;
}
