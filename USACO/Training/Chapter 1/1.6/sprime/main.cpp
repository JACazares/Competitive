/*
ID: josecaz1
PROG: sprime
LANG: C++11
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
typedef long long int lld;
vector <int> primeRib;
int startIndex;
int endIndex;

bool isPrime (int p)
{
	if ( p % 2 == 0 || p < 1 ) return false;

	int len = sqrt (p * 1.0);

	for ( int i = 3; i <= len; i += 2 ) if ( p % i == 0 ) return false;
	return true;
}

void oneDigit ()
{
	primeRib.push_back (2);
	primeRib.push_back (3);
	primeRib.push_back (5);
	primeRib.push_back (7);

	startIndex = 0;
	endIndex = primeRib.size ();
}

void twoDigit ()
{
	for ( int i = startIndex; i < endIndex; i++ ) {
		for ( int j = 1; j <= 9; j += 2 ) {
			int num = primeRib [i] * 10 + j;
			if ( isPrime (num) ) primeRib.push_back (num);
		}
	}

	startIndex = endIndex;
	endIndex = primeRib.size ();

}

void threeDigit ()
{
	for ( int i = startIndex; i < endIndex; i++ ) {
		for ( int j = 1; j <= 9; j += 2 ) {
			int num = primeRib [i] * 10 + j;
			if ( isPrime (num) ) primeRib.push_back (num);
		}
	}

	startIndex = endIndex;
	endIndex = primeRib.size ();
}

void fourDigit ()
{
	for ( int i = startIndex; i < endIndex; i++ ) {
		for ( int j = 1; j <= 9; j += 2 ) {
			int num = primeRib [i] * 10 + j;
			if ( isPrime (num) ) primeRib.push_back (num);
		}
	}

	startIndex = endIndex;
	endIndex = primeRib.size ();
}

void fiveDigit ()
{
	for ( int i = startIndex; i < endIndex; i++ ) {
		for ( int j = 1; j <= 9; j += 2 ) {
			int num = primeRib [i] * 10 + j;
			if ( isPrime (num) ) primeRib.push_back (num);
		}
	}

	startIndex = endIndex;
	endIndex = primeRib.size ();
}

void sixDigit ()
{
	for ( int i = startIndex; i < endIndex; i++ ) {
		for ( int j = 1; j <= 9; j += 2 ) {
			int num = primeRib [i] * 10 + j;
			if ( isPrime (num) ) primeRib.push_back (num);
		}
	}

	startIndex = endIndex;
	endIndex = primeRib.size ();
}

void sevenDigit ()
{
	for ( int i = startIndex; i < endIndex; i++ ) {
		for ( int j = 1; j <= 9; j += 2 ) {
			int num = primeRib [i] * 10 + j;
			if ( isPrime (num) ) primeRib.push_back (num);
		}
	}

	startIndex = endIndex;
	endIndex = primeRib.size ();
}

void eightDigit ()
{
	for ( int i = startIndex; i < endIndex; i++ ) {
		for ( int j = 1; j <= 9; j += 2 ) {
			int num = primeRib [i] * 10 + j;
			if ( isPrime (num) ) primeRib.push_back (num);
		}
	}

	startIndex = endIndex;
	endIndex = primeRib.size ();
}

void generatePrimeRib ()
{
	oneDigit ();
	twoDigit ();
	threeDigit ();
	fourDigit ();
	fiveDigit ();
	sixDigit ();
	sevenDigit ();
	eightDigit ();
}

int power (int b, int p)
{
	int ret = 1;

	for ( int i = 1; i <= p; i++ ) 
		ret *= b;

	return ret;
}

int main ()
{
	generatePrimeRib ();

	freopen ("sprime.in", "r", stdin);
	freopen ("sprime.out", "w", stdout);
	//printf ("%d\n", primeRib.size ());

	int digit;
	scanf ("%d", &digit);
	
	for ( size_t i = 0; i < primeRib.size (); i++ ) {
		if ( primeRib [i] >= power (10, digit - 1) && primeRib [i] <= power (10, digit) ) { printf ("%d\n", primeRib [i]); }
	}
	
	return 0;
}
