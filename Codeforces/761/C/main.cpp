#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = (1 << 29);

int main ()
{
	int N, M;
	cin >> N >> M;
	string S[N];
	for ( int i = 0; i < N; i++ )
		cin >> S[i];
	
	int a1 = INF, a2 = INF, a3 = INF, ans = INF;
	for ( int i = 0; i < N; i++ )
	{
		a1 = INF;
		for ( int l = 0; l < M; l++ )
			if ( '0' <= S[i][l] && S[i][l] <= '9' )
				a1 = min ( a1, min ( l, M - l ) );

		for ( int j = 0; j < N; j++ )
		{
			if ( i == j ) continue;
			a2 = INF;
			for ( int l = 0; l < M; l++ )
				if ( 'a' <= S[j][l] && S[j][l] <= 'z' )
					a2 = min ( a2, min ( l, M - l ) );

			for ( int k = 0; k < N; k++ )
			{
				if ( i == k || j == k ) continue;
				a3 = INF;
				for ( int l = 0; l < M; l++ )
					if ( S[k][l] == '#' || S[k][l] == '*' || S[k][l] == '&' )
						a3 = min ( a3, min ( l, M - l ) );
				
				ans = min ( ans, a1 + a2 + a3 );
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
