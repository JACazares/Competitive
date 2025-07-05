#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

vl BIT(4e5 + 5);

void upd ( int pos )
{
	for ( ; pos <= 4e5 + 5; pos += (pos & -pos) )
		BIT[pos]++;
}

ll qry ( int pos )
{
	ll ans = 0;
	for ( ; pos; pos -= (pos & -pos) )
		ans += BIT[pos];
	return ans;
}

int main ()
{
	//ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	int N;
	cin >> N;
	vi a(N), b(N);
	for ( int i = 0; i < N; i++ )
		cin >> a[i];
	for ( int i = 0; i < N; i++ )
		cin >> b[i];
		
	vi c;
	for ( int i = 0; i < N; i++ )
	{
		c.push_back ( a[i] - b[i] );
		c.push_back ( b[i] - a[i] );
	}
	sort ( c.begin(), c.end() );
	map<int, int> MP;
	for ( int i = 0; i < c.size(); i++ )
		MP[c[i]] = i + 1;
	
	ll ans = 0;
	for ( int i = N - 1; i >= 0; i-- )
	{
		ans += qry ( MP[a[i] - b[i]] - 1 );
		upd ( MP[b[i] - a[i]] );
	}
	cout << ans << "\n";
	return 0;
}
