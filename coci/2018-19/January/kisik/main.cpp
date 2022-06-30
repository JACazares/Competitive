#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000005

using namespace std;
typedef long long ll;

ll N, K, w, h, sum, ans, aux;
vector < ll > a[MAX];
priority_queue < ll > PQ;

int main ()
{
	cin >> N >> K;
	for ( ll i = 0; i < N; i++ )
	{
		cin >> w >> h;
		a[h].push_back ( w );
	}

	ans = (1LL << 60LL);
	for ( ll i = 1; i <= 1000000; i++ )
	{
		for ( auto j : a[i] )
		{
			PQ.push ( j );
			sum += j;
			if ( PQ.size() == K )
			{
				aux = PQ.top();
				PQ.pop();

				ans = min ( ans, i * sum );
				sum -= aux;
			}
		}
	}

	cout << ans << "\n";
	return 0;
}
