#include <iostream>
#include <cmath>
#include <bitset>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll N, Result = 1;
bitset <100000000> Primes;

ll Cribba ( ll n )
{
	Primes[0] = true;
	Primes[1] = true;

	for ( ll i = 4; i > 0 && i * i <= n; i += 2 )
		Primes[i] = true;

	for ( ll j = 4; j > 0 && j <= n; j *= 2)
	{
		Result *= 2;
		Result %= MOD;
	}

	for ( ll i = 3; i * i > 0 && i * i <= n + 1; i += 2 )
	{
		if ( !Primes[i] )
		{
			for ( ll j = i * i; j * j <= n; j += i )
			{
				if ( j >= sqrt(n) )
					break;
				Primes[j] = true;
			}
			for ( ll j = i * i; j <= n; j *= i )
			{
				Result *= i;
				Result %= MOD;

				if ( j >= 1e18/i )
					break;
			}
		}
	}

	return Result;
}

int main ()
{
	cin >> N;
	cout << Cribba ( N ) << "\n";
	return 0;
}
