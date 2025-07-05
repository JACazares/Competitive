#include <iostream>
#include <vector>

template<typename T>
using vector = std::vector<T>;
using ll = long long;

ll solve(std::string num)
{
    if(num == "-1")
        return 0;

    int len = (int)num.length();
    vector<vector<vector<ll>>> dp(len + 1, vector<vector<ll>>(11, vector<ll>(2, 0)));

    for(int prev = 0; prev <= 9; prev++)
        dp[len][prev][1] = 1;
    dp[len][(int)(num[len - 1] - '0')][0] = 1;

    for(int n = len - 1; n >= 0; n--)
    {
        int digit = (int)(num[n] - '0');

        for(int prev = 0; prev <= 10; prev++)
        {
            for(int curr = 0; curr <= 10; curr++)
            {
                if(curr == 10 && prev != 10)
                    continue;
                if(prev == curr && prev != 10)
                    continue;
                if(prev == 10 && curr == 0 && n < len - 1)
                    continue;
                
                dp[n][prev][1] += dp[n + 1][curr][1];
                if(curr <= digit)
                    dp[n][prev][0] += dp[n + 1][curr][curr < digit ? 1 : 0];
                if(curr == 10)
                    dp[n][prev][0] += dp[n + 1][curr][1];
            }
        }
    }

    return dp[0][10][0];
}

int main()
{
    ll a, b;
    std::cin >> a >> b;
    std::cout << solve(std::to_string(b)) - solve(std::to_string(a-1)) << "\n";
    return 0;
}