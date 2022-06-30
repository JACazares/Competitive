#include <iostream>
#include <vector>
#define MAXN 1001005

using namespace std;
typedef long long ll;

ll N, Q, t, p, ans, aux, x, y, BIT[3 * MAXN], lbound, rbound;
bool f;
vector < int > v;

void upd ( ll pos, ll val )
{
	for ( ; pos <= 2 * N; pos += (pos & -pos) )
		BIT[pos] += val;
}

ll qry ( ll pos )
{
	ll val = 0;
	for ( ; pos; pos -= (pos & -pos) )
		val += BIT[pos];
	return val;
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> Q;

	for ( ll i = 1; i <= N; i++ )
		upd ( i, 1 );
	f = 0;
	lbound = 0;
	rbound = N;
	for ( ll q = 0; q < Q; q++ )
	{
		cin >> t;
		if ( t == 1 )
		{
			cin >> p;
			if ( 2 * p <= rbound - lbound && !f )
			{
				//cout << "chida y left\n";
				for ( ll i = p + lbound + 1, j = p + lbound; j >= lbound + 1; i++, j-- )
				{
					aux = qry ( j ) - qry ( j - 1 );
					upd ( i, aux );
				}
				lbound += p;
			}
			else if ( 2 * p <= rbound - lbound && f )
			{
				//cout << "chida y right\n";
				p = rbound - p;
				for ( ll i = p + 1, j = p; i <= rbound; i++, j-- )
				{
					aux = qry ( i ) - qry ( i - 1 );
					upd ( j, aux );
				}
				rbound = p;
			}
			else if ( 2 * p > rbound - lbound && !f )
			{
				//cout << "no chida y right\n";
				for ( ll i = p + lbound + 1, j = p + lbound; i <= rbound; i++, j-- )
				{
					aux = qry ( i ) - qry ( i - 1 );
					upd ( j, aux );
				}
				rbound = p + lbound;
				f = 1;
			}
			else if ( 2 * p > rbound - lbound && f )
			{
				//cout << "no chida y left\n";
				p = rbound - p;
				for ( ll i = p + 1, j = p; j >= lbound + 1; i++, j-- )
				{
					aux = qry ( j ) - qry ( j - 1 );
					upd ( i, aux );
				}
				lbound = p;
				f = 0;
			}
		}
		else if ( t == 2 )
		{
			cin >> x >> y;
			if ( f == 0 )
				cout << qry ( y + lbound) - qry ( x + lbound ) << "\n";
			else if ( f == 1 )
			{
				y = rbound - y;
				x = rbound - x;
				swap ( x, y );
				cout << qry ( y ) - qry ( x ) << "\n";
			}
		}
	}
	return 0;
}
