#include <algorithm>
#include <chrono>
#include <iterator>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

using ll = long long;

ll back_inserter()
{
    int N;
    std::cin >> N;

    std::vector<int> coins(N);
    std::copy_n(std::istream_iterator<int>(std::cin), N, std::back_inserter(coins));

    std::sort(coins.begin(), coins.end());
    
    ll largest_value = 0;
    for(int coin : coins)
    {
        if(coin <= largest_value + 1)
            largest_value += coin;
        else
            return largest_value + 1;
    }
    return largest_value + 1;
}

ll cin()
{
    int N;
    std::cin >> N;

    std::vector<int> coins(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> coins[i];
    }

    std::sort(coins.begin(), coins.end());
    
    ll largest_value = 0;
    for(int coin : coins)
    {
        if(coin <= largest_value + 1)
            largest_value += coin;
        else
            return largest_value + 1;
    }
    return largest_value + 1;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<std::vector<int>> test_cases = {
        {5, 2, 9, 1, 2, 7}
    };

    for (int i = 1e6; i <= (int)3e8; i *= 3) {
        std::vector<int> test_case(i + 1);
        test_case[0] = i;
        std::iota(test_case.begin() + 1, test_case.end(), 1);
        test_cases.push_back(test_case);
    }

    std::cout << "N\t| Elapsed time (back_inserter)\t| Elapsed time (cin)\n";
    std::cout << "---------------------------------------------------------------------------------------------\n";

    for (const auto& input : test_cases) {
        std::stringstream ss;
        for (int num : input) {
            ss << num << " ";
        }
        std::cin.rdbuf(ss.rdbuf());

        auto start = std::chrono::high_resolution_clock::now();
        ll result_back_inserter = back_inserter();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_back_inserter = end - start;

        // Reset the stringstream and std::cin buffer
        ss.clear();
        ss.seekg(0, std::ios::beg);
        std::cin.rdbuf(ss.rdbuf());

        start = std::chrono::high_resolution_clock::now();
        ll result_cin = cin();
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_cin = end - start;

        std::cout << input[0] << "\t| " << elapsed_back_inserter.count() << " seconds\t| " << elapsed_cin.count() << " seconds\n";
    }
    return 0;
}