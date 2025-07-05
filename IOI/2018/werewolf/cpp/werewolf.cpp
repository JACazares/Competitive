#include "werewolf.h"
#include <ranges>

using namespace std;
using vi = vector<int>;

vi check_validity(int N, vi X, vi Y, vi S, vi E, vi L, vi R)
{
    int Q = S.size();
    vi A(Q);
    vector<vi> G(N);

    for(auto [u, v] : views::zip(X, Y))
    {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = N - 1; i >= 0; i--)
    {
        for()
    }

    return A;
}
