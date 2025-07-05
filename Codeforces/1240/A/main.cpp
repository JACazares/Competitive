#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXN = 200005;

ll N, K, p[MAXN], x, y, a, b;
priority_queue < ll > PQ;

bool solve ( ll v )
{
	ll sell1 = 0, sell2 = 0, sell3 = 0;
	while ( !PQ.empty() )
		PQ.pop();
	for ( ll i = 0; i < v; i++ )
	{
		PQ.push ( p[i] );
		if ( (i + 1) % a == 0 && (i + 1) % b == 0 )
			sell3++;
		else if ( (i + 1) % a == 0 )
			sell1++;
		else if ( (i + 1) % b == 0 )
			sell2++;
	}
	
	ll ans = 0;
	for ( ll i = 0; i < sell3; i++ )
		ans += PQ.top() / 100 * (x + y), PQ.pop();
	for ( ll i = 0; i < sell1; i++ )
		ans += PQ.top() / 100 * x, PQ.pop();
	for ( ll i = 0; i < sell2; i++ )
		ans += PQ.top() / 100 * y, PQ.pop();
	
	return (ans >= K);
}

int main ()
{
	ll Q;
	cin >> Q;
	while ( Q-- )
	{
		cin >> N;
		for ( ll i = 0; i < N; i++ )
			cin >> p[i];

		cin >> x >> a;
		cin >> y >> b;
		if ( x < y )
			swap ( x, y ), swap ( a, b );

		cin >> K;
	
		ll s = 1, e = N, ans = -1, mid, val;
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
	}
	return 0;
}
