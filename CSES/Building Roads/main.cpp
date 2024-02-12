#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;
int N, M, parent[MAXN];

int look(int node)
{
    if(parent[node] == node)
        return node;
    return parent[node] = look(parent[node]);
}

void join(int u, int v)
{
    parent[look(u)] = look(v);
}

int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        parent[i] = i;
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }

    vector<int> supercities;
    for(int i = 1; i <= N; i++)
        if(look(i) == i)
            supercities.push_back(i);
    
    cout << supercities.size() - 1 << "\n";
    for(int i = 0; i < supercities.size() - 1; i++)
        cout << supercities[i] << " " << supercities[i + 1] << "\n";
    return 0;
}