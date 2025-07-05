#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LOG = 30;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	vi a ( N );
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	
	int ans = -1;
	for ( int bit = LOG; bit >= 0; bit-- )
	{
		int cnt = 0;
		for ( int i = 0; i < N; i++ )
			if ( a[i] & (1 << bit) )
				cnt++;

		if ( cnt != 1 )
			continue;

		for ( int i = 0; i < N; i++ )
			if ( a[i] & (1 << bit) )
				ans = i;
		break;
	}
	if ( ans != -1 )
		cout << a[ans] << " ";
	for ( int i = 0; i < N; i++ )
		if ( i != ans )
			cout << a[i] << " ";
	cout << "\n";
	return 0;
}
