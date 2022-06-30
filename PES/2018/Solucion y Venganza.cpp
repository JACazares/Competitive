#include <iostream>
#include <algorithm>
#define MAXN 200005
#define pii pair<long long, long long>
#define mp make_pair
using namespace std;

long long N, R, a[MAXN], tipo, x, lpnt, rpnt, ans, lazy[4*MAXN];
pii ST1[4*MAXN], ST2[4*MAXN];

void propagate( long long node, long long l, long long r )
{
    if ( lazy[node] > -1 )
    {
        long long lchild = (2 * node) + 1;
        long long rchild = (2 * node) + 2;
        if ( l != r )
        {
            lazy[lchild] = lazy[node];
            lazy[rchild] = lazy[node];
        }
        ST1[node] = mp(lazy[node], l);
        ST2[node] = mp(lazy[node], r);
        lazy[node] = -1;
    }
}

void build1 ( long long node, long long l, long long r )
{
    lazy[node] = -1;

    if ( l == r )
    {
        ST1[node] = mp(a[l], l);
        return;
    }

    long long lchild = (2 * node) + 1;
    long long rchild = (2 * node) + 2;
    long long mid = (l + r)/2;

    build1 ( lchild, l, mid );
    build1 ( rchild, mid + 1, r );

    if ( ST1[lchild].first >= ST1[rchild].first )
        ST1[node] = ST1[lchild];
    else
        ST1[node] = ST1[rchild];
}

void build2 ( long long node, long long l, long long r )
{
    if ( l == r )
    {
        ST2[node] = mp(a[l], l);
        return;
    }

    long long lchild = (2 * node) + 1;
    long long rchild = (2 * node) + 2;
    long long mid = (l + r)/2;

    build2 ( lchild, l, mid );
    build2 ( rchild, mid + 1, r );

    if ( ST2[lchild].first < ST2[rchild].first )
        ST2[node] = ST2[lchild];
    else
        ST2[node] = ST2[rchild];
}

pii queryLeft ( long long node, long long l, long long r, long long A )
{
    long long lchild = (2 * node) + 1;
    long long rchild = (2 * node) + 2;
    long long mid = (l + r)/2;
    propagate(node, l, r);
    if ( l < r )
    {
        propagate(lchild, l, mid);
        propagate(rchild, mid + 1, r);
        if ( ST1[lchild].first >= A )
            return queryLeft(lchild, l, mid, A);
        else
            return queryLeft(rchild, mid + 1, r, A);
    }
    else
        return ST1[node];
}

pii queryRight ( long long node, long long l, long long r, long long A )
{
    long long lchild = (2 * node) + 1;
    long long rchild = (2 * node) + 2;
    long long mid = (l + r)/2;
    propagate(node, l, r);

    if ( l < r )
    {
        propagate(lchild, l, mid);
        propagate(rchild, mid + 1, r);
        if ( ST2[rchild].first <= A )
            return queryRight(rchild, mid + 1, r, A);
        else
            return queryRight(lchild, l, mid, A);
    }
    else
        return ST2[node];
}

void update1 ( long long node, long long l, long long r, long long L, long long R, long long val )
{
    propagate(node, l, r);
    if ( L <= l && r <= R )
    {
        lazy[node] = val;
        propagate(node, l, r);
        return;
    }
    if ( r < L || R < l)
        return;

    long long lchild = (2 * node) + 1;
    long long rchild = (2 * node) + 2;
    long long mid = (l + r)/2;

    update1 ( lchild, l, mid, L, R, val );
    update1 ( rchild, mid + 1, r, L, R, val );

    if ( ST1[lchild].first >= ST1[rchild].first )
        ST1[node] = ST1[lchild];
    else
        ST1[node] = ST1[rchild];
}

void update2 ( long long node, long long l, long long r, long long L, long long R, long long val )
{
    propagate(node, l, r);
    if ( L <= l && r <= R )
    {
        lazy[node] = val;
        propagate(node, l, r);
        return;
    }
    if ( r < L || R < l)
        return;

    long long lchild = (2 * node) + 1;
    long long rchild = (2 * node) + 2;
    long long mid = (l + r)/2;

    update2 ( lchild, l, mid, L, R, val );
    update2 ( rchild, mid + 1, r, L, R, val );

    if ( ST2[lchild].first < ST2[rchild].first )
        ST2[node] = ST2[lchild];
    else
        ST2[node] = ST2[rchild];
}

long long getElement(long long node, long long l, long long r, long long pos )
{
    propagate(node, l, r);
    if ( l == r )
        return ST1[node].first;

    long long lchild = (2 * node) + 1;
    long long rchild = (2 * node) + 2;
    long long mid = (l + r)/2;

    if ( pos <= mid )
        return getElement(lchild, l, mid, pos);
    else
        return getElement(rchild, mid + 1, r, pos);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for ( long long i = 0; i < N; i++ )
        cin >> a[i];
    sort ( a, a + N );
    build1 (0, 0, N - 1 );
    build2 (0, 0, N - 1 );
    cin >> R;
    for ( long long i = 0; i < R; i++ )
    {
        cin >> tipo >> x;
        if ( tipo == 1 )
        {
            lpnt = queryLeft ( 0, 0, N - 1, x ).second;
            rpnt = queryRight ( 0, 0, N - 1, x ).second;
            ans += getElement(0, 0, N - 1, rpnt + 1) - x;
            update1 ( 0, 0, N - 1, lpnt, rpnt, getElement(0, 0, N - 1, rpnt + 1) );
            update2 ( 0, 0, N - 1, lpnt, rpnt, getElement(0, 0, N - 1, rpnt + 1) );
        }
        if ( tipo == 2 )
        {
            lpnt = queryLeft ( 0, 0, N - 1, x ).second;
            rpnt = queryRight ( 0, 0, N - 1, x ).second;
            ans += x - getElement(0, 0, N - 1, lpnt - 1);
            update1 ( 0, 0, N - 1, lpnt, rpnt, getElement(0, 0, N - 1, lpnt - 1) );
            update2 ( 0, 0, N - 1, lpnt, rpnt, getElement(0, 0, N - 1, lpnt - 1) );
        }
    }
    cout << ans << "\n";
    return 0;
}
