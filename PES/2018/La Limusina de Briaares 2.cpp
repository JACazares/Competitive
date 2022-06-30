#include <iostream>
#include <vector>
#define MAXN 1005
#define INF (1<<30)
using namespace std;

int N, M, W, peso[MAXN], genial[MAXN], u, v, numGroups, DP[MAXN][MAXN];
int visited[MAXN], TGenial[MAXN], TPeso[MAXN];
vector<int> Graph[MAXN], Group[MAXN];

void floodfill ( int node, int g )
{
    visited[node] = g;
    Group[g].push_back(node);
    TGenial[g] += genial[node];
    TPeso[g] += peso[node];
    for ( auto nextNode : Graph[node] )
    {
        if ( !visited[nextNode] )
            floodfill(nextNode, g);
    }
}

int dp ( int grupo, int capacity )
{
    //cout << grupo << " " << capacity << "\n";
    if ( capacity < 0 )
        return -INF;
    if ( grupo > numGroups )
        return 0;

    if ( DP[grupo][capacity] > -1)
        return DP[grupo][capacity];

    int ret = 0;

    ret = max ( dp(grupo + 1, capacity), dp(grupo + 1, capacity - TPeso[grupo]) + TGenial[grupo] );
    for ( auto nextNode : Group[grupo] )
        ret = max ( ret, dp(grupo + 1, capacity - peso[nextNode]) + genial[nextNode] );

    //cout << "returning " << ret << " for " << grupo << " " << capacity << "\n";
    return DP[grupo][capacity] = ret;
}

int main()
{
    cin >> N >> M >> W;
    for ( int i = 1; i <= N; i++ )
        cin >> peso[i];
    for ( int i = 1; i <= N; i++ )
        cin >> genial[i];
    
    for ( int i = 0; i < N + 5; i++ )
        for ( int j = 0; j < W + 5; j++ )
            DP[i][j] = -1;

    for ( int i = 0; i < M; i++ )
    {
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    for ( int i = 1; i <= N; i++ )
    {
        if ( !visited[i] )
            floodfill(i, ++numGroups);
    }

    cout << dp ( 1, W );
    return 0;
}
