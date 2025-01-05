#include <iostream>
#include <vector>

using ll = long long;

const int MOD = (int)1e9 + 7;

int main()
{
    int N = (int)1e6;
    std::vector<ll> f(N + 1), pre(N + 1, 0), fourth(N + 1);
    fourth[0] = 1;
    for(int i = 1; i <= N; i++)
        fourth[i] = 4ll*fourth[i - 1] % MOD;

    ll prev = 0;
    f[0] = 1;
    pre[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        // All only width = 1
        f[i] = fourth[i-1]%MOD;

        // First l rows, block of 2xl
        f[i] += pre[i-1];
        f[i] %= MOD;

        // First k rows, 1xa blocks, then a 2xl block.
        if(i >= 2)
        {
            prev = (4ll*prev%MOD+pre[i-2])%MOD;
            f[i] += prev;
            f[i] %= MOD;
        }

        pre[i] = (pre[i-1] + f[i]) % MOD;
    }

    int T;
    std::cin >> T;
    while(T--)
    {
        int n;
        std::cin >> n;
        std::cout << f[n] << "\n";
    }
    return 0;
}