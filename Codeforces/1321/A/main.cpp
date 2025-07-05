#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	vi a(N), b(N);
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	for ( int i = 0; i < N; i++ )
		cin >> b[i];
	
	int ans = 0, last = 0;
	for ( int i = 0; i < N; i++ )
	{
		if ( a[i] == 1 && b[i] == 0 )
			ans++;
		if ( a[i] == 0 && b[i] == 1 )
			last++;
	}
	if ( ans == 0 )
		cout << "-1\n";
	else
	{
		cout.setf ( ios::fixed );
		cout.precision ( 0 );
		cout << ceil ( (last + 1.0) / ans ) << "\n";
	}
	return 0;
}
