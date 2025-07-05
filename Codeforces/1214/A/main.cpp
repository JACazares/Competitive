#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll N, d, e, aux, ans = (1 << 30);

int main ()
{
	cin >> N;
	cin >> d >> e;
	
	for ( ll i = 0; 5 * e * i <= N; i++ )
	{
		aux = N - 5 * e * i;
		aux %= d;
		ans = min ( ans, aux );
	}
	cout << ans << "\n";
	return 0;
}
