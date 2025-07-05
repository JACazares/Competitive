#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	vector < vector < pii > > Graph ( N + 5 );
	for ( int i = 0; i < N - 1; i++ )
	{
		int u, v;
		cin >> u >> v;
		Graph[u].push_back ( {v, i} );
		Graph[v].push_back ( {u, i} );
	}
	
	if ( N == 2 )
	{
		cout << "0\n";
		return 0;
	}
	
	int leafs = 0, theleaf = 0;
	for ( int i = 1; i <= N; i++ )
		if ( Graph[i].size() == 1 )
			leafs++, theleaf = i;
	
	if ( leafs == 2 )
	{
		for ( int i = 0; i < N - 1; i++ )
			cout << i << "\n";
		return 0;
	}
	
	int node = theleaf, parent = 0, delta = 1;
	vi check ( N + 5 );
	check[node] = 1;
	while ( delta )
	{
		delta = 0;
		for ( auto i : Graph[node] )
		{
			if ( i.first != parent )
			{
				parent = node;
				node = i.first;
				check[node] = 3;
				delta = 1;
				break;
			}
		}
	}
	check[node] = 2;

	int two = 0;
	vi ans ( N );
	for ( int i = 1; i <= N; i++ )
	{
		if ( check[i] == 2 )
			ans[Graph[i][0].second] = -1;
		else if ( check[i] == 1 )
			ans[Graph[i][0].second] = 1;
		else if ( check[i] == 0 )
		{
			if ( !two )
				ans[Graph[i][0].second] = 2;
			two = 1;
		}
	}
	
	int cnt = 3;
	for ( int i = 0; i < N - 1; i++ )
	{
		if ( ans[i] == -1 )
			ans[i] = 0;
		else if ( ans[i] == 0 )
			ans[i] = cnt++;
		cout << ans[i] << "\n";
	}
	return 0;
}
