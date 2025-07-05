#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const int MAXN = 1e5 + 5;
int T, a, b, p;
ll cost[MAXN];

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> T;
	while ( T-- )
	{
		string S;
		cin >> a >> b >> p;
		cin >> S;
		cost[S.length() - 1] = 0;
		cost[S.length() - 2] = (S[S.length() - 2] == 'A' ? a : b);
		for ( int i = S.length() - 3; i >= 0; i-- )
		{
			cost[i] = cost[i + 1];
			if ( S[i] != S[i + 1] )
				cost[i] += (S[i] == 'A' ? a : b);
		}
		
		for ( int i = 0; i < S.length(); i++ )
			if ( cost[i] <= p )
			{
				cout << i + 1 << "\n";
				break;
			}
	}
	return 0;
}
