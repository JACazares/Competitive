#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXN = 2005;

ll N, a[MAXN];
unordered_map < ll, ll > MP;

bool solve ( ll x )
{
	ll sub = 0;
	for ( ll i = 0; i < N; i++ )
		MP[a[i]] = 0;
	for ( ll i = 0; i < N; i++ )
	{
		MP[a[i]]++;
		if ( MP[a[i]] >= 2 )
			sub++;
	}
	
	for ( ll i = 0; i < x; i++ )
	{
		MP[a[i]]--;
		if ( MP[a[i]] != 0 )
			sub--;
	}
	
	for ( ll i = x; i < N; i++ )
	{
		if ( sub == 0 )
			break;
		
		MP[a[i - x]]++;
		if ( MP[a[i - x]] >= 2 )
			sub++;
		MP[a[i]]--;
		if ( MP[a[i]] != 0 )
			sub--;
	}
	
	return (sub == 0);
}

int main ()
{
	cin >> N; 
	for ( ll i = 0; i < N; i++ )
		cin >> a[i];
	
	ll s = 0, e = N, mid, val, ans = N;
	while ( s <= e )
	{
		mid = (s + e) / 2;
		val = solve ( mid );
		
		if ( val )
			ans = mid, e = mid - 1;
		else
			s = mid + 1;
	}

	cout << ans << "\n";
	return 0;
}
