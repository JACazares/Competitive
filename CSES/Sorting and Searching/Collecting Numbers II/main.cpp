#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> a(N + 1), idx(N + 2, 0);
    for(int i = 1; i <= N; i++)
    {
        std::cin >> a[i];
        idx[a[i]] = i;
    }
    idx[N + 1] = N + 1;

    int total_rounds = 1;
    for (int i = 1; i < N; i++) {
        if (idx[i] > idx[i + 1])
            total_rounds++;
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        if (a[x] > a[y])
            std::swap(x, y);

        // a[x] < a[y]
        if (a[x] == a[y] - 1) {
            if (idx[a[x]] > idx[a[y]])
                total_rounds--;
            else
                total_rounds++;

            std::swap(a[x], a[y]);
            idx[a[x]] = x;
            idx[a[y]] = y;
        }
        else {
            if (idx[a[x] - 1] > idx[a[x]])
                total_rounds--;
            if (idx[a[x]] > idx[a[x] + 1])
                total_rounds--;

            if (idx[a[y] - 1] > idx[a[y]])
                total_rounds--;
            if (idx[a[y]] > idx[a[y] + 1])
                total_rounds--;

            std::swap(a[x], a[y]);
            idx[a[x]] = x;
            idx[a[y]] = y;

            if (idx[a[x] - 1] > idx[a[x]])
                total_rounds++;
            if (idx[a[x]] > idx[a[x] + 1])
                total_rounds++;

            if (idx[a[y] - 1] > idx[a[y]])
                total_rounds++;
            if (idx[a[y]] > idx[a[y] + 1])
                total_rounds++;
        }

        std::cout << total_rounds << "\n";
    }
    return 0;
}
