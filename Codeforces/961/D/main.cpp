#include <iostream>
#include <algorithm>
#define MAXN 100005

using namespace std;
typedef long long int lld;
struct point
{
	lld x, y;
	point operator-(const point &p) const
    {
        return {x-p.x, y-p.y};
    }
    bool operator<(const point &p) const
    {
		if(x!=p.x)
            return x<p.x;
        return y<p.y;
    }
};

lld N, hullSize;
point pnt[MAXN], convexhull[MAXN], unused[MAXN];

lld cross ( point a, point b )
{
	return a.x * b.y - a.y * b.x;
}

void convexHull ( int s, int e, int inc, point hull[] )
{
	for ( int i = s; i != e; i += inc)
    {
        while(hullSize >= 2 && cross ( hull[hullSize - 1] - hull[hullSize], pnt[i] - hull[hullSize] ) <= 0)
            hullSize--;
        hull[++hullSize] = pnt[i];
    }
}

bool allColineal3()
{
	int aux, unusedTam;
	int pnt1, pnt2, pnt3, pnt4;

	unusedTam = 0;
	aux = 0;
	pnt1 = 1, pnt2 = 2;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else
			unused[unusedTam++] = pnt[i];
	}

	pnt1 = 0, pnt2 = 1;
	for ( int i = 0; i < unusedTam; i++ )
		if ( cross ( unused[pnt1] - unused[pnt2], unused[i] - unused[pnt2] ) == 0)
			aux++;
	
	if ( aux == N )
		return true;

	unusedTam = 0;
	aux = 0;
	pnt1 = 1, pnt2 = 3;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else
			unused[unusedTam++] = pnt[i];
	}

	pnt1 = 0, pnt2 = 1;
	for ( int i = 0; i < unusedTam; i++ )
		if ( cross ( unused[pnt1] - unused[pnt2], unused[i] - unused[pnt2] ) == 0)
			aux++;
	
	if ( aux == N )
		return true;

	unusedTam = 0;
	aux = 0;
	pnt1 = 2, pnt2 = 3;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else
			unused[unusedTam++] = pnt[i];
	}

	pnt1 = 0, pnt2 = 1;
	for ( int i = 0; i < unusedTam; i++ )
		if ( cross ( unused[pnt1] - unused[pnt2], unused[i] - unused[pnt2] ) == 0)
			aux++;
	
	if ( aux == N )
		return true;


	aux = 0;
	pnt1 = 1, pnt2 = 2, pnt3 = 1, pnt4 = 3;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else if ( cross ( convexhull[pnt3] - convexhull[pnt4], pnt[i] - convexhull[pnt4] ) == 0 )
			aux++;
	}
	if ( aux == N )
		return true;
	aux = 0;
	pnt1 = 2, pnt2 = 1, pnt3 = 2, pnt4 = 3;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else if ( cross ( convexhull[pnt3] - convexhull[pnt4], pnt[i] - convexhull[pnt4] ) == 0 )
			aux++;
	}
	if ( aux == N )
		return true;
	aux = 0;
	pnt1 = 3, pnt2 = 1, pnt3 = 3, pnt4 = 2;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else if ( cross ( convexhull[pnt3] - convexhull[pnt4], pnt[i] - convexhull[pnt4] ) == 0 )
			aux++;
	}
	if ( aux == N )
		return true;
	return false;
}

bool allColineal4()
{
	int aux;
	int pnt1, pnt2, pnt3, pnt4;
	aux = 0;
	pnt1 = 1, pnt2 = 2, pnt3 = 3, pnt4 = 4;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else if ( cross ( convexhull[pnt3] - convexhull[pnt4], pnt[i] - convexhull[pnt4] ) == 0 )
			aux++;
	}
	if ( aux == N )
		return true;
	aux = 0;
	pnt1 = 1, pnt2 = 3, pnt3 = 2, pnt4 = 4;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else if ( cross ( convexhull[pnt3] - convexhull[pnt4], pnt[i] - convexhull[pnt4] ) == 0 )
			aux++;
	}
	if ( aux == N )
		return true;
	aux = 0;
	pnt1 = 1, pnt2 = 4, pnt3 = 2, pnt4 = 3;
	for ( int i = 1; i <= N; i++ )
	{
		if ( cross ( convexhull[pnt1] - convexhull[pnt2], pnt[i] - convexhull[pnt2] ) == 0)
			aux++;
		else if ( cross ( convexhull[pnt3] - convexhull[pnt4], pnt[i] - convexhull[pnt4] ) == 0 )
			aux++;
	}
	if ( aux == N )
		return true;
	return false;
}

int main ()
{
	cin >> N;
	for ( lld i = 1; i <= N; i++ )
		cin >> pnt[i].x >> pnt[i].y;
	
	sort ( pnt + 1, pnt + N + 1 );
	convexHull( 1, N, 1, convexhull );
	convexHull( N, 0, -1, convexhull );
	hullSize--;

	if ( hullSize == 1 || hullSize == 0 )
	{
		cout << "YES\n";
	}
	else if ( hullSize == 3 )
	{
		if ( allColineal3() )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else if ( hullSize == 4 )
	{
		if ( allColineal4() )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else
	{
		cout << "NO\n";
	}

	return 0;
}
