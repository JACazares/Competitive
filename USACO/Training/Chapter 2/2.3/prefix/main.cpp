/*
ID: josecaz1
PROG: prefix
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#define MAXN 205
#define MAXS 200005

#define UPLOAD 1

#if UPLOAD
#define cin fin
#define cout fout
#endif

using namespace std;
typedef long long int lld;
ifstream fin("prefix.in");
ofstream fout("prefix.out");

int N, ans, DP[MAXS];
char aux;
string primitive, S, auxS;
map < string, bool> primitives;

int main ()
{
	for ( int i = 0; cin >> primitive; i++ )
	{
		if ( primitive == "." )
			break;
		primitives[primitive] = 1;
	}

	while ( cin >> aux )
	{
		if ( 'A' <= aux && aux <= 'Z' )
			S+= aux;
	}


	N = S.length();
	for ( int i = 0; i < N; i++ )
	{
		auxS = "";
		for ( int j = i; j >= 0 && j >= i - 20; j-- )
		{
			if ( DP[j] && primitives[auxS] )
			{
				ans = max ( ans, i + 1 );
				DP[i] = 1;
				break;;
			}
			auxS = S[j] + auxS;
		}

		if ( primitives[auxS] )
		{
			ans = max ( ans, i + 1 );
			DP[i] = 1;
		}
	}

	cout << ans << "\n";
	
	return 0;
}
