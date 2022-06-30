/*
ID: josecaz1
PROG: concom
LANG: C++11
*/
#include <iostream>
#include <fstream>
#define MAXN 105

#define UPLOAD 1
#if UPLOAD
#define cin ccin
#define cout ccout
#endif

using namespace std;
typedef long long int lld;
ifstream ccin("concom.in");
ofstream ccout("concom.out");

int N, from, to, perc, matrix[MAXN][MAXN];
int visited[MAXN], control[MAXN];

void dfs ( int x )
{
	visited[x] = 1;

	for ( int i = 1; i <= 100; i++ )
		control[i] += matrix[x][i];
	
	for ( int i = 1; i <= 100; i++ )
		if ( control[i] >= 50 && !visited[i] && i != x )
			dfs ( i );
}

int main ()
{
	cin >> N;
	for ( int i = 0; i < N; i++ )
	{
		cin >> from >> to >> perc;
		matrix[from][to] = perc;
	}

	for ( int i = 1; i <= 100; i++ )
	{
		for ( int j = 1; j <= 100; j++ )
			control[j] = 0, visited[j] = 0;

		dfs ( i );

		for ( int j = 1; j <= 100; j++ )
			if ( control[j] >= 50 && i != j)
				cout << i << " " << j << "\n";
	}
	return 0;
}
