#include <iostream>
#define MAXN 105
#define MAXK 50
#define INF ( 1 << 30 )

using namespace std;
typedef long long int lld;

int N, a[MAXN], primes[MAXN], Bits[MAXK], cnt, mask[MAXK], DP[MAXN][(1<<13)];

void criba ( int x )
{
	primes[0] = 1;
	primes[1] = 1;
	for ( int i = 2; i <= x; i += 2 )
		primes[i] = 2;
	
	Bits[2] = (1 << (cnt++));
	
	for ( int i = 3; i <= x; i += 2 )
	{
		if ( !primes[i] )
		{
			Bits[i] = (1 << (cnt++));
			primes[i] = i;
			for ( int j = i * i; j <= x; j += i )
				primes[j] = i;
		}
	}

}

void precalc ( int x )
{
	int aux;
	mask[1] = 0;
	for ( int i = 2; i <= x; i++ )
	{
		aux = i;
		while ( aux > 1 )
		{
			mask[i] |= Bits[primes[aux]];
			aux /= primes[aux];
		}
	}
}

int dp ( int i, int m )
{
	if ( i == N )
		return DP[i][m] = 0;
	
	if ( DP[i][m] != -1 )
		return DP[i][m];
	
	DP[i][m] = INF;
	
	for ( int x = 1; x <= 40; x++ )
		if ( (m & mask[x]) == 0 )
			DP[i][m] = min ( DP[i][m], abs ( a[i] - x ) + dp ( i + 1, m | mask[x] ) );
	
	return DP[i][m];
}

void recurse ( int i, int m )
{
	if ( i == N )
		return;

	int minim = INF;
	for ( int x = 1; x <= 40; x++ )
		if ( (m & mask[x]) == 0 )
			minim = min ( minim, DP[i + 1][m | mask[x]] + abs ( a[i] - x ) );
	
	for ( int x = 1; x <= 40; x++ )
	{
		if ( (m & mask[x]) == 0 && DP[i + 1][m | mask[x]] + abs ( a[i] - x ) == minim )
		{
			cout << x << " ";
			recurse ( i + 1, m | mask[x] );
			break;
		}
	}
}

int main ()
{
	criba ( 40 );
	precalc ( 40 );

	while ( cin >> N )
	{
		if ( N == 0 )
			break;

		for ( int i = 0; i < N; i++ )
			for ( int j = 0; j < (1 << 13); j++ )
				DP[i][j] = -1;

		for ( int i = 0; i < N; i++ )
			cin >> a[i];

		dp ( 0, 0 );

		recurse ( 0, 0 );
		cout << "\n";
	}
	
	return 0;
}
