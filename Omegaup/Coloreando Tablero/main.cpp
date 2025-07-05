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

const int MAXN = (int)1e3 + 5;
const int MAXK = (int)1e6 + 5;
const ll MOD = (ll)1e9 + 7;

int N, M, K;
ll ans, s2[MAXN][MAXN], fact[MAXK], inv[MAXK];

ll binexp(ll b, ll e)
{
	if(e == 0)
		return 1;
	if(e == 1)
		return b;
	if(e&1)
		return (b*binexp(b, e-1))%MOD;
	else
	{
		ll a = binexp(b, e/2);
		return (a*a)%MOD;
	}
}

ll comb(ll n, ll k)
{
	if(n < k || n < 0)
		return 0;
	return (((fact[n]*inv[k])%MOD)*inv[n-k])%MOD;
}

int main()
{
	optimizeIO();
	cin >> N >> M >> K;
	
	fact[0] = 1;
	inv[0] = 1;
	for(int i = 1; i <= max(N, K); i++)
	{
		fact[i] = (fact[i-1]*i)%MOD;
		inv[i] = binexp(fact[i], MOD-2);
	}
	
	s2[0][0] = 1;
	s2[1][1] = 1;
	for(int i = 1; i <= N; i++)
		for(int k = 1; k <= i; k++)
		{
			if(i == 1 && k == 1)
				continue;
				
			s2[i][k] = ((k*s2[i-1][k])%MOD + s2[i-1][k-1])%MOD;
		}
	
	if(M > 2)
	{
		for(int k = 1; k <= min(N, K); k++)
		{
			for(int i = 1; i <= k; i++)
			{
				// Choose which k colors
				ll colors = comb(K, i);
				colors = (((colors * comb(K-i,k-i))%MOD) * comb(K-k,k-i))%MOD;
				
				// Choose edges 
				ll edge = (s2[N][k] * fact[k])%MOD;
				edge = (edge*edge)%MOD;
				
				// Choose middle
				ll middle = binexp(i, N*(M-2));
				
				ans += (((colors * edge)%MOD) * middle)%MOD;
				ans %= MOD;
			}
		}
	}
	else if(M == 2)
	{
		for(int k = 1; k <= min(N, K); k++)
		{
			// Choose which k colors, for each edge
			ll colors = comb(K, k);
			colors = (colors*colors)%MOD;
			
			// Choose edges 
			ll edge = (s2[N][k] * fact[k])%MOD;
			edge = (edge*edge)%MOD;
			
			ans += (colors * edge)%MOD;
			ans %= MOD;
		}
	}
	else if(M == 1)
	{
		for(int k = 1; k <= min(N, K); k++)
		{
			// Choose which k colors
			ll colors = comb(K, k);
			
			// Choose edge
			ll edge = (s2[N][k] * fact[k])%MOD;
			
			ans += (colors * edge)%MOD;
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	dbg(binexp(K, N));
	return 0;
}


