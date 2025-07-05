#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 5e5 + 5;
const ll INF = (1LL << 60LL);
int N, M, a[MAXN], p[MAXN], b[MAXN], nxt[MAXN], idx[MAXN];
ll BIT[MAXN], DP[MAXN], minim[MAXN], pre[MAXN];

void upd(int pos, ll x)
{
    for(; pos <= N + 1; pos += (pos & -pos))
        BIT[pos] += x;
}

ll qry(int pos)
{
    ll ans = 0;
    for(; pos; pos -= (pos & -pos))
        ans += BIT[pos];
    return ans;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> a[i];
    for(int i = 1; i <= N; i++)
    {
        cin >> p[i];
        pre[i] = pre[i - 1] + p[i];
    }
    cin >> M;
    for(int i = 1; i <= M; i++)
    {
        cin >> b[i];
        idx[b[i]] = i;
        nxt[i] = N + 1;
    }
    nxt[M + 1] = N + 1;
    
    for(int i = N; i >= 1; i--)
    {
        if(p[i] >= 0)
            upd(a[i], p[i]);
        else
            upd(N + 1, p[i]);

        if(idx[a[i]] > 0)
        {
            //go to next same -- take from me to before next to be "bad(idx - 1)"
            //  this represents NOT taking me to be part of the answer
            ll ans1 = INF;
            if(DP[nxt[idx[a[i]]]] < INF && nxt[idx[a[i]]] <= N)
                ans1 = qry(N + 1) - qry(b[idx[a[i]] - 1]) - minim[nxt[idx[a[i]]]] + DP[nxt[idx[a[i]]]];

            //go to next big -- take from me + 1 to before next to be "bad(idx)"
            //  this represents TAKING me to be part of the anser
            ll ans2 = INF;
            if(DP[nxt[idx[a[i]] + 1]] < INF && nxt[idx[a[i]] + 1] <= N)
            {
                ans2 = qry(N + 1) - qry(b[idx[a[i]]]) - minim[nxt[idx[a[i]] + 1]] + DP[nxt[idx[a[i]] + 1]];
                if(p[i] < 0)
                    ans2 -= p[i];
            }
            else if(idx[a[i]] == M)
            {
                ans2 = qry(N + 1) - qry(b[idx[a[i]]]);
                if(p[i] < 0)
                    ans2 -= p[i];
            }
            
            DP[i] = min(ans1, ans2);
            nxt[idx[a[i]]] = i;
            minim[i] = qry(N + 1) - qry(b[idx[a[i]] - 1]);
        }
    }
    
    ll ans = INF;
    for(int i = 1; i <= N; i++)
    {
        if(a[i] == b[1])
        {
            if(DP[i] < INF)
                ans = DP[i] + pre[i - 1];
            break;
        }
    }
    
    if(ans < INF)
        cout << "YES\n" << ans << "\n";
    else
        cout << "NO\n";
    return 0;
}
