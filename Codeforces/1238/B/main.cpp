#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

int Q, N, R, x[MAXN], c;

int main ()
{
	cin >> Q;
	while ( Q-- )
	{
		cin >> N >> R;
		for ( int i = 0; i < N; i++ )
			cin >> x[i];
		sort ( x, x + N );
		
		c = 1;
		for ( int i = N - 2; i >= 0; i-- )
			if ( x[i] != x[i + 1] && x[i] - c*R > 0 )
				c++;
		
		cout << c << "\n";
	}
	return 0;
}
