#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5 + 5;
int N, a[MAXN], cnt = 0, trie[30*MAXN][2];

void ins ( int num )
{
    int node = 0, nxt;
    for ( int i = 30; i >= 0; i-- )
    {
        nxt = (num & (1 << i) ? 1 : 0);
        if ( !trie[node][nxt] )
            trie[node][nxt] = ++cnt;
        node = trie[node][nxt];
    }
}

int qry ( int node, int bit )
{
    if ( bit < 0 )
        return 0;

    if ( trie[node][0] && trie[node][1] )
        return min(qry(trie[node][0], bit - 1), qry(trie[node][1], bit - 1)) + (1 << bit);
    else if ( trie[node][0] )
        return qry(trie[node][0], bit - 1);
    else if ( trie[node][1] )
        return qry(trie[node][1], bit - 1);
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N;
	for ( int i = 0; i < N; i++ )
    {
	    cin >> a[i];
        ins(a[i]);
    }
    
    cout << qry(0, 30) << "\n";
	return 0;
}
