#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
int N, K, a[MAXN], c[MAXN], b[MAXN], vis[MAXN], ST[4*MAXN];
vi ans[MAXN];

void build(int node = 0, int l = 0, int r = N - 1)
{
    if(l == r)
    {
        ST[node] = b[l];
        return;
    }
    
    int mid = (l+r) / 2, lchild = (2*node) + 1, rchild = (2*node) + 2;
    build(lchild, l, mid);
    build(rchild, mid + 1, r);
    ST[node] = max(ST[lchild], ST[rchild]);
}

int qry(int R, int val, int node = 0, int l = 0, int r = N - 1)
{
    if(l > R)
        return -1;
    if(ST[node] < val)
        return -1;
    if(l == r)
    {
        if(ST[node] >= val)
            return l;
        return -1;
    }
    
    int mid = (l+r) / 2, lchild = (2*node) + 1, rchild = (2*node) + 2;
    int aux = qry(R, val, rchild, mid + 1, r);
    if(aux == -1)
        return qry(R, val, lchild, l, mid);
    return aux;
}

void upd(int pos, int val, int node = 0, int l = 0, int r = N - 1)
{
    if(r < pos || pos < l)
        return;
    if(l == r)
    {
        ST[node] = val;
        return;
    }
    
    int mid = (l+r) / 2, lchild = (2*node) + 1, rchild = (2*node) + 2;
    upd(pos, val, lchild, l, mid);
    upd(pos, val, rchild, mid + 1, r);
    ST[node] = max(ST[lchild], ST[rchild]);
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a+N);
    for(int i = 1; i <= K; i++)
        cin >> c[i];
    for(int i = 0; i < N; i++)
        b[i] = c[a[i]];
    build();
    int curr = 0;
    for(int i = N - 1; i >= 0; i--)
    {
        if(vis[i])
            continue;
        vis[i] = 1;
        ans[curr].push_back(a[i]);
        int cnt = 2;
        upd(i, -1);
        int nxt = qry(i, cnt);
        while(nxt >= 0)
        {
            upd(nxt, -1);
            ans[curr].push_back(a[nxt]);
            vis[nxt] = 1;
            ++cnt;
            nxt = qry(nxt, cnt);
        }
        curr++;
    }
    cout << curr << "\n";
    for(int i = 0; i < curr; i++)
    {
        cout << ans[i].size() << " ";
        for(auto j : ans[i])
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}
