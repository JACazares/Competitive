#include <iostream>
#include <algorithm>
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, a[MAXN], last, islands, dead[MAXN], ans;
vector < pii > b;
pii x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for ( int i = 1; i <= N; i++ )
        cin >> a[i], b.push_back ( {a[i], i} );
    sort ( b.begin(), b.end() );

    last = -1, islands = 1, ans = 1;
    dead[0] = 1, dead[N + 1] = 1;

    for ( int i = 0; i < b.size(); i++ )
    {
        if ( i && b[i].first != b[i - 1].first )
            ans = max ( ans, islands );

        x = b[i];
        if ( dead[x.second - 1] && dead[x.second + 1] )
            islands--;
        if ( !dead[x.second - 1] && !dead[x.second + 1] )
            islands++;
        dead[x.second] = 1;
    }
    ans = max ( ans, islands );

    cout << ans << "\n";
    return 0;
}
