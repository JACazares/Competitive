#include <iostream>

using namespace std;
using ll = long long;

const int MAXN = (int)5e5 + 5;
int N;
ll ST[4*MAXN];

void update(int x, ll val, int node = 0, int l = 0, int r = N - 1)
{
    if(x < l || r < x)
        return;

    if(x <= l && r <= x)
    {
        ST[node] += val;
        return;
    }

    int mid = (l + r) / 2, lchild = 2*node + 1, rchild = 2*node + 2;
    update(x, val, lchild, l, mid);
    update(x, val, rchild, mid + 1, r);
    ST[node] = ST[lchild] + ST[rchild];
    // update the node
}

ll query(int L, int R, int node = 0, int l = 0, int r = N - 1)
{
    if(r < L || R < l)
        return 0;

    if(L <= l && r <= R)
        return ST[node];

    int mid = (l + r) / 2, lchild = 2*node + 1, rchild = 2*node + 2;
    return query(L, R, lchild, l, mid) + query(L, R, rchild, mid + 1, r);
}

int main()
{
    int Q;
    cin >> N >> Q;
    for(int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        update(i, val);
    }
    for(int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;
        if(type == 0)
        {
            int x, val;
            cin >> x >> val;
            update(x, val);
        }
        else if(type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r - 1) << "\n";
        }
    }
    return 0;
}