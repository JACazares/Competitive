#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 4e5 + 5;
int tot[30], cnt = 1, trie[30*MAXN][3];

void clear()
{
	for ( int i = 0; i < cnt; i++ )
		for ( int j = 0; j < 3; j++ )
			trie[i][j] = 0;
	cnt = 1;
}

void ins ( int x )
{
	int node = 0, nxt;
	for ( int i = 0; i <= 24; i++ )
	{
		trie[node][2]++;
		nxt = (x & (1 << i) ? 1 : 0);
		if ( !trie[node][nxt] )
			trie[node][nxt] = cnt++;
		node = trie[node][nxt];
	}
	trie[node][2]++;
}

void qry ( int bit, int x )
{
	if ( (x & 1) == 0 )
		return;

	int node = 0, nxt;
	++bit;
	if ( trie[node][1] )
	{
		node = trie[node][1];
		tot[bit] += trie[node][2];
	}
	else
		return;

	for ( int i = 1; i <= 24; i++ )
	{
		++bit;
		nxt = (x & (1 << i) ? 0 : 1 );
		if ( trie[node][nxt] )
		{
			node = trie[node][nxt];
			tot[bit] += trie[node][2];
		}
		else
			return;
	}
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	int a[N];
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	
	int ans = 0;
	for ( int bit = 0; bit <= 24; bit++ )
	{
		clear();
		tot[bit] += (a[0] & 1 ? 1 : 0) * (N - 1);
		ins ( a[0] );
		a[0] /= 2;
		for ( int i = 1; i < N; i++ )
		{
			tot[bit] += (a[i] & 1 ? 1 : 0) * (N - 1);
			qry ( bit, a[i] );
			ins ( a[i] );
			a[i] /= 2;
		}
		ans += ((tot[bit] & 1) << bit);
	}
	cout << ans << "\n";
	return 0;
}
