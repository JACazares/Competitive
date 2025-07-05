#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int N, M;
vector<tuple<int, int, long long>> edges;

int main() {
    cin >> N >> M;
    vector<int> in(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        in[v]++;
    }

    vector<long long> dist(N + 1, 1e18);
    vector<int> pred(N + 1, 0);

    dist[1] = 0;
    pred[1] = 1;

    for (int i = 1; i <= N; i++)
        if (in[i] == 0) {
            dist[i] = 0;
            pred[i] = i;
        }

    for (int i = 0; i < N - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }

    vector<int> ans;
    for (auto [u, v, w] : edges) {
        if (dist[u] + w < dist[v]) {
            int current_node = u;
            do {
                ans.push_back(current_node);
                current_node = pred[current_node];
            } while (current_node != u);
            ans.push_back(u);
        }
    }

    if (ans.empty()) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        ranges::reverse(ans);
        for (const auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}