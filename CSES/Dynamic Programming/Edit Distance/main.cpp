#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = static_cast<int>(1e9);

int main() {
    string S, T;
    cin >> S >> T;

    const int N = static_cast<int>(S.length()), M = static_cast<int>(T.length());

    vector<vector<int>> DP(N + 1, vector<int>(M + 1, INF));
    DP[N][M] = 0;
    for (int j = M - 1; j >= 0; j--) {
        // Add character to S
        int i = N;
        DP[i][j] = min(DP[i][j], DP[i][j + 1] + 1);
    }

    for (int i = N - 1; i >= 0; i--) {
        // Add character to T
        int j = M;
        DP[i][j] = min(DP[i][j], DP[i + 1][j] + 1);
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            // Add character to S
            DP[i][j] = min(DP[i][j], DP[i][j + 1] + 1);

            // Add character to T
            DP[i][j] = min(DP[i][j], DP[i + 1][j] + 1);

            // Change character
            DP[i][j] = min(DP[i][j], DP[i + 1][j + 1] + 1);

            // Same character
            if (S[i] == T[j])
                DP[i][j] = min(DP[i][j], DP[i + 1][j + 1]);
        }
    }

    cout << DP[0][0] << "\n";
    return 0;
}