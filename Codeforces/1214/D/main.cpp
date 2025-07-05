#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1000005;

int N, M;
string S[MAXN];

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M;
	for ( int i = 0; i < N; i++ )
		cin >> S[i];
	
	int a[N + 1][M + 1];
	for ( int i = N; i >= 0; i-- )
		for ( int j = M; j >= 0; j-- )
			a[i][j] = 0;

	a[N - 1][M] = 1, a[N][M - 1] = 1;
	for ( int i = N - 1; i >= 0; i-- )
		for ( int j = M - 1; j >= 0; j-- )
			if ( S[i][j] == '.' )
				a[i][j] = max ( a[i + 1][j], a[i][j + 1] );
	
	if ( !a[0][0] )
	{
		cout << "0\n";
		return 0;
	}
	
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	while ( x1 != N - 1 || y1 != M - 1 )
	{
		if ( a[x1][y1 + 1] == 1 )
			y1++;
		else
			x1++;
		
		if ( a[x2 + 1][y2] == 1 )
			x2++;
		else
			y2++;
		
		if ( x1 == N - 1 && y1 == M - 1 )
			break;
		
		if ( x1 == x2 && y1 == y2 )
		{
			cout << "1\n";
			return 0;
		}
	}
	
	cout << "2\n";
	return 0;
}
