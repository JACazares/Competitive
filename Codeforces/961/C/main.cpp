#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int lld;

int N, board[4][105][105], a[4] = {0, 1, 2, 3}, ans, change0[4], change1[4];
char Board[4][105][105];

int board_config ( int A, int B, int C, int D )
{
	return min ( change1[A] + change0[B] + change0[C] + change1[D],
				 change0[A] + change1[B] + change1[C] + change0[D] );
}

int main ()
{
	cin >> N;
	for ( int k = 0; k < 4; k++ )
	{
		for ( int i = 0; i < N; i++ )
		{
			for ( int j = 0; j < N; j++ )
			{
				cin >> Board[k][i][j];
				board[k][i][j] = Board[k][i][j] - '0';
				if ( board[k][i][j] == 0 )
				{
					if ( i % 2 == j % 2 )
						change1[k]++;
					if ( i % 2 != j % 2 )
						change0[k]++;
				}
				if ( board[k][i][j] == 1 )
				{
					if ( i % 2 == j % 2 )
						change0[k]++;
					if ( i % 2 != j % 2 )
						change1[k]++;
				}
			}
		}
	}

	ans = board_config ( a[0], a[1], a[2], a[3] );
	next_permutation ( a, a + 4 );

	do
	{
		ans = min ( ans, board_config( a[0], a[1], a[2], a[3] ) );
	} while ( next_permutation(a, a + 4) );
	
	cout << ans << "\n";
	return 0;
}
