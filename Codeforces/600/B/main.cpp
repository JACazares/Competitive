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
	int N, M;
	cin >> N >> M;
	int a[N];
	pii b[M];
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	for ( int i = 0; i < M; i++ )
	{
		cin >> b[i].first;
		b[i].second = i;
	}
	sort ( a, a + N );
	sort ( b, b + M );
	
	int lpnt = 0, ans[M];
	for ( int i = 0; i < M; i++ )
	{
		for ( ; lpnt < N; lpnt++ )
			if ( a[lpnt] > b[i].first )
				break;
		
		ans[b[i].second] = lpnt;
	}
	for ( int i = 0; i < M; i++ )
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
