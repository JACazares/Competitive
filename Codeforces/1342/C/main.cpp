#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        ll a, b, q;
        cin >> a >> b >> q;
        if(a > b)
            swap(a, b);
        ll tot = 0;
        vi ans(a*b, 0), pre(a*b, 0);
        for(int i = 0; i < a*b; i++)
        {
            if(i)
                pre[i] = pre[i - 1];
            if(i%a != (i%b)%a)
            {
                ans[i] = 1;
                pre[i]++;
                tot++;
            }
        }

        while(q--)
        {
            ll l, r, res = 0;
            cin >> l >> r;
            if(l / (a*b) == r / (a*b))
            {
                if(l%(a*b) == 0)
                    res += pre[r%(a*b)];
                else
                    res += pre[r%(a*b)] - pre[l%(a*b)-1];
            }
            else
            {
                if(l%(a*b) == 0)
                    res += pre[a*b - 1];
                else
                    res += pre[a*b - 1] - pre[l%(a*b) - 1];
                res += pre[r%(a*b)];
                res += tot * (r/(a*b) - l/(a*b) - 1);
            }
            cout << res << " ";
        }
        cout << "\n";
    }
    return 0;
}
