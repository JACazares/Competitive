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
	int Q;
	cin >> Q;
	while ( Q-- )
	{
		int N, M;
		cin >> N >> M;
		vi t(N + 1), l(N + 1), r(N + 1);
		t[0] = 0, l[0] = M, r[0] = M;
		for ( int i = 1; i <= N; i++ )
			cin >> t[i] >> l[i] >> r[i];
		
		int tempL = l[0], tempR = r[0], ans = 1;
		for ( int i = 1; i <= N; i++ )
		{
			tempL -= (t[i] - t[i - 1]);
			tempR += (t[i] - t[i - 1]);
			if ( tempL <= tempR && !(tempR < l[i] || r[i] < tempL) )
				tempL = max ( tempL, l[i] ), tempR = min ( tempR, r[i] );
			else
				ans = 0;
		}
		
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}
