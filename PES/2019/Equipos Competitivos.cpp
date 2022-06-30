#include <iostream>
#include <set>
#include <vector>
#define MAXN 200010
#define pii pair < ll, ll >

using namespace std;
typedef long long ll;

ll N, Q, type, x, y, sz[MAXN], rpnt, ans, C, upd, sum[MAXN];
vector < pii > A;
pii parent[MAXN];

ll look ( ll node )
{
	if ( parent[node].first == node )
		return node;
	return parent[node].first = look ( parent[node].first );
}

void join ( ll nodeA, ll nodeB )
{
	parent[look(nodeB)].second += parent[look(nodeA)].second;
	parent[look(nodeA)].first = look(nodeB);
}

int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	for ( ll i = 1; i <= N; i++ )
		parent[i] = {i, 1};
	sz[1] = N;

	set < ll > Treap;
	Treap.insert ( 1 );
	upd = 1;

	for ( ll t = 0; t < Q; t++ )
	{
		cin >> type;
		if ( type == 1 )
		{
			cin >> x >> y;
			if ( look ( x ) != look ( y ) )
			{
				if ( sz[parent[look(x)].second] == 1 )
					Treap.erase ( parent[look(x)].second );
				sz[parent[look(x)].second]--;

				if ( sz[parent[look(y)].second] == 1 )
					Treap.erase ( parent[look(y)].second );
				sz[parent[look(y)].second]--;

				join ( x, y );

				if ( sz[parent[look(x)].second] == 0 )
					Treap.insert ( parent[look(x)].second );
				sz[parent[look(x)].second]++;
				
				upd = 1;
			}
		}
		else if ( type == 2 )
		{
			cin >> C;

			if ( upd )
			{
				A.clear();
				for ( auto i : Treap )
					A.push_back ( {i, sz[i]} );
				upd = 0;
			}
			
			sum[A.size()] = 0;
			for ( ll i = A.size() - 1; i >= 0; i-- )
				sum[i] = sum[i + 1] + A[i].second;

			if ( C == 0 )
				ans = (sum[0] * (sum[0] - 1)) / 2;
			else
			{

				rpnt = 0;
				ans = 0;
				for ( ll lpnt = 0; lpnt < A.size(); lpnt++ )
				{
					for ( rpnt = max ( rpnt, lpnt + 1) ; rpnt < A.size() && A[rpnt].first - A[lpnt].first < C; rpnt++ ) ;
					if ( rpnt < A.size() && A[rpnt].first - A[lpnt].first >= C )
						ans += (A[lpnt].second * sum[rpnt]);
				}
			}

			cout << ans << "\n";
		}
	}
	return 0;
}
