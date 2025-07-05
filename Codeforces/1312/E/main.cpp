#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 505;
int N, a[MAXN], converge[MAXN][MAXN], DP[MAXN];
stack < int > S;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	
	for ( int i = 0; i < N; i++ )
	{
		for ( int j = i; j < N; j++ )
		{
			S.push ( a[j] );
			while ( S.size() >= 2 )
			{
				int fst = S.top();
				S.pop();
				int snd = S.top();
				S.pop();
				if ( fst == snd )
					S.push ( fst + 1 );
				else
				{
					S.push ( snd );
					S.push ( fst );
					break;
				}
			}
			if ( S.size() == 1 )
				converge[i][j] = 1;
		}
		while ( !S.empty() )
			S.pop();
	}
	
	DP[N] = 0;
	for ( int i = N - 1; i >= 0; i-- )
	{
		DP[i] = DP[i + 1] + 1;
		for ( int j = i + 1; j <= N; j++ )
			if ( converge[i][j - 1] )
				DP[i] = min ( DP[i], DP[j] + 1 );
	}
	cout << DP[0] << "\n";
	return 0;
}
