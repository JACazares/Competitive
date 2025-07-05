#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N, M;
	cin >> N >> M;
	ll x;
	unordered_map < ll, bool > vis, tree;
	queue < pll > Q;
	for ( int i = 0; i < N; i++ )
	{
		cin >> x;
		tree[x] = 1;
		vis[x] = 1;
		if ( !vis[x + 1] )
			Q.push ( {x + 1, 1} ), vis[x + 1] = 1;
		if ( !vis[x - 1] )
			Q.push ( {x - 1, 1} ), vis[x - 1] = 1;
	}
	
	ll cnt = 0, dist = 0;
	vi ans;
	while ( !Q.empty() )
	{
		auto aux = Q.front();
		Q.pop();
		
		if ( tree[aux.first] )
			continue;

		ans.push_back ( aux.first ), dist += aux.second;
		cnt++;
		if ( cnt == M )
			break;
		
		if ( !vis[aux.first + 1] )
			Q.push ( {aux.first + 1, aux.second + 1} ), vis[aux.first + 1] = 1;
		if ( !vis[aux.first - 1] )
			Q.push ( {aux.first - 1, aux.second + 1} ), vis[aux.first - 1] = 1;
	}
	
	cout << dist << "\n";
	for ( auto i : ans )
		cout << i << " ";
	cout << "\n";
	return 0;
}
