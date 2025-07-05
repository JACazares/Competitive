#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;
int N, blue[MAXN], red[MAXN], ans[MAXN];
vi Graph[MAXN];

void solve(int node, int p = 0)
{
    for(auto i : Graph[node])
        if(i != p)
            solve(i, node);

    int children = 0;
    for(auto i : Graph[node])
        if(i != p)
            children++;
    blue[node] = 1;
    red[node] = children - 1;
    for(auto i : Graph[node])
    {
        if(i == p)
            continue;
        blue[node] = max(blue[node], 1 + red[i]);
        red[node] = max(red[node], children - 1 + max(red[i], blue[i]));
    }
    
    int b1 = 0, b2 = 0, r1 = 0, r2 = 0;
    for(auto i : Graph[node])
    {
        int aux;
        aux = red[i];
        if(aux > b1)
        {
            b2 = b1;
            b1 = aux;
        }
        else if(aux > b2)
            b2 = aux;
        
        aux = max(red[i], blue[i]);
        if(aux > r1)
        {
            r2 = r1;
            r1 = aux;
        }
        else if(aux > r2)
            r2 = aux;
    }
    
    if(children == 0)
        ans[node] = 1;
    else if(children == 1)
        ans[node] = max(ans[node], max(blue[node], red[node]));
    else
        ans[node] = max(ans[node], max(b1 + b2 + 1, children - 2 + r2 + r1));
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    solve(1);
    int res = 0;
    for(int i = 1; i <= N; i++)
        res = max(res, ans[i]);
    cout << res << "\n";
    return 0;
}
