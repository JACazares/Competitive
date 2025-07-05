#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int T;
	cin >> T;
	while ( T-- )
	{
		ll n, b, g;
		cin >> n >> b >> g;
		ll x = (ceil(n/2.0) - 1) / b;
		ll ans = x * (b+g) + ceil(n/2.0)-(x*b);
		cout << max ( n, ans ) << "\n";
	}
	return 0;
}