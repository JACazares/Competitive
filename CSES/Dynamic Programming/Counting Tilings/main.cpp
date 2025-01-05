#include <iostream>

int main()
{
    int N, M;
    std::cin >> N >> M;

    f[0][0] = 1;
    for(int mask = 1; mask < (1 << N); mask++)
        f[0][mask] = 0;

    for(int i = 1; i <= M; i++)
    {
        for(int mask = 0; mask < (1 << N); mask++)
        {
            for(int j = 0; j < N; j++)
            
        }
    }

    return 0;
}