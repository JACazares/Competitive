#include "closing.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

const int MAXN = (int)5e2 + 5;
ll pre[MAXN], cost[MAXN];

ll qry(int a, int b)
{
    if(b < a)
        swap(b, a);
    return (b - 1 >= 0 ? pre[b - 1] : 0) - (a - 1 >= 0 ? pre[a - 1] : 0);
}

int max_score(int N, int X, int Y, ll K, vi U, vi V, vi W)
{
    int ans = 0;
    cerr << K << " -- " << X << "  " << Y << "\n";

    pre[0] = 0;
    for(int i = 1; i < N; i++)
        pre[i] = pre[i - 1] + W[i - 1];
    
    for(int i = 0; i < N - 1; i++)
        cerr << W[i] << " ";
    cerr << "\n";

    for(int lx = X; lx >= 0; lx--)
    {
        for(int rx = X + 1; rx <= N; rx++)
        {
            ll tot = 0;
            for(int i = 0; i < N; i++)
                cost[i] = 0;

            cerr << lx << ", " << rx << ":\n";
            for(int i = lx; i < rx; i++)
            {
                cost[i] = qry(i, X);
                tot += cost[i];
            }
            for(int i = 0; i < N; i++)
                cerr << cost[i] << " ";
            cerr << "\n";

            if(tot > K)
                break;

            int ly = Y;
            int ry = Y + 1;
            for(; ly >= 0; ly--) 
            {
                cerr << tot << " ";
                if(tot + max(qry(ly, Y) - cost[ly], 0LL) > K)
                {
                    ly++;
                    break;
                }
                tot += max(qry(ly, Y) - cost[ly], 0LL);
            }
            cerr << "\n";

            for(int ly = 0; ly <= Y; ly++)
            {
                for(; ry < N; ry++)
                {
                    if(tot + max(qry(Y, ry) - cost[ry], 0LL) > K)
                        break;
                    tot += max(qry(Y, ry) - cost[ry], 0LL);
                }
                cerr << "ly, ry: " << ly << ", " << ry << " -- " << tot << "\n";

                // [ly, ry)

                if(tot <= K)
                    ans = max(ans, rx - lx + ry - ly);
                tot -= max(qry(ly, Y) - cost[ly], 0LL);
            }
        }
    }
    return ans;
}
    