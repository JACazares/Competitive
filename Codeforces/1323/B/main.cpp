#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cnt;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N, M, K;
	cin >> N >> M >> K;
	vi a(N), b(M), onesA, onesB;
	cnt = 0;
	for ( int i = 0; i < N; i++ )
	{
		cin >> a[i];
		if ( a[i] == 1 )
			cnt++;
		else
		{
			onesA.push_back ( cnt );
			cnt = 0;
		}
	}
	onesA.push_back ( cnt );
	cnt = 0;
	for ( int i = 0; i < M; i++ )
	{
		cin >> b[i];
		if ( b[i] == 1 )
			cnt++;
		else
		{
			onesB.push_back ( cnt );
			cnt = 0;
		}
	}
	onesB.push_back ( cnt );
	cnt = 0;
	
	ll ans = 0;
	for ( int k = 1; k * k <= K; k++ )
	{
		if ( K % k == 0 )
		{
			ll ansA = 0, ansB = 0;
			for ( auto i : onesA )
				ansA += max ( i - k + 1, 0 );
			for ( auto i : onesB )
				ansB += max ( i - K/k + 1, 0 );
			ans += (ansA * ansB);
			
			if ( k != K / k )
			{
				ansA = 0, ansB = 0;
				for ( auto i : onesA )
					ansA += max ( i - K/k + 1, 0 );
				for ( auto i : onesB )
					ansB += max ( i - k + 1, 0 );
				ans += (ansA * ansB);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
