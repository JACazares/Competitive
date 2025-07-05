#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 998244353;
ll N, M, L, R;

ll binexp(ll b, ll e)
{
    if(e == 0) return 1;
    if(e&1) return (binexp(b, e-1) * b)%MOD;
    else
    {
        ll aux = binexp(b, e/2);
        return (aux*aux)%MOD;
    }
}

int main ()
{
	ios_base::sync_with_stdio ( 0 ); cin.tie ( 0 );
	cin >> N >> M >> L >> R;
    if((N*M) & 1)
        cout << binexp((R-L+1)%MOD, N*M) << "\n";
    else
    {
        if((R-L+1)%2 == 0)
            cout << (binexp((R-L+1)%MOD, N*M) * binexp(2, MOD-2))%MOD << "\n";
        else if(R%2 == 0)
        {
            ll aux = ((binexp((R-L+1)%MOD, N*M - 1) + 1) * binexp(2, MOD-2)) % MOD;
            ll aux2 = ((binexp((R-L+1)%MOD, N*M - 1) - aux)%MOD + MOD)%MOD;
            ll even = (R/2 - (L-1)/2);
            ll odd = (R-L+1) - even;
            even %= MOD;
            odd %= MOD;
            aux *= even;
            aux %= MOD;
            aux2 *= odd;
            aux2 %= MOD;
            cout << (aux + aux2) % MOD << "\n";
        }
        else if(R%2 == 1)
        {
            ll aux = ((binexp((R-L+1)%MOD, N*M - 1) + 1) * binexp(2, MOD-2)) % MOD;
            ll aux2 = ((binexp((R-L+1)%MOD, N*M - 1) - aux)%MOD + MOD)%MOD;
            ll even = (R/2 - (L-1)/2);
            ll odd = (R-L+1) - even;
            even %= MOD;
            odd %= MOD;
            aux *= odd;
            aux %= MOD;
            aux2 *= even;
            aux2 %= MOD;
            cout << (aux + aux2) % MOD << "\n";
        }
    }
	return 0;
}
