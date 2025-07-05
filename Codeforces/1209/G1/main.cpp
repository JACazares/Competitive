#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXN = 200005;

ll N, Q, a[MAXN], maxim[MAXN], freq[MAXN], ans, maxFreq, sz;

int main ()
{
	cin >> N >> Q;
	for ( ll i = 0; i < N; i++ )
		cin >> a[i], maxim[a[i]] = i, freq[a[i]]++;
	
	ll l = 0, r = -1;
	for ( ll i = 0; i < N; i++ )
	{
		while ( i < N && i > r )
		{
			sz = r - l + 1;
			ans += (sz - maxFreq);
			l = i;
			r = maxim[a[i]];
			maxFreq = freq[a[i]];
			sz = r - l + 1;
			i++;
		}

		if ( i < N && a[i] != a[i - 1] )
			r = max ( r, maxim[a[i]] ), maxFreq = max ( maxFreq, freq[a[i]] );
	}
	sz = r - l + 1;
	ans += (sz - maxFreq);
	
	cout << ans << "\n";
	return 0;
}
