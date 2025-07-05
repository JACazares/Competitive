#include <iostream>
#include <vector>
#include <map>

int main()
{
    int N, S;
    std::cin >> N >> S;

    std::map<int, int> buy, sell;
    for(int i = 0; i < N; i++)
    {
        char dir;
        std::cin >> dir;

        int p, q;
        std::cin >> p >> q;

        if(dir == 'B')
            buy[p] += q;
        if(dir == 'S')
            sell[p] += q;
    }

    std::vector<std::pair<int, int>> ans;
    int i = 0;
    for(auto it = sell.begin(); it != sell.end(); it++)
    {
        if(i == S)
            break;
        ans.push_back(*it);
        i++;
    }

    for(auto it = ans.rbegin(); it != ans.rend(); it++)
    {
        auto [p, q] = *it;
        std::cout << "S " << p << " " << q << "\n";
    }

    i = 0;
    for(auto it = buy.rbegin(); it != buy.rend(); it++)
    {
        if(i == S)
            break;
        auto [p, q] = *it;
        std::cout << "B " << p << " " << q << "\n";
        i++;
    }
    return 0;
}