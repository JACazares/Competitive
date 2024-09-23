#include <iostream>

using namespace std;
using ll = long long;

ll K;

void solve()
{
    cin >> K;
    ll cnt = 0;
    int len = 1;
    for(ll i = 9; ; i *= 10)
    {
        if(K > i * len)
        {
            K -= i * len;
            cnt += i;
            len++;
        }
        else
        {
            ll res = ((K - 1) / len) + 1 + cnt;
            int obj = (len - 1) - ((K - 1) % len);
            while(obj--)
                res /= 10;
            cout << res % 10 << "\n";
            break;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}