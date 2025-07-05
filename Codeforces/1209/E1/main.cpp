#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll MAXN = 15, MAXM = 2005;

ll T, N, M, a[MAXN][MAXM], aux, aux2 = 0, ans;
priority_queue < pii > PQ;
vector < int > cols;

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> T;
	while ( T-- )
	{
		cin >> N >> M;
		for ( ll i = 0; i < N; i++ )
			for ( ll j = 0; j < M; j++ )
				cin >> a[i][j];
		
		for ( int j = 0; j < M; j++ )
		{
			aux = 0;
			for ( int i = 0; i < N; i++ )
				aux = max ( aux, a[i][j] );
			PQ.push ( {aux, j} );
		}
		
		cols.clear();
		for ( int i = 0; i < N; i++ )
			if ( !PQ.empty() )
				cols.push_back ( PQ.top().second ), PQ.pop();
		
		while ( !PQ.empty() )
			PQ.pop();
		
		ans = 0;
		for ( int i1 = 0; i1 < N; i1++ )
		for ( int i2 = 0; i2 < N; i2++ )
		for ( int i3 = 0; i3 < N; i3++ )
		{
			aux2 = 0;
			for ( int i = 0; i < N; i++ )
			{
				aux = a[i][cols[0]];
				if ( cols.size() >= 2 )
					aux = max ( aux, a[(i + i1) % N][cols[1]] );
				if ( cols.size() >= 3 )
					aux = max ( aux, a[(i + i2) % N][cols[2]] );
				if ( cols.size() >= 4 )
					aux = max ( aux, a[(i + i3) % N][cols[3]] );
				
				aux2 += aux;
			}
			
			ans = max ( ans, aux2 );
		}
		
		cout << ans << "\n";
	}
	return 0;
}
