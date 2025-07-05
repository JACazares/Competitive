#include <iostream>
#include <unordered_map>
#include <vector>

constexpr int MOD = static_cast<int>(1e9) + 7;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N), cnt(N + 1);
    std::unordered_map<int, int> mp;
    mp.reserve(N);
    int next_key = 1;
    for (int i = 0; i < N; i++)
    {
        int x;
        std::cin >> x;
        if (auto [_, success] = mp.try_emplace(x, next_key); success)
            next_key++;
        a[i] = mp[x];
        cnt[a[i]]++;
    }

    long long ans = 1;
    for (int i = 1; i < next_key; i++)
    {
        ans *= (1 + cnt[a[i]]);
        ans %= MOD;
    }
    std::cout << ans - 1 << "\n";
    return 0;
}
