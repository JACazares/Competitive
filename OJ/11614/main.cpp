#include <iostream>

using namespace std;
using ll = long long;

void solve()
{
    ll x = 0;
    cin >> x;
    
    ll s = 0, e = 2e9, mid = 0, ans = 0;
    while(s <= e)
    {
        mid = (s + e) / 2;
        ll sum = (mid * (mid + 1)) / 2LL;

        if(sum <= x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << ans << "\n";
}

int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}