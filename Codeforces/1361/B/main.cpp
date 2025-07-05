#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define mp make_pair
#define sz(x) (int)x.size()
#define pb push_back

int pct(int x) { return __builtin_popcount(x); }
template<class T> T ceil(T a, T b) {
    return ((a)/(b) + ((a)%(b) ? 1 : 0)); }
template<class T> T floor(T a, T b) {
    return ((a)/(b)); }

// TO_STRING, credits: Benq
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < sz(v); i++) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
	string res = ""; for(int i = 0; i < SZ; i++) res += char('0'+b[i]);
	return res; }
template<class A, class B> string ts(pair<A,B> p);
template<class T> string ts(T v) { // containers with begin(), end()
	bool fst = 1; string res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> string ts(pair<A,B> p) {
	return "("+ts(p.first)+", "+ts(p.second)+")"; }
    
// DEBUG, credits: Benq
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

const ll MOD = 1e9 + 7;

ll binexp(ll b, ll e)
{
    if(e == 0)  return 1;
    if(e&1) return (binexp(b, e - 1) * b) % MOD;
    else
    {
        ll aux = binexp(b, e/2);
        return (aux*aux) % MOD;
    }
}

const int MAXN = 1e6 + 5;
int N, P, k[MAXN];

void solve()
{
    cin >> N >> P;
    for(int i = 0; i < N; i++)
        cin >> k[i];
    if(P == 1)
    {
        cout << (N&1) << "\n";
        return;
    }
    sort(k, k + N);
    int cnt = 0;
    map<int, int> powers, borrow;
    for(int i = 0; i < N; i++)
    {
        ++cnt;
        if(i == N - 1 || k[i] != k[i + 1])
        {
            powers[k[i]] = cnt;
            cnt = 0;
        }
    }
    vi powers2;
    for(auto& i : powers)
    {
        if(i.second >= P)
        {
            powers[i.first + 1] += i.second / P;
            borrow[i.first + 1] = i.second / P;
        }
        i.second %= P;
        dbg(i);
        powers2.pb(i.first);
    }
    sort(powers2.begin(), powers2.end(), greater<int>());
    ll sign = 1, ans = 0;
    for(auto i : powers2)
    {
        if(sign == -1)
        {
            ans -= (powers[i] * binexp(P, i)) % MOD;
            ans %= MOD;
            continue;
        }

        if(powers[i]&1)
        {
            if(borrow[i])
            {
                powers[i]--;
                powers[i - 1] += P;
            }
            else
            {
                ans += sign * binexp(P, i);
                ans %= MOD;
                sign = -1;
            }
        }
    }
    ans = (ans + MOD) % MOD;
    cout << ans << "\n";
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

