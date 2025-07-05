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
        int n;
        cin >> n;
        ll ans = 0;
        ans += (1 << n);
        for(int i = n - 1; i >= n - n/2; i--)
            ans -= (1 << i);
        for(int i = n - n/2 - 1; i >= 1; i--)
            ans += (1 << i);
        cout << ans << "\n";
    }
    return 0;
}

//IF USE CEIL/FLOOR, CAST TO INT
