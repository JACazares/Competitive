#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	ll N;
	cin >> N;
	ll b[N], a[N];
	for ( ll i = 0; i < N; i++ )
		cin >> b[i];
	a[0] = b[0];
	ll maxim = 0;
	maxim = max ( maxim, a[0] );
	for ( ll i = 1; i < N; i++ )
	{
		a[i] = b[i] + maxim;
		maxim = max ( maxim, a[i] );
	}
	for ( ll i = 0; i < N; i++ )
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}
