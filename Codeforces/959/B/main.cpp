#include <iostream>
#include <map>
#define MAXN 100005
using namespace std;
typedef long long int lld;

lld N, K, M, c, group, numgroup, costgroup[MAXN];
lld ans;
string word[MAXN], w;
map<string, lld> groups, cost;

int main ()
{
	cin >> N >> K >> M;
	for ( lld i = 0; i < N; i++ )
		cin >> word[i];
	for ( lld i = 0; i < N; i++ )
		cin >> c, cost[word[i]] = c;

	for ( lld i = 0; i < K; i++ )
	{
		cin >> numgroup;
		for ( lld j = 0; j < numgroup; j++ )
		{
			cin >> group;
			group--;
			costgroup[i] = min ( costgroup[i], cost[word[group]] );
			if ( j == 0 )
				costgroup[i] = cost[word[group]];
			groups[word[group]] = i;
		}
	}

	for ( lld i = 0; i < M; i++ )
	{
		cin >> w;
		ans += costgroup[groups[w]];
	}

	cout << ans << "\n";
	return 0;
}
