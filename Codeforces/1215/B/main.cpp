#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXN = 200005;

ll N, a[MAXN], pre[MAXN], MP[3], neg, pos;

int main ()
{
	cin >> N;
	pre[0] = 1;
	for ( ll i = 1; i <= N; i++ )
		cin >> a[i], a[i] = (a[i] > 0 ? 1 : -1), pre[i] = pre[i - 1] * a[i];
		
	MP[2]++;
	for ( ll i = 1; i <= N; i++ )
	{
		if ( pre[i] == -1 )
			pos += MP[0], neg += MP[2];
		else
			pos += MP[2], neg += MP[0];
		MP[pre[i] + 1]++;
	}
	cout << neg << " " << pos << "\n";
	return 0;
}
