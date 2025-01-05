#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int N, x;
    std::cin >> N >> x;

    std::vector<int> a(N);
    for(int i = 0; i < N; i++)
        std::cin >> a[i];
    
    std::unordered_map<int, std::pair<int, int>> total_sums;
    int mid = N/2;
    for(int i = 0; i < mid; i++)
        for(int j = i + 1; j < mid; j++)
            total_sums[a[i] + a[j]] = {i, j};
    
    for(int i = mid; i < N; i++)
        for(int j = i + 1; j < N; j++)
            if(total_sums.find(x - (a[i] + a[j])) != total_sums.end())
            {
                auto [k, l] = total_sums[x - (a[i] + a[j])];
                std::cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << "\n";
                return 0;
            }

    std::cout << "IMPOSSIBLE\n";
    return 0;
}