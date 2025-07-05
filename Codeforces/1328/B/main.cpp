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
        ll n, k;
        cin >> n >> k;
        int cnt = 1;
        for(int i = 1; i <= n; i++)
        {
            if(k - i >= 1)
            {
                k -= i;
                cnt++;
            }
            else
                break;
        }
        --k;
        string ans = "";
        for(int i = 0; i < k; i++)
            ans += "a";
        ans += "b";
        for(int i = k + 1; i < cnt; i++)
            ans += "a";
        ans += "b";
        for(int i = cnt + 1; i < n; i++)
            ans += "a";
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
