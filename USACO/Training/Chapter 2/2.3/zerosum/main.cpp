/*
ID: josecaz1
PROG: zerosum
LANG: C++11
*/
#include <iostream>
#include <fstream>

#define UPLOAD 1

#if UPLOAD
#define cin fin
#define cout fout
#endif

using namespace std;
typedef long long int lld;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int N;

void recurse ( int a, string s)
{
	int aux = 0, lastterm = 0;
	char lastsign = '+';
	if ( a == N )
	{
		lastterm = 1;

		for ( int i = 0; i < s.length(); i++ )
		{
			if ( s[i] == '+' || s[i] == '-' )
			{
				if ( lastsign == '+' )
					aux += lastterm;
				else
					aux -= lastterm;
				lastterm = 0;
				lastsign = s[i];
			}
			else
				lastterm *= 10;

			lastterm += ( i + 2 );

		}
		if ( lastsign == '+' )
			aux += lastterm;
		else
			aux -= lastterm;

		if ( aux == 0 )
		{
			for ( int i = 0; i < s.length(); i++ )
				cout << i + 1 << s[i];
			cout << N << "\n";
		}
		return;
	}

	recurse ( a + 1, s + " " );
	recurse ( a + 1, s + "+" );
	recurse ( a + 1, s + "-" );
}

int main ()
{
	cin >> N;
	recurse ( 1, "" );
	return 0;
}
