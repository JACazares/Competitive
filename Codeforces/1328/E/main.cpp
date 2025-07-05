#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
int N, M, k[MAXN], ans[MAXN];
vi Graph[MAXN], qry[MAXN];

void solve(int node, int p = 0)
{
    for(auto i : Graph[node])
    {
        if(i == p)
            continue;
        for(auto j : qry[i])
        {
            k[j]--;
            if(k[j] == 0)
                ans[j] = 1;
        }
    }
    for(auto i : Graph[node])
        if(i != p)
            solve(i, node);
    for(auto i : Graph[node])
    {
        if(i == p)
            continue;
        for(auto j : qry[i])
            k[j]++;
    }
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    
    for(int i = 0; i < M; i++)
    {
        cin >> k[i];
        int u;
        for(int j = 0; j < k[i]; j++)
        {
            cin >> u;
            qry[u].push_back(i);
        }
    }
    for(auto j : qry[1])
    {
        k[j]--;
        if(k[j] == 0)
            ans[j] = 1;
    }
    solve(1);
    for(auto j : qry[1])
        k[j]++;
    for(int i = 0; i < M; i++)
        cout << (ans[i] ? "YES" : "NO") << "\n";
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
