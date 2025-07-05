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
        ll D, MOD;
        cin >> D >> MOD;
        ll c1 = 1, c2 = 2, ans = 0, pot;
        for(pot = 2; pot <= D; pot *= 2)
        {
            ans += ((pot/2) * c1) % MOD;
            ans %= MOD;
            c1 *= c2;
            c1 %= MOD;
            c2 *= 2;
            --c2;
            c2 = (c2%MOD + MOD)%MOD;
        }
        pot /= 2;
        ans += (((D - pot + 1) * c1)%MOD + MOD)%MOD;
        ans %= MOD;
        cout << ans << "\n";
    }
    return 0;
}
