#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXN = 200005;

ll T, N, pipe, pillar, DP[MAXN][2], a1, a2;
string S;

int main ()
{
	cin >> T;
	while ( T-- )
	{
		cin >> N >> pipe >> pillar;
		cin >> S;
		
		S = S + " ";
		DP[N][0] = pillar, DP[N][1] = (1LL << 60LL);
		for ( ll i = N - 1; i >= 0; i-- )
		{
			if ( S[i] == '1' )
				DP[i][0] = (1LL << 60LL);
			else
			{
				a1 = DP[i + 1][0] + pillar + pipe;
				a2 = DP[i + 1][1] + pillar + 2*pipe;
				if ( S[i + 1] == '1' )
					DP[i][0] = a2;
				else
					DP[i][0] = min ( a1, a2 );
			}

			a1 = DP[i + 1][1] + 2*pillar + pipe;
			a2 = DP[i + 1][0] + 2*pillar + 2*pipe;
			if ( S[i] == '1' || S[i + 1] == '1' )
				DP[i][1] = a1;
			else
				DP[i][1] = min ( a1, a2 );
		}
		
		cout << DP[0][0] << "\n";
	}
	return 0;
}
