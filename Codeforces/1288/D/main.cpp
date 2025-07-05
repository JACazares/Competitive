#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3e5 + 5, MAXM = 10;
int N, M, a[MAXN][MAXM], b[MAXN];

pair < bool, pii > solve ( int x )
{
	vi MP ( (1 << M), 0 );
	vector < pii > masks;
	for ( int i = 0; i < N; i++ )
	{
		b[i] = 0;
		for ( int j = 0; j < M; j++ )
			if ( a[i][j] >= x )
				b[i] |= (1 << j);
		if ( !MP[b[i]] )
			masks.push_back ( {b[i], i + 1} );
		MP[b[i]] = 1;
	}

	for ( auto i : masks )
		for ( auto j : masks )
			if ( (i.first | j.first) == (1 << M) - 1 )
				return {1, {i.second, j.second}};
	return {0, {-1, -1}};
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M;
	for ( int i = 0; i < N; i++ )
		for ( int j = 0; j < M; j++ )
			cin >> a[i][j];
	
	int s = 0, e = 1e9, mid;
	pii ans;
	pair < bool, pii > val;
	while ( s <= e )
	{
		mid = (s + e) / 2;
		val = solve ( mid );
		
		if ( val.first )
		{
			ans = val.second;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
