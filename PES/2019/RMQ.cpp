#include <iostream>
#include <vector>
#define MAXN 100005
#define VARS int mid = (l + r) / 2, lchild = (2 * node) + 1, rchild = (2 * node) + 2

using namespace std;

struct Query
{
    int l, r, res;
};

int N, Q, strong[MAXN], weak[MAXN], pos[MAXN], used[MAXN], ans[MAXN], nxt, possible;
int strongLazy[4 * MAXN], weakLazy[4 * MAXN];
int strongST[4 * MAXN], weakST[4 * MAXN];
Query q[MAXN], strongNum[MAXN], weakNum[MAXN];
vector < int > cluster[MAXN], wildcard;

void propagate ( int node, int l, int r )
{
    if ( strongLazy[node] != -1 )
    {
        strongST[node] = strongLazy[node];
        if ( l != r )
        {
            VARS;
            strongLazy[lchild] = strongLazy[node];
            strongLazy[rchild] = strongLazy[node];
        }
        strongLazy[node] = -1;
    }

    if ( weakLazy[node] != -1 )
    {
        weakST[node] = weakLazy[node];
        if ( l != r )
        {
            VARS;
            weakLazy[lchild] = weakLazy[node];
            weakLazy[rchild] = weakLazy[node];
        }
        weakLazy[node] = -1;
    }
}

void build ( int node = 0, int l = 0, int r = N - 1 )
{
    strongLazy[node] = -1, strongST[node] = -1;
    weakLazy[node] = -1, weakST[node] = -1;
    if ( l == r )
        return;

    VARS;
    build ( lchild, l, mid );
    build ( rchild, mid + 1, r );
}

void strongUpdate ( int L, int R, int val, int node = 0, int l = 0, int r = N - 1 )
{
    propagate ( node, l, r );
    if ( L <= l && r <= R )
    {
        strongLazy[node] = val;
        return;
    }
    if ( r < L or R < l )
        return;

    VARS;
    strongUpdate ( L, R, val, lchild, l, mid );
    strongUpdate ( L, R, val, rchild, mid + 1, r );
}

void weakUpdate ( int L, int R, int val, int node = 0, int l = 0, int r = N - 1 )
{
    propagate ( node, l, r );
    if ( L <= l && r <= R )
    {
        weakLazy[node] = val;
        return;
    }
    if ( r < L or R < l )
        return;

    VARS;
    weakUpdate ( L, R, val, lchild, l, mid );
    weakUpdate ( L, R, val, rchild, mid + 1, r );
}

int strongQuery ( int x, int node = 0, int l = 0, int r = N - 1 )
{
    propagate ( node, l, r );
    if ( x < l or r < x )
        return -1;
    if ( l == r )
        return strongST[node];

    VARS;
    return max ( strongQuery ( x, lchild, l, mid ), strongQuery ( x, rchild, mid + 1, r ) );
}

int weakQuery ( int x, int node = 0, int l = 0, int r = N - 1 )
{
    propagate ( node, l, r );
    if ( x < l or r < x )
        return -1;
    if ( l == r )
        return weakST[node];

    VARS;
    return max ( weakQuery ( x, lchild, l, mid ), weakQuery ( x, rchild, mid + 1, r ) );
}

int main()
{
    cin >> N >> Q;
    for ( int i = 0; i < N; i++ )
    {
        strongNum[i].l = -1, strongNum[i].r = N + 1;
        weakNum[i].l = N + 1, weakNum[i].r = -1;
    }
    for ( int i = 0; i < Q; i++ )
    {
        cin >> q[i].l >> q[i].r >> q[i].res;
        strongNum[q[i].res].l = max ( strongNum[q[i].res].l, q[i].l );
        strongNum[q[i].res].r = min ( strongNum[q[i].res].r, q[i].r );

        weakNum[q[i].res].l = min ( weakNum[q[i].res].l, q[i].l );
        weakNum[q[i].res].r = max ( weakNum[q[i].res].r, q[i].r );
    }

    build();
    for ( int i = 0; i < N; i++ )
    {
        if ( strongNum[i].l > strongNum[i].r )
            possible = -1;

        if ( strongNum[i].l != -1 )
            strongUpdate ( strongNum[i].l, strongNum[i].r, i );

        if ( weakNum[i].r != -1 )
            weakUpdate ( weakNum[i].l, weakNum[i].r, i );
    }

    if ( possible == -1 )
    {
        for ( int i = 0; i < N; i++ )
            cout << "-1 ";
        cout << "\n";
        return 0;
    }

    for ( int i = 0; i < N; i++ )
    {
        strong[i] = strongQuery ( i );
        weak[i] = weakQuery ( i );

        if ( strong[i] > -1 && weak[i] > -1 && weak[i] > strong[i] )
            strong[i] = -1;
    }

    for ( int i = 0; i < N; i++ )
        pos[i] = -1;
    for ( int i = 0; i < N; i++ )
        if ( strong[i] != -1 )
            pos[strong[i]] = i, used[strong[i]] = 1;

    for ( int i = 0; i < Q; i++ )
        if ( !used[q[i].res] )
            possible = -1;

    if ( possible == -1 )
    {
        for ( int i = 0; i < N; i++ )
            cout << "-1 ";
        cout << "\n";
        return 0;
    }

    for ( int i = 0; i < N; i++ )
        if ( pos[i] != -1 )
            ans[pos[i]] = i;

    for ( int i = 0; i < N; i++ )
    {
        if ( weak[i] == -1 )
            wildcard.push_back ( i );
        else
            cluster[weak[i]].push_back ( i );
    }

    for ( int i = 0; i < N; i++ )
    {
        nxt = max ( nxt, i + 1 );
        while ( used[nxt] ) nxt++;

        for ( auto j : cluster[i] )
        {
            if ( j == pos[i] )
                continue;

            ans[j] = nxt;
            used[nxt] = 1;
            while ( used[nxt] ) nxt++;
        }
    }

    nxt = 0;
    while ( used[nxt] ) nxt++;
    for ( auto j : wildcard )
    {
        ans[j] = nxt;
        used[nxt] = 1;
        while ( used[nxt] ) nxt++;
    }

    for ( int i = 0; i < N; i++ )
        if ( !used[i] )
            possible = -1;

    if ( possible == -1 )
        for ( int i = 0; i < N; i++ )
            ans[i] = -1;

    for ( int i = 0; i < N; i++ )
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
