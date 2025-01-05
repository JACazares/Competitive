#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using ll = long long;

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::vector<int> a(N), b(N);
    for(int i = 0; i < N; i++)
        std::cin >> a[i];

    std::unordered_map<int, int> frequency;
    int distinct_numbers = 0;
    
    ll ans = 0;
    int rpnt = 0;
    for(int i = 0; i < N; i++)
    {
        while(rpnt < N)
        {
            if(frequency[a[rpnt]] == 0 && distinct_numbers == K)
                break;

            if(frequency[a[rpnt]] == 0)
                distinct_numbers++;
            frequency[a[rpnt]]++;
            rpnt++;
        }

        ans += rpnt - i;

        if(frequency[a[i]] == 1)
            distinct_numbers--;
        frequency[a[i]]--;
    }
    std::cout << ans << "\n";
    return 0;
}