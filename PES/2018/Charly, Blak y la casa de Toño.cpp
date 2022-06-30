#include <iostream>
#include <vector>
#define MAXN 200005
#define INF (1<<30)
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int N, Q, u, v, first[MAXN], A, B, C, auxdepth;
pii segTree[4*MAXN];
bool visited[MAXN];
vector<int> Graph[MAXN], recorrido, depth;

void dfs ( int n, int d )
{
    visited[n] = 1;

    first[n] = recorrido.size();
    recorrido.push_back(n);
    depth.push_back(d);

    for ( auto nextNode : Graph[n] )
    {
        if ( !visited[nextNode] )
        {
            dfs ( nextNode, d + 1 );
            recorrido.push_back(n);
            depth.push_back(d);
        }
    }
}

pii query ( int node, int l, int r, int L, int R )
{
    if ( L <= l && r <= R )
        return segTree[node];
    if ( r < L || R < l )
        return mp ( INF, -1 );

    int lchild = (2 * node) + 1;
    int rchild = (2 * node) + 2;
    int mid = (l + r) / 2;

    pii left = query(lchild, l, mid, L, R);
    pii right = query(rchild, mid + 1, r, L, R);
    if ( left.first <= right.first )
        return left;
    else
        return right;
}

void build ( int node, int l, int r )
{
    if ( l == r )
    {
        segTree[node] = mp(depth[l], l);
        return;
    }

    int lchild = (2 * node) + 1;
    int rchild = (2 * node) + 2;
    int mid = (l + r) / 2;
    build(lchild, l, mid);
    build(rchild, mid + 1, r);

    if ( segTree[lchild].first <= segTree[rchild].first )
        segTree[node] = segTree[lchild];
    else
        segTree[node] = segTree[rchild];
}

int lca ( int A, int B )
{
    /*cout << A << ", " << B << "\n";
    cout << query(0, 0, recorrido.size() - 1, min(first[A], first[B]), max(first[A], first[B])).second << "\n";
    cout << recorrido[query(0, 0, recorrido.size() - 1, min(first[A], first[B]), max(first[A], first[B])).second] << "\n";*/
    return recorrido[query(0, 0, recorrido.size() - 1, min(first[A], first[B]), max(first[A], first[B])).second];
}

int main()
{
    cin >> N >> Q;
    for ( int i = 0; i < N - 1; i++ )
    {
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    dfs(1, 1);
    build(0, 0, recorrido.size() - 1);


    for ( int i = 0; i < Q; i++ )
    {
        cin >> A >> B >> C;

        int depthA = depth[first[A]];
        int depthB = depth[first[B]];
        int depthC = depth[first[C]];

        //cout << depthA << " " << depthB << " " << depthC << "\n";

        int possible1 = lca(A, B);
        int possible2 = lca(A, C);
        int possible3 = lca(B, C);

        int depth1 = depth[first[possible1]];
        int depth2 = depth[first[possible2]];
        int depth3 = depth[first[possible3]];

        auxdepth = depth[first[lca(possible1, C)]];
        int ans1 = abs(depth1 - depthA) + abs(depth1 - depthB) + abs(auxdepth - depthC) + abs(auxdepth - depth1);

        auxdepth = depth[first[lca(possible2, B)]];
        int ans2 = abs(depth2 - depthA) + abs(depth2 - depthC) + abs(auxdepth - depthB) + abs(auxdepth - depth2);

        auxdepth = depth[first[lca(possible3, A)]];
        int ans3 = abs(depth3 - depthB) + abs(depth3 - depthC) + abs(auxdepth - depthA) + abs(auxdepth - depth3);

        if ( ans1 <= ans2 && ans1 <= ans3 )
            cout << possible1 << " " << ans1 << "\n";
        else if ( ans2 <= ans1 && ans2 <= ans3)
            cout << possible2 << " " << ans2 << "\n";
        else if ( ans3 <= ans1 && ans3 <= ans2 )
            cout << possible3 << " " << ans3 << "\n";
    }
    return 0;
}
