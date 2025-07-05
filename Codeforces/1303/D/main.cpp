#include <iostream>
#include <algorithm>
#include <map>
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
		ll N;
		int M;
		cin >> N >> M;
		int a, ans = 0;
		ll sum = 0;
		map < ll, int > MP;
		for ( int i = 0; i < M; i++ )
		{
			cin >> a;
			sum += a;
			MP[a]++;
		}
		if ( sum < N )
		{
			cout << "-1\n";
			continue;
		}
		for ( ll i = 0; i <= 50; i++ )
		{
			if ( N & (1LL << i) )
			{
				if ( MP[(1LL << i)] )
					MP[(1LL << i)]--;
				else
				{
					MP[(1LL << i)]++;
					for ( ll j = i + 1; j <= 50; j++ )
					{
						if ( MP[(1LL << j)] )
						{
							ans++;
							MP[(1LL << j)]--;
							break;
						}
						ans++;
						MP[(1LL << j)]++;
					}
				}
			}
			if ( i < 50 )
				MP[(1LL << (i + 1))] += (MP[(1LL << i)] / 2);
		}
		cout << ans << "\n";
	}
	return 0;
}
