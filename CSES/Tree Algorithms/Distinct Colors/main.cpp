#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 2e5 + 5;
int N, a[MAXN], pre[MAXN], t_in[MAXN], t_out[MAXN];
int nxt[MAXN], nxtc[MAXN];
vi Graph[MAXN], tot_colors;
map<int, int> compre;

int tim;
void dfs(int x, int p = -1)
{
    t_in[x] = tim;
    pre[tim++] = a[x];
    for(int y : Graph[x])
    {
        if(y == p)
            continue;
        dfs(y, x);
    }
    t_out[x] = tim - 1;
}

vector<oset<pii>> segtri;
int query(int idx) {
    int ans = 0;
    for(int l = N + t_in[idx], r = N + t_out[idx] + 1; l < r; l >>= 1, r >>= 1) {
        if(l & 1) {
            ans += segtri[l].size() - segtri[l].order_of_key({t_out[idx] + 1, 0});
            l++;
        }
        if(r & 1) {
            r--;
            ans += segtri[r].size() - segtri[r].order_of_key({t_out[idx] + 1, 0});
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
        tot_colors.pb(a[i]);
    }
        
    sort(all(tot_colors));
    for(int i = 0; i < N; i++)
        compre[tot_colors[i]] = i;
    for(int i = 0; i < N; i++)
        a[i] = compre[a[i]];
        
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        Graph[u].pb(v);
        Graph[v].pb(u);
    }
    
    dfs(0);
    for(int i = N - 1; i >= 0; i--)
        nxtc[i] = N;
    for(int i = N - 1; i >= 0; i--)
    {
        nxt[i] = nxtc[a[i]];
        nxtc[a[i]] = i;
    }
    segtri.assign(2 * N, oset<pair<int, int>>());
    for(int i = 0; i < N; i++)
        for(int idx = i + N; idx > 0; idx >>= 1)
            segtri[idx].insert({nxt[i], i});
    
    for(int i = 0; i < N; i++)
        cout << query(i) << " ";
    cout << "\n";
    return 0;
}
