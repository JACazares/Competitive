#include <iostream>
#include <vector>
#define MAXN 100005
#define mp make_pair
using namespace std;

long long N, M, K, u, v, A[MAXN], B[MAXN];
vector < pair<long long, long long> > ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    cin >> K;
    for ( long long i = 0; i < K; i++ )
    {
        cin >> u >> v;
        if ( !A[u] && !B[v])
        {
            ans.push_back(mp(u, v));
            A[u] = 1;
            B[v] = 1;
        }
    }

    cout << ans.size() << "\n";
    for ( auto i : ans )
        cout << i.first << " " << i.second << "\n";
    return 0;
}
