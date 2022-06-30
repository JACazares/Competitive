#include <iostream>
#include <queue>
#include <vector>
#define pii pair < ll, ll >
#define MAXN 100005
#define VARS ll mid = (l + r) / 2, lchild = (2 * node) + 1, rchild = (2 * node) + 2

using namespace std;
typedef long long ll;

ll offset1, offset2, visited[10 * MAXN], cost[10 * MAXN];
ll N, M, S, t, u, v, a, b, c;
vector < pii > Graph[10 * MAXN];
priority_queue < pii > PQ;

void build ( ll node = 0, ll l = 1, ll r = N )
{
	if ( l == r )
	{
		Graph[node + offset1].push_back ( {0, l} );
		Graph[l].push_back ( {0, node + offset2} );
		return;
	}

	VARS;
	build ( lchild, l, mid );
	build ( rchild, mid + 1, r );

	Graph[node + offset1].push_back ( {0, lchild + offset1} );
	Graph[node + offset1].push_back ( {0, rchild + offset1} );
	Graph[lchild + offset2].push_back ( {0, node + offset2} );
	Graph[rchild + offset2].push_back ( {0, node + offset2} );
}

void upd ( ll _u, ll L, ll R, ll x, bool f, ll node = 0, ll l = 1, ll r = N )
{
	if ( R < l or r < L )
		return;
	if ( L <= l && r <= R )
	{
		if ( !f )
			Graph[_u].push_back ( {x, node + offset1} );
		else
			Graph[node + offset2].push_back ( {x, _u} );
		return;
	}

	VARS;
	upd ( _u, L, R, x, f, lchild, l, mid );
	upd ( _u, L, R, x, f, rchild, mid + 1, r );
}

int main ()
{
	cin >> N >> M >> S;

	offset1 = N + 5;
	offset2 = (5 * N) + 5;

	build ( );

	for ( ll i = 0; i < M; i++ )
	{
		cin >> t;
		if ( t == 1 )
		{
			cin >> u >> v >> c;
			Graph[u].push_back ( {c, v} );
		}
		else if ( t == 2 or t == 3 )
		{
			cin >> u >> a >> b >> c;
			upd ( u, a, b, c, (t == 2 ? 0 : 1) );
		}
	}

	for ( ll i = 1; i <= N; i++ )
		cost[i] = -1;

	PQ.push ( {0, S} );
    while ( !PQ.empty() )
    {
        auto aux = PQ.top();
        PQ.pop();

        if ( visited[aux.second] )
            continue;
        visited[aux.second] = 1;
        cost[aux.second] = -aux.first;
		
        for ( auto i : Graph[aux.second] )
            if ( !visited[i.second] )
                PQ.push ( {aux.first - i.first, i.second} );
    }

    for ( ll i = 1; i <= N; i++ )
        cout << cost[i] << " ";
    cout << "\n";
	return 0;
}
