#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 200005;

struct Trap
{
	int l, r, d;
};

int M, N, K, T, a[MAXN];
Trap trap[MAXN];

bool solve ( int x )
{
	int traps[N +  5];
	for ( int i = 0; i <= N; i++ )
		traps[i] = 0;

	for ( int i = 0; i < K; i++ )
		if ( trap[i].d > x )
			traps[trap[i].l]++, traps[trap[i].r + 1]--;

	int aux = 0, cnt = 0;
	for ( int i = 1; i <= N; i++ )
	{
		traps[i] += traps[i - 1];
		if ( traps[i] >= 1 )
			cnt++;
		else
		{
			aux += 2 * cnt;
			cnt = 0;
		}
	}
	aux += 2 * cnt;
	cnt = 0;
	
	//cout << x << " " << aux + N + 1 << "\n";
	return min ( 3 * N + 1, aux + N + 1 ) <= T;
}

int main ()
{
	cin >> M >> N >> K >> T;
	for ( int i = 0; i < M; i++ )
		cin >> a[i];
	sort ( a, a + M, greater < int > () );

	for ( int i = 0; i < K; i++ )
		cin >> trap[i].l >> trap[i].r >> trap[i].d;

	int s = 0, e = M - 1, mid, val, ans = 0;
	while ( s <= e )
	{
		mid = (s + e) / 2;
		val = solve ( a[mid] );
		
		if ( val )
		{
			ans = mid + 1;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	
	cout << ans << "\n";
	return 0;
}
