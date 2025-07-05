#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAXN = 2e5 + 5;
const ll MOD = 998244353LL;
ll N, K, fact[MAXN], inv[MAXN];

ll binexp(ll b, ll e)
{
    if(e == 0)  return 1LL;
    if(e&1) return (binexp(b, e - 1) * b) % MOD;
    else
    {
        ll aux = binexp(b, e/2);
        return (aux * aux) % MOD;
    }
}

ll choose(ll n, ll k)
{
    return ((fact[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    fact[0] = 1;
    for(ll i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for(ll i = 0; i <= N; i++)
        inv[i] = binexp(fact[i], MOD - 2);
    
    ll ans = 0;
    if(K == 0)
        ans = fact[N];
    else if(K <= N)
    {
        for(int i = 0; i <= N - K; i += 2)
        {
            ans += (binexp(N - K - i, N) * choose(N - K, i)) % MOD;
            ans %= MOD;
        }
        for(int i = 1; i <= N - K; i += 2)
        {
            ans -= (binexp(N - K - i, N) * choose(N - K, i)) % MOD;
            ans %= MOD;
            ans = (ans + MOD) % MOD;
        }
        ans *= (2*choose(N, N - K))%MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
