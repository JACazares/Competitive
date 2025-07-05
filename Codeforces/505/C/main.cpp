#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int maxim;
vi island;
map < pii, int > DP, vis;

ll dp ( int i, int l )
{
	if ( l < 1 )
		return 0;
	if ( i > maxim )
		return 0;
	if ( vis[{i, l}] )
		return DP[{i, l}];
	vis[{i, l}] = 1;
	return DP[{i, l}] = max ( dp(i+l+1, l+1), max ( dp(i+l, l), dp(i+l-1, l-1) ) ) + island[i];
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N, D;
	cin >> N >> D;
	int x;
	island.resize ( 300005 );
	for ( int i = 0; i < N; i++ )
		cin >> x, island[x]++, maxim = max ( maxim, x );
	cout << dp ( D, D ) << "\n";
	return 0;
}
