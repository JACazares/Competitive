#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N;
vector<vi> Graph;

int solveMax(int node, int p = -1)
{
    int sum = 0, e = 0, edges = 0;
    for(auto i : Graph[node])
        if(i != p)
        {
            int aux = solveMax(i, node);
            sum += aux;
            if(!aux && !e)
            {
                edges++;
                e = 1;
            }
            else if(aux)
                edges++;
        }
    return sum + edges;
}

int solveMin(int node, int p = -1, int d = 0)
{
    if(Graph[node].size() == 1 && p != -1)
    {
        if(d % 2 == 0)
            return 1;
        else
            return 3;
    }
    int ans = 1;
    for(auto i : Graph[node])
        if(i != p)
            ans = max(ans, solveMin(i, node, d + 1));
    return ans;
}

int main ()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    Graph.resize(N + 5);
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    
    int leaf, root;
    for(int i = 1; i <= N; i++)
    {
        if(Graph[i].size() == 1)
            leaf = i;
        else
            root = i;
    }
    
    int maxim = solveMax(root);
    int minim = solveMin(leaf);
    cout << minim << " " << maxim << "\n";
    return 0;
}
