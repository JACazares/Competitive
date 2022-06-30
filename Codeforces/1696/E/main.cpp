#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pii>;
using vpl = vector<pll>;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define snd second
 
int pct(int x) { return __builtin_popcount((unsigned int)x); }
 
// TO_STRING, credits: Benq
#define ts to_string
string ts(char c) { return string(1,c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < sz(v); i++) res += char('0'+v[(unsigned long)i]);
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
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h);
    if (sizeof...(t))
        cerr << ", ";
	DBG(t...);
}
 
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define optimizeIO() 0
#else
#define dbg(...) 0
#define optimizeIO() ios_base::sync_with_stdio(false); cin.tie(nullptr)
#endif

const int MAXN = 4e5 + 5;
const ll MOD = 1e9 + 7;
ll fact[MAXN], inv[MAXN];

ll binexp(ll b, ll e)
{
	if(e == 0)
		return 1LL;
	if(e&1)
		return (b * binexp(b, e-1)) % MOD;
	else
	{
		ll aux = binexp(b, e/2);
		return (aux * aux) % MOD;
	}
}

ll choose(int n, int k)
{
	return (((fact[n] * inv[k]) % MOD) * inv[n - k]) % MOD;
}

int main()
{
	optimizeIO();
	int N;
	cin >> N;
	
	fact[0] = 1;
	inv[0] = binexp(fact[0], MOD - 2);
	for(int i = 1; i < MAXN; i++)
	{
		fact[i] = (fact[i - 1] * (ll)i) % MOD;
		inv[i] = binexp(fact[i], MOD - 2);
	}
	
	ll ans = 0;
	for(int i = 0; i <= N; i++)
	{
		int a;
		cin >> a;
		if(a > 0)
			ans = (ans + choose(a + i, a - 1)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
