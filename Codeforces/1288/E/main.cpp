#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3e5 + 5;
int N, M, a[MAXN], minim[MAXN], maxim[MAXN], BIT[2*MAXN], pos[MAXN];

void upd ( int x, int val )
{
	for ( ; x <= N + M; x += (x & -x) )
		BIT[x] += val;
}

int qry ( int x )
{
	int ans = 0;
	for ( ; x; x -= (x & -x) )
		ans += BIT[x];
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M;
	for ( int i = 1; i <= N; i++ )
		minim[i] = i;
	for ( int i = 0; i < M; i++ )
	{
		cin >> a[i];
		minim[a[i]] = 1;
	}
	
	for ( int i = M + 1; i <= M + N + 1; i++ )
	{
		upd ( i, 1 );
		pos[i - M] = i;
	}

	int cnt = M;
	for ( int i = 0; i < M; i++ )
	{
		maxim[a[i]] = max ( maxim[a[i]], qry ( pos[a[i]] ) );
		upd ( pos[a[i]], -1 );
		upd ( cnt--, 1 );
		pos[a[i]] = cnt + 1;
	}
	for ( int i = 1; i <= N; i++ )
	{
		maxim[i] = max ( maxim[i], qry ( pos[i] ) );
		cout << minim[i] << " " << maxim[i] << "\n";
	}
	return 0;
}
