#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi convert ( ll n, ll b )
{
	if ( n == 0 )
		return vi ( 1, 0 );
	vi aux = convert ( n / b, b );
	aux.push_back ( n % b );
	return aux;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	ll T;
	cin >> T;
	while ( T-- )
	{
		ll N, K, x, ans = 1;
		cin >> N >> K;
		vi a[N], vis ( 60 );
		for ( ll i = 0; i < N; i++ )
		{
			cin >> x;
			a[i] = convert ( x, K );
			for ( ll j = 0; j < a[i].size(); j++ )
			{
				if ( a[i][j] > 1 )
					ans = 0;
				else if ( a[i][j] == 1 && !vis[a[i].size() - j] )
					vis[a[i].size() - j] = 1;
				else if ( a[i][j] == 1 && vis[a[i].size() - j] )
					ans = 0;
			}
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}
