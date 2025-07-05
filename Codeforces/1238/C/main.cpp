#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXN = 200005;

ll Q, H, N, a[MAXN], cnt;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> Q;
	while ( Q-- )
	{
		cin >> H >> N;
		for ( ll i = 0; i < N; i++ )
			cin >> a[i];
		a[N] = 0;
		
		cnt = 0;
		for ( ll i = 0; i < N - 1; i++ )
		{
			a[i] = a[i + 1] + 1;
			
			if ( i + 2 <= N && a[i + 2] == a[i] - 2 )
				i++;
			else
				a[i + 1] = a[i] - 2, cnt++;
		}
		
		cout << cnt << "\n";
	}
	return 0;
}
