#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    const ll INF = (1LL << 62LL);
    int T;
    cin >> T;
    while(T--)
    {
        int R, G, B;
        cin >> R >> G >> B;
        ll r[R], g[G], b[B];
        for(int i = 0; i < R; i++)
            cin >> r[i];
        for(int i = 0; i < G; i++)
            cin >> g[i];
        for(int i = 0; i < B; i++)
            cin >> b[i];

        sort(r, r + R);
        sort(g, g + G);
        sort(b, b + B);
        
        ll ans = INF;
        int gpnt;

        gpnt = 0;
        for(int i = 0; i < R; i++)
        {
            for(; gpnt < G; gpnt++)
            {
                if(g[gpnt] > r[i])
                    break;
            }
            //gpnt - 1 <= r[i], gpnt > r[i]
            if(gpnt - 1 >= 0)
            {
                auto bp1 = upper_bound(b, b + B, (r[i] + g[gpnt - 1]) / 2);
                auto bp2 = bp1;
                if(bp1 != b)
                    bp1--;
                //bpnt1 <= mid, bnpt2 > mid
                ans = min(ans,ll(pow(r[i] - g[gpnt - 1], 2)+pow(r[i] - *bp1, 2)+pow(g[gpnt - 1] - *bp1, 2)));
                if(bp2 != (b + B))
                    ans = min(ans,ll(pow(r[i] - g[gpnt - 1], 2)+pow(r[i] - *bp2, 2)+pow(g[gpnt - 1] - *bp2, 2)));
            }
            if(gpnt < G)
            {
                auto bp1 = upper_bound(b, b + B, (r[i] + g[gpnt]) / 2);
                auto bp2 = bp1;
                if(bp1 != b)
                    bp1--;
                //bpnt1 <= mid, bnpt2 > mid
                ans = min(ans,ll(pow(r[i] - g[gpnt], 2)+pow(r[i] - *bp1, 2)+pow(g[gpnt] - *bp1, 2)));
                if(bp2 != (b + B))
                    ans = min(ans,ll(pow(r[i] - g[gpnt], 2)+pow(r[i] - *bp2, 2)+pow(g[gpnt] - *bp2, 2)));
            }
        }
        
        gpnt = 0;
        for(int i = 0; i < G; i++)
        {
            for(; gpnt < R; gpnt++)
            {
                if(r[gpnt] > g[i])
                    break;
            }
            //gpnt - 1 <= r[i], gpnt > r[i]
            if(gpnt - 1 >= 0)
            {
                auto bp1 = upper_bound(b, b + B, (g[i] + r[gpnt - 1]) / 2);
                auto bp2 = bp1;
                if(bp1 != b)
                    bp1--;
                //bpnt1 <= mid, bnpt2 > mid
                ans = min(ans,ll(pow(g[i] - r[gpnt - 1], 2)+pow(g[i] - *bp1, 2)+pow(r[gpnt - 1] - *bp1, 2)));
                if(bp2 != (b + B))
                    ans = min(ans,ll(pow(g[i] - r[gpnt - 1], 2)+pow(g[i] - *bp2, 2)+pow(r[gpnt - 1] - *bp2, 2)));
            }
            if(gpnt < R)
            {
                auto bp1 = upper_bound(b, b + B, (g[i] + r[gpnt]) / 2);
                auto bp2 = bp1;
                if(bp1 != b)
                    bp1--;
                //bpnt1 <= mid, bnpt2 > mid
                ans = min(ans,ll(pow(g[i] - r[gpnt], 2)+pow(g[i] - *bp1, 2)+pow(r[gpnt] - *bp1, 2)));
                if(bp2 != (b + B))
                    ans = min(ans,ll(pow(g[i] - r[gpnt], 2)+pow(g[i] - *bp2, 2)+pow(r[gpnt] - *bp2, 2)));
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
