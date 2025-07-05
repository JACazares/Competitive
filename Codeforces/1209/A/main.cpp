#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 105;

int N, a[MAXN], color[MAXN], ans;

int main ()
{
	cin >> N;
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	sort ( a, a + N );
	
	for ( int i = 0; i < N; i++ )
	{
		if ( !color[i] )
		{
			ans++;
			for ( int j = i + 1; j < N; j++ )
				if ( a[j] % a[i] == 0 )
					color[j] = 1;
		}
	}
	
	cout << ans << "\n";
	return 0;
}
