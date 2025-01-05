#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> a(N), idx(N + 1);
    for(int i = 0; i < N; i++)
    {
        std::cin >> a[i];
        idx[a[i]] = i;
    }
    
    int total_rounds = 1;
    int curr_idx = idx[1];
    for(int num = 2; num <= N; num++) 
    {
        if(idx[num] < curr_idx)
            total_rounds++;
        curr_idx = idx[num];
    }

    
    return 0;
}