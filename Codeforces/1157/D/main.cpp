#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXK = 100005;

ll N, K, sum, aux, ans[MAXK];

int main ()
{
	cin >> N >> K;
	sum = K * (K + 1) / 2;
	N -= sum;
	if ( N < 0 )
	{
		cout << "NO\n";
		return 0;
	}
	for ( ll i = 1; i <= K; i++ )
		ans[i] = i;
	
	aux = N / K;
	N %= K;
	for ( ll i = 1; i <= K; i++ )
		ans[i] += aux;
	
	ll s;
	if ( aux )
		s = 2;
	else
		s = 3;

	ll cnt = 0;
	for ( ll i = s; i <= K; i++ )
	{
		if ( N >= K - i + 1 )
			N -= (K - i + 1), cnt++;
		ans[i] += cnt;
	}
	
	if ( N == 0 )
	{
		cout << "YES\n";
		for ( ll i = 1; i <= K; i++ )
			cout << ans[i] << " ";
		cout << "\n";
	}
	else
		cout << "NO\n";
	return 0;
}
