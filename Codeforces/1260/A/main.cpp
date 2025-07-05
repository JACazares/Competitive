#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main ()
{
	ll N;
	cin >> N;
	while ( N-- )
	{
		ll c, sum, ans = 0;
		cin >> c >> sum;
		
		ll ce = ceil ( (double)sum / c );
		ll fl = floor ( (double)sum / c );
		
		ans = ce * ce * (sum % c) + fl * fl * (c - sum%c);
		
		cout << ans << "\n";
	}
	return 0;
}
