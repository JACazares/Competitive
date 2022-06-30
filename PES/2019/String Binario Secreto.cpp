#include "stringSecreto.h"
#include <iostream>
#define MAXN 1005

// Main
//	int pregunta(int n, char s[])
//	int respuesta(int cero, int uno)

using namespace std;

char S[MAXN], aux[MAXN];
int N, s, e, mid, val, ones, zeros, uno, cero, f, bc, bu;

int solve ( int l, int x )
{
	for ( int i = 0; i < N; i++ )
		aux[i] = '0';
	for ( int i = l; i <= x; i++ )
		aux[i] = '1';
	
	zeros = pregunta ( N, aux );

	if ( ((x - l + 1) - zeros + ones) / 2 == (x - l + 1) )
		return 2;
	
	if ( ((x - l + 1) - zeros + ones) / 2 > 0 )
		return 1;
	return 0;
}

int solve2 ( int l, int x )
{
	for ( int i = 0; i < N; i++ )
		aux[i] = '0';
	for ( int i = l; i <= x; i++ )
		aux[i] = '1';
	
	zeros = pregunta ( N, aux );
	
	if ( (zeros - ones + (x - l + 1)) / 2 == (x - l + 1) )
		return 2;

	if ( (zeros - ones + (x - l + 1)) / 2 > 0 )
		return 1;
	return 0;
}

void adivina ( int n )
{
	N = n;
	for ( int i = 0; i < N; i++ )
		S[i] = '0';
	
	ones = pregunta ( n, S );

	s = 0, e = n - 1, f = 1;
	while ( s < e )
	{
		mid = (s + e) / 2;

		if ( f == 1 )
			val = solve ( s, mid );
		else
			val = solve2 ( s, mid );

		if ( val == 2 )
		{
			if ( f == 1 )
			{
				f = 0;
				if ( !bu )
					uno = s;
				bu = 1;
				s = mid + 1;
			}
			else
			{
				if ( !bc )
					cero = s;
				bc = 1;
				s = mid + 1;
			}
		}
		else if ( val == 0 )
		{
			if ( f == 1 )
			{
				if ( !bc )
					cero = s;
				bc = 1;
			}
			else
			{
				if ( !bu )
					uno = s;
				bu = 1;
			}
			s = mid + 1;
		}
		else if ( val == 1 )
			e = mid;
	}
	if ( f == 1 && !bu)
		uno = s;
	if ( f == 0 && !bc)
		cero = s;
	
	//cout << cero << " " << uno << "\n";

	respuesta ( cero, uno );
}
