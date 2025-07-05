#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    std::cin >> N >> K;

    std::vector<int> a(N);
    std::unordered_map<int, int> mp;
    mp.reserve(N);
    int nextKey = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        if (mp.find(a[i]) == mp.end())
            mp[a[i]] = nextKey++;
    }
    for (int i = 0; i < N; i++ ) {
        a[i] = mp[a[i]];
    }

    int rpnt = 0, distinct = 0;
    long long ans = 0;
    std::vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        while (rpnt < N && distinct < K) {
            if (cnt[a[rpnt]] == 0)
                distinct++;
            cnt[a[rpnt]]++;
            rpnt++;
        }

        while (rpnt < N && cnt[a[rpnt]] > 0) {
            cnt[a[rpnt]]++;
            rpnt++;
        }

        ans += rpnt - i;

        if (cnt[a[i]] == 1)
                distinct--;
        cnt[a[i]]--;
    }

    std::cout << ans << "\n";
    return 0;
}