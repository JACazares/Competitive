#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
    ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
    int T;
    cin >> T;
    while(T--)
    {
        int N, M, a, pairity[2] = {0, 0};
        ll ans = 0;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> a;
            pairity[a&1]++;
        }
        cin >> M;
        for(int i = 0; i < M; i++)
        {
            cin >> a;
            ans += pairity[a&1];
        }
        cout << ans << "\n";
    }
    return 0;
}
