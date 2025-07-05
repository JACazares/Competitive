#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

constexpr int MAXN = 2505;
unsigned int N, M;
vector<tuple<unsigned int, unsigned int, long long>> edges;
vector<unsigned int> Graph[MAXN], GraphT[MAXN];
vector<bool> visited, visitedT;

void dfs(const unsigned int node, const vector<unsigned int>G[],  vector<bool> &vis) {
    if (vis[node])
        return;
    vis[node] = true;
    for (const auto v : G[node]) {
        if (vis[v])
            continue;
        dfs(v, G, vis);
    }
}

int main() {
    cin >> N >> M;
    for (unsigned int i = 0; i < M; i++) {
        unsigned int u, v;
        long long w;
        cin >> u >> v >> w;
        Graph[u].push_back(v);
        GraphT[v].push_back(u);
        edges.push_back({u, v, -w});
    }

    visited.resize(N + 1, false);
    visitedT.resize(N + 1, false);
    dfs(1, Graph, visited);
    dfs(N, GraphT, visitedT);

    for (unsigned int i = 1; i <= N; i++)
        visited[i] = (visited[i] && visitedT[i]);

    vector<long long> dist(N + 1, 1e18);

    dist[1] = 0;
    for (unsigned int k = 0; k < N; k++) {
        for (auto [u, v, w] : edges) {
            if (!visited[u] || !visited[v])
                continue;

            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for (auto [u, v, w] : edges) {
        if (!visited[u] || !visited[v])
            continue;

        if (dist[u] + w < dist[v]) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << -dist[N] << "\n";
    return 0;
}