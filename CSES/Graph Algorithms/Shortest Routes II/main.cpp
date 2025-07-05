#include <iostream>

using namespace std;

constexpr int MAXN = 505;
constexpr long long INF = static_cast<long long>(1e18);
int N, M, Q;
long long DP[MAXN][MAXN];

void floyd_warshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            DP[i][j] = INF;
        }
        DP[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        DP[u][v] = min(DP[u][v], w);
        DP[v][u] = min(DP[v][u], w);
    }

    floyd_warshall();

    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (DP[u][v] == INF ? -1 : DP[u][v]) << "\n";
    }
    return 0;
}