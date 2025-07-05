#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 ); cout.tie ( 0 );
	int N;
	cin >> N;
	ll a[N], b[N];
	bool c[N];
	for ( int i = 0; i < N; i++ )
		cin >> a[i], b[i] = a[i];
	
	int cnt = N, odd = 0, ans = 0;
	for ( int i = 0; i < N; i++ )
		c[i] = 0;
	while ( cnt ) //will run at most O(lg N) times
	{
		odd = 0;
		cnt = 0;
		for ( int i = 0; i < N; i++ )
		{
			if ( a[i] % 2 == 1 )
				odd++;
			else if ( a[i] != 0 )
				cnt++;
		}
		
		if ( odd > ans )
		{
			for ( int i = 0; i < N; i++ )
			{
				c[i] = 0;
				if ( a[i] % 2 == 1 )
					c[i] = 1;
			}
			ans = odd;
		}

		for ( int i = 0; i < N; i++ )
		{
			if ( a[i] % 2 == 1 )
				a[i] = 0;
			else if ( a[i] != 0 )
				a[i] /= 2;
		}
	}
	
	cout << N - ans << "\n";
	for ( int i = 0; i < N; i++ )
		if ( !c[i] )
			cout << b[i] << " ";
	cout << "\n";
	return 0;
}
