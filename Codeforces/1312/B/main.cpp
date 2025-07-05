#include <iostream>
#include <algorithm>
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
		int N;
		cin >> N;
		int a[N];
		for ( int i = 0; i < N; i++ )
			cin >> a[i];
		sort ( a, a + N, greater<int>() );
		for ( int i = 0; i < N; i++ )
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
