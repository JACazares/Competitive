#include <iostream>
#define MAXN 3005
#define INF (1LL << 60LL)

using namespace std;
typedef long long ll;

int N, K, vis[MAXN][MAXN], s, e, mid, aux;
double val;
double DP[MAXN][MAXN];

double solve ( int n, int k, int x )
{
	double b = ((x + 1) / (double)n) + DP[n - x - 1][k - 1];
	double a = (x / (double)n) + DP[n - x][k - 1];
	return b - a;
}

int main ()
{
	cin >> N >> K;
	cout.setf ( ios::fixed );
	cout.precision ( 9 );
	
	for ( int k = 0; k <= K; k++ )
	{
		for ( int n = 0; n <= N; n++ )
		{
			if ( n == 0 && k == 0 )
				DP[n][k] = 0;
			else if ( n == 0 or k == 0 )
				DP[n][k] = -INF;
			else
			{
				if ( k == 1 or n == 1 )
				{
					for ( int i = 1; i <= n; i++ )
						DP[n][k] = max ( DP[n][k], i / (double)n + DP[n - i][k - 1] );
				}
				else
				{
					s = 1, e = n - 1;
					while ( s <= e )
					{
						mid = (s + e) / 2;
						val = solve ( n, k, mid );

						if ( val >= 0 )
							s = mid + 1;
						if ( val <= 0 )
						{
							aux = mid;
							e = mid - 1;
						}
					}
					DP[n][k] = aux / (double)n + DP[n - aux][k - 1];
				}
			}
		}
	}
	
	cout << DP[N][K] << "\n";
	return 0;
}
