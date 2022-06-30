#include <iostream>
#include <vector>
#define MAXN 500005
#define INF (1 << 30)

using namespace std;
typedef long long ll;

struct Node
{
    int val;
    Node *lchild, *rchild;
    bool lazy;

    Node()
    {
        val = 0;
        lazy = 0;
        lchild = nullptr;
        rchild = nullptr;
    }
};

int N, R, x, a, sum, ans, aux;
vector < int > blocks;
Node *root;

void upd ( int L, int R, Node* node = root, int l = 1, int r = N )
{
    if ( node -> lazy )
    {
        node -> val = r - l + 1;
        return;
    }
    if ( L <= l && r <= R )
    {
        node -> val = r - l + 1;
        node -> lazy = 1;
        return;
    }
    if ( r < L or R < l )
        return;

    int mid = (l + r) / 2;
    if ( !(node -> lchild) )
        node -> lchild = new Node();
    if ( !(node -> rchild) )
        node -> rchild = new Node();

    upd ( L, R, node -> lchild, l, mid );
    upd ( L, R, node -> rchild, mid + 1, r );
    node -> val = node -> lchild -> val + node -> rchild -> val;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> R;

    root = new Node();
    for ( int i = 0; i < R; i++ )
    {
        blocks.clear();
        cin >> x;
        for ( int j = 0; j < x; j++ )
            cin >> a, blocks.push_back ( a );

        sum = 0, aux = 0;
        for ( auto j : blocks )
            sum += j;

        for ( auto j : blocks )
        {
            if ( aux + j >= N - sum + 1 )
                upd ( N - sum + 1, aux + j );
            aux += j, sum -= j;
        }
    }

    if ( root -> lazy )
        root -> val = N;
    ans = root -> val;

    cout << ans << "\n";
    return 0;
}
