#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 150005;

int T, N, a[MAXN];

int main ()
{
	cin >> T;
	while ( T-- )
	{
		cin >> N;
		for ( int i = 0; i < N; i++ )
			cin >> a[i];
		
		int maxim = (1 << 30), ans = 0;
		for ( int i = N - 1; i >= 0; i-- )
		{
			if ( a[i] <= maxim )
				maxim = a[i];
			else
				ans++;
		}
		
		cout << ans << "\n";
	}
	return 0;
}
