#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        ll a[N];
        for(int i = 0; i < N; i++)
            cin >> a[i];
        int ans = 0;
        for(int i = 1; i < N; i++)
        {
            ll aux = max(0LL, a[i - 1] - a[i]);
            for(ll j = 0; j < 32; j++)
                if(aux & (1LL << j))
                    ans = max(ans, (int)(j + 1));
            a[i] = max(a[i], a[i - 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}
