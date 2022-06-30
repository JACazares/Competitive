#include <iostream>
#include <deque>
#define MAXN 1000005

using namespace std;
typedef long long ll;

int N, L, R, a[MAXN], s, e, mid, val, ans;
deque < int > Q;

bool solve ( int x )
{
	if ( x == -1 )
		return 1;

	int b[MAXN], l, DP[MAXN];
	for ( int i = 1; i <= N; i++ )
		b[i] = (a[i] >= x);
	
	Q.clear();
	l = (1 << 30);
	DP[N + 1] = 1;
	Q.push_back ( N + 1 );
	for ( int i = N; i >= 1; i-- )
	{
		if ( b[i] == 1 )
			l = i;

		while ( !Q.empty() && Q.front() > i + R )
			Q.pop_front();

		DP[i] = 0;
		if ( !Q.empty() && Q.front() > l && Q.front() >= i + L )
		{
			DP[i] = 1;
			Q.push_back ( i );
		}
	}

	return DP[1];
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> L >> R;
	for ( int i = 1; i <= N; i++ )
		cin >> a[i];
	
	s = -1, e = 1000000000;
	while ( s <= e )
	{
		mid = (s + e) / 2;
		val = solve ( mid );

		if ( val )
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	cout << ans << "\n";
	return 0;
}
