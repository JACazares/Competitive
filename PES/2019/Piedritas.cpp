#include <iostream>
#define MAXN 1000

using namespace std;
typedef long long ll;

ll N, fib[MAXN];

ll f ( ll x )
{
	if ( x < -10 )
		return -1;
	if ( x == 1 )
		return 1;

	ll i = 0;
	for ( i = 1; true; i++ )
		if ( fib[i] > x )
			break;
		
	if ( x == fib[i - 1] )
		return x;
	
	return f ( x - fib[i - 1] );
}

int main ()
{
	cin >> N;

	fib[0] = 1;
	fib[1] = 1;
	for ( int i = 2; fib[i - 1] <= N; i++ )
		fib[i] = fib[i - 1] + fib[i - 2];

	cout << f ( N );
	return 0;
}
