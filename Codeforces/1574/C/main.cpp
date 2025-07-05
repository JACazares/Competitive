#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = (int)2e5 + 5;
const ll INF = (1LL << 62LL);
int N, Q;
ll a[MAXN], sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + N);
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        ll x, y;
        cin >> x >> y;
        ll hero = lower_bound(a, a + N, x) - a;
        if(hero == N)
            cout << (x - a[N - 1]) + max(0LL, y - (sum - a[N - 1])) << "\n";
        else
        {
            // keep hero the same
            ll geq = INF, le = INF;
            geq = max(y - (sum - a[hero]), 0LL);
            if(hero > 0)
                le = max(max(x - a[hero - 1], 0LL) + max(y - (sum - a[hero - 1]), 0LL), 0LL);
            cout << min(geq, le) << "\n";
        }
    }
    return 0;
}
