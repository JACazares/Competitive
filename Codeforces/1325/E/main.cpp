#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e6 + 5;
int N;
vi a, vis, dist, par;
vector < vi > Graph ( MAX );

int find_cycle ( int node )
{
	vis.clear();
	dist.clear();
	par.clear();
	vis.resize ( MAX );
	dist.resize ( MAX );
	par.resize ( MAX );

	vi Q;
	int nxt, parent, minim = (1 << 30);
	Q.push_back ( node );
	vis[node] = 1;
	dist[node] = 0;
	par[node] = -1;
	for ( int i = 0; i < Q.size(); i++ )
	{
		nxt = Q[i];
		parent = 0;
		for ( auto j : Graph[nxt] )
		{
			if ( !vis[j] )
			{
				Q.push_back ( j );
				dist[j] = dist[nxt] + 1;
				vis[j] = 1;
				par[j] = nxt;
			}
			else
			{
				if ( par[nxt] == j && !parent )
					parent = 1;
				else
					minim = min ( minim, dist[j] + dist[nxt] + 1 );
			}
		}
	}
	return minim;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	a.resize ( N );
	for ( int i = 0; i < N; i++ )
	{
		cin >> a[i];
		int freq = 0;
		vi primes;
		for ( int j = 2; j*j <= a[i]; j++ )
		{
			freq = 0;
			while ( a[i] % j == 0 )
				freq++, a[i] /= j;
			if ( freq % 2 == 1 )
				primes.push_back ( j );
		}
		while ( primes.size() < 2 )
		{
			primes.push_back ( a[i] );
			a[i] = 1;
		}
		
		Graph[primes[0]].push_back ( primes[1] );
		Graph[primes[1]].push_back ( primes[0] );
	}
	
	int ans = (1 << 30);
	for ( int i = 1; i <= 1000; i++ )
		ans = min ( ans, find_cycle(i) );
	cout << (ans != (1 << 30) ? ans : -1) << "\n";
	return 0;
}
