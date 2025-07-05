#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a1, a2, k1, k2, n, lim;
int minim, maxim;

int main ()
{
	cin >> a1 >> a2;
	cin >> k1 >> k2;
	cin >> n;
	
	lim = a1 * (k1 - 1) + a2 * (k2 - 1);
	minim = max ( 0, n - lim );
	
	if ( k1 < k2 )
	{
		maxim = min ( a1, n / k1 );
		if ( k1 * a1 < n )
		{
			n -= (k1 * a1);
			maxim += min ( a2, n / k2 );
		}
	}
	else
	{
		maxim = min ( a2, n / k2 );
		if ( k2 * a2 < n )
		{
			n -= (k2 * a2);
			maxim += min ( a1, n / k1 );
		}
	}

	cout << minim << " " << maxim << "\n";
	return 0;
}
