/*
ID: josecaz1
PROG: runround
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
typedef long long int lld;
ifstream fin("runround.in");
ofstream fout("runround.out");

lld M;

bool runround( lld x )
{
	int number[15], len = 0, ind, x2 = x;
	bool visited[15] = {0}, bucket[15] = {0};

	bucket[0] = 1;

	while ( x2 > 0 )
	{
		if ( bucket[x2 % 10] == 1 )
			return false;

		bucket[x2 % 10] = 1;

		x2 /= 10;
		len++;
	}

	for ( int i = len - 1; x > 0; i-- )
	{
		number[i] = x % 10;
		x /= 10;
	}

	ind = 0;
	for ( int i = 0; i < len; i++ )
	{
		ind = ( ind + number[ind]) % len;
		if ( visited[ind] == 1 )
			break;
		visited[ind] = 1;
	}


	for ( int i = 0; i < len; i++ )
		if ( visited[i] == 0)
			return false;

	return true;
}

int main ()
{
	fin >> M;
	for ( lld i = M + 1; true; i++ )
	{
		if ( runround( i ) )
		{
			fout << i << "\n";
			break;
		}
	}
	return 0;
}
