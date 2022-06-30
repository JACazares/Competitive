#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#define MAXN 100005
#define INF (1LL << 60LL)
#define VARS int mid = (l + r) / 2, lchild = (2 * node) + 1, rchild = (2 * node) + 2
#define pii pair < ll, ll >

using namespace std;
typedef long long ll;

struct Node
{
	ll cost, node1, node2, node3;

	bool operator < ( const Node _a ) const
	{
		if ( cost == _a.cost )
		{
			if ( node1 == _a.node1 )
			{
				if ( node2 == _a.node2 )
					return node3 > _a.node3;
				return node2 > _a.node2;
			}
			return node1 > _a.node1;
		}
		return cost > _a.cost;
	}

	void out ()
	{
		cout << cost << " " << node1 << " " << node2 << " " << node3 << "\n";
	}
};

ll N, a, b, c, v1, v2, v3, u, v, dist[MAXN], fst[MAXN], val;
vector < ll > Graph[MAXN], nodes, depths, specialNodes, vi;
pii ST[10 * MAXN];
priority_queue < Node > PQ;
map < Node, int > visited, ans;
Node tmp, aux2;

void dfs ( ll node, ll p = 0, ll d = 0 )
{
	dist[node] = d;
	fst[node] = nodes.size();
	nodes.push_back ( node );
	depths.push_back ( d );
	for ( auto i : Graph[node] )
		if ( i != p )
		{
			dfs ( i, node, d + 1 );
			nodes.push_back ( node );
			depths.push_back ( d );
		}
}

void build ( ll node = 0, ll l = 0, ll r = nodes.size() - 1 )
{
	if ( l == r )
	{
		ST[node] = {depths[l], l};
		return;
	}
	
	VARS;
	build ( lchild, l, mid );
	build ( rchild, mid + 1, r );
	ST[node] = min ( ST[lchild], ST[rchild] );
}

pii qry ( ll L, ll R, ll node = 0, ll l = 0, ll r = nodes.size() - 1 )
{
	if ( r < L or R < l )
		return {INF, 0};
	if ( L <= l && r <= R )
		return ST[node];
	
	VARS;
	return min ( qry ( L, R, lchild, l, mid ), qry ( L, R, rchild, mid + 1, r ) );
}

ll lca ( ll nodeA, ll nodeB )
{
	if ( fst[nodeA] > fst[nodeB] )
		swap ( nodeA, nodeB );
	return nodes[qry(fst[nodeA], fst[nodeB]).second];
}

ll dis ( ll nodeA, ll nodeB )
{
	return dist[nodeA] + dist[nodeB] - 2 * dist[lca ( nodeA, nodeB )];
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	cin >> a >> b >> c;
	cin >> v1 >> v2 >> v3;
	for ( ll i = 0; i < N - 1; i++ )
	{
		cin >> u >> v;
		Graph[u].push_back ( v );
		Graph[v].push_back ( u );
	}
	dfs ( 1 );
	build ( );

	specialNodes.push_back ( 1 );
	specialNodes.push_back ( v1 );
	specialNodes.push_back ( v2 );
	specialNodes.push_back ( v3 );
	specialNodes.push_back ( lca ( v1, v2 ) );
	specialNodes.push_back ( lca ( v1, v3 ) );
	specialNodes.push_back ( lca ( v2, v3 ) );
	specialNodes.push_back ( lca ( lca ( v1, v2 ), v3 ) );

	sort ( specialNodes.begin(), specialNodes.end() );

	for ( int i = 0; i < specialNodes.size(); )
	{
		val = specialNodes[i];
		vi.push_back ( val );
		while ( i < specialNodes.size() && val == specialNodes[i] ) i++;
	}

	PQ.push ( {0, v1, v2, v3} );
	while ( !PQ.empty() )
	{
		auto aux = PQ.top();
		PQ.pop();
		aux2 = aux;
		aux2.cost = 0;
		if ( visited[aux2] )
			continue;
		visited[aux2] = 1;
		ans[aux2] = aux.cost;

		for ( auto i : vi )
		{

			if ( aux.node1 != i )
			{
				tmp = aux, tmp.cost = aux.cost + dis ( aux.node1, i ) * a, tmp.node1 = i;
				PQ.push ( tmp );
			}
			if ( aux.node2 != i )
			{
				tmp = aux, tmp.cost = aux.cost + dis ( aux.node2, i ) * a, tmp.node2 = i;
				PQ.push ( tmp );
			}
			if ( aux.node3 != i )
			{
				tmp = aux, tmp.cost = aux.cost + dis ( aux.node3, i ) * a, tmp.node3 = i;
				PQ.push ( tmp );
			}

			if ( aux.node1 == aux.node2 && aux.node1 != i )
			{
				tmp = aux, tmp.cost = aux.cost + dis ( aux.node1, i ) * b, tmp.node1 = i, tmp.node2 = i;
				PQ.push ( tmp );
			}
			if ( aux.node1 == aux.node3 && aux.node1 != i )
			{
				tmp = aux, tmp.cost = aux.cost + dis ( aux.node1, i ) * b, tmp.node1 = i, tmp.node3 = i;
				PQ.push ( tmp );
			}
			if ( aux.node2 == aux.node3 && aux.node2 != i )
			{
				tmp = aux, tmp.cost = aux.cost + dis ( aux.node2, i ) * b, tmp.node2 = i, tmp.node3 = i;
				PQ.push ( tmp );
			}

			if ( aux.node1 == aux.node2 && aux.node2 == aux.node3 && aux.node1 != i )
			{
				tmp = aux, tmp.cost = aux.cost + dis ( aux.node1, i ) * c, tmp.node1 = i, tmp.node2 = i, tmp.node3 = i;
				PQ.push ( tmp );
			}
		}
	}

	cout << ans[{0, 1, 1, 1}] << "\n";
	return 0;
}
