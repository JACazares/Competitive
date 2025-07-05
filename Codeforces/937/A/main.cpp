#include <iostream>
#include <algorithm>
#define MAXN 105
using namespace std;
typedef long long int lld;

int N, a[MAXN], ans;

int main () {
	cin >> N;
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	sort( a, a + N );

	for ( int i = 0; i < N; i++ )
	{
		if ( a[i] > 0 && a[i] != a[i - 1] )
			ans++;
	}

	cout << ans << "\n";
	return 0;
}
