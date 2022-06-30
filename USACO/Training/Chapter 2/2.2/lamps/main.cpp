/*
ID: josecaz1
PROG: lamps
LANG: C++11
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#define MAXN 105

#define UPLOAD 1

#if UPLOAD
#define cin fin
#define cout fout
#endif

using namespace std;
typedef long long int lld;
ifstream fin("lamps.in");
ofstream fout("lamps.out");

int N, C, lamp, finalLamps[MAXN], aux, lamps[MAXN], cnt;
string ans[(1 << 4)];

int opp ( int x ) {	return ( (x + 1) & 1 ); }

void reset()
{
	for ( int i = 0; i < N; i++ )
		lamps[i] = 1;
}

void button1()
{
	for ( int i = 0; i < N; i++ )
		lamps[i] = opp(lamps[i]);
}

void button2()
{
	for ( int i = 0; i < N; i += 2 )
		lamps[i] = opp(lamps[i]);
}

void button3()
{
	for ( int i = 1; i < N; i += 2 )
		lamps[i] = opp(lamps[i]);
}

void button4()
{
	for ( int i = 0; i < N; i += 3 )
		lamps[i] = opp(lamps[i]);
}

bool verify()
{
	for ( int i = 0; i < N; i++ )
	{
		if ( finalLamps[i] == 0 )
			continue;
		if ( finalLamps[i] == 1 && lamps[i] == 0 )
			return false;
		if ( finalLamps[i] == -1 && lamps[i] == 1 )
			return false;
	}
	return true;
}

bool verify( int x )
{
	int sum = 0;
	for ( int i = 0; i < 4; i++ )
		sum += ( (x & (1 << i) ) > 0 );
	
	if ( C >= sum && ((sum & 1) == (C & 1)) )
		return true;
	return false;
}

int main ()
{
	cin >> N;
	cin >> C;
	while ( cin >> lamp )
	{
		if ( lamp == -1 )
			break;
		finalLamps[lamp - 1] = 1;
	}
	while ( cin >> lamp )
	{
		if ( lamp == -1 )
			break;
		finalLamps[lamp - 1] = -1;
	}

	for ( int i = 0; i < ( 1 << 4 ); i++ )
	{
		if ( !verify(i) )
			continue;

		reset();

		if ( i & (1 << 0) )	button1();
		if ( i & (1 << 1) )	button2();
		if ( i & (1 << 2) )	button3();
		if ( i & (1 << 3) )	button4();

		if ( verify() )
		{
			for ( int k = 0; k < N; k++ )
				ans[cnt] += (char)(lamps[k] + '0');
			cnt++;
		}
	}
	sort ( ans, ans + cnt );

	if ( cnt == 0)
		cout << "IMPOSSIBLE\n";
	else
	{
		cout << ans[0] << "\n";
		for ( int i = 1; i < cnt; i++ )
			if ( ans[i] != ans[i - 1] )
				cout << ans[i] << "\n";
	}
	
