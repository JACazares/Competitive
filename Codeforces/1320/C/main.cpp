#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAXN = 2e5 + 5, INF = (1LL << 60LL), MAX = 1e6 + 5;
ll N, M, P, pre[MAX + 5];
pii w[MAXN], a[MAXN], ST[4 * MAX];
pair<ll, pii> m[MAXN];

pii comb ( pii A, pii B )
{
	pii aux;
	aux.second = A.second + B.second;
	aux.first = max ( A.first, A.second + B.first );
	return aux;
}

void upd ( ll pos, ll val )
{
	pos += MAX;
	ST[pos].first += val;
	ST[pos].second += val;
	for ( pos = pos / 2; pos; pos /= 2 )
		ST[pos] = comb ( ST[2*pos], ST[2*pos + 1] );
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M >> P;
	for ( ll i = 0; i < N; i++ )
		cin >> w[i].first >> w[i].second;
	for ( ll i = 0; i < M; i++ )
		cin >> a[i].first >> a[i].second;
	for ( ll i = 0; i < P; i++ )
		cin >> m[i].first >> m[i].second.first >> m[i].second.second;
	sort ( w, w + N );
	sort ( a, a + M );
	sort ( m, m + P );

	ll minim = INF;
	pre[a[M - 1].first] = INF;
	for ( ll i = M - 1; i >= 1; i-- )
	{
		minim = min ( minim, a[i].second );
		if ( a[i - 1].first != a[i].first )
			pre[a[i - 1].first] = minim;
	}
	minim = min ( minim, a[0].second );

	ll past = minim, left = 0;
	pre[0] = -minim;
	for ( ll i = 1; i <= MAX; i++ )
	{
		left = pre[i] - past;
		if ( pre[i] != 0 )
		{
			past = pre[i];
			pre[i] = left;
		}
		pre[i] *= -1;
	}
	
	for ( ll i = 0; i <= MAX; i++ )
		ST[i + MAX] = {pre[i], pre[i]};
	for ( ll i = MAX - 1; i; i-- )
		ST[i] = comb ( ST[2*i], ST[2*i + 1] );

	ll rpnt = 0, finalAns = -INF;
	for ( ll i = 0; i < N; i++ )
	{
		for ( ; rpnt < P; rpnt++ )
		{
			if ( m[rpnt].first >= w[i].first )
				break;
			upd ( m[rpnt].second.first, m[rpnt].second.second );
		}
		
		pii leftAns = ST[MAX], rightAns = {0, 0}, ans;
		for ( ll l = MAX + 1, r = 2*MAX + 1; l < r; l /= 2, r /= 2 )
		{
			if ( l & 1 )
				leftAns = comb ( leftAns, ST[l++] );
			if ( r & 1 )
				rightAns = comb ( ST[--r], rightAns );
		}
		ans = comb ( leftAns, rightAns );
		finalAns = max ( finalAns, ans.first - w[i].second );
	}
	cout << finalAns << "\n";
	return 0;
}
