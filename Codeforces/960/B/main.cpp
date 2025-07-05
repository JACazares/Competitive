#include <iostream>
#include <queue>
#define MAXN 1005

using namespace std;
typedef long long int lld;

lld N, k1, k2, a[MAXN], b[MAXN], c, x;
lld ans;
priority_queue<lld> pq;

int main ()
{
	cin >> N >> k1 >> k2;
	for ( lld i = 0; i < N; i++ )
		cin >> a[i];
	for ( lld i = 0; i < N; i++ )
		cin >> b[i];
	for ( lld i = 0; i < N; i++ )
	{
		c = abs(a[i] - b[i]);
		pq.push ( c );
	}

	for ( lld i = 0; i < k1 + k2; i++ )
	{
		x = pq.top();
		pq.pop();
		if ( x > 0 )
			x--;
		else
			x++;
		pq.push(x);
	}

	while ( !pq.empty() )
	{
		x = pq.top();
		pq.pop();
		ans += (x * x);
	}

	cout << ans << "\n";
	
	return 0;
}
