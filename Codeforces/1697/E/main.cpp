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

const int MAXN = 1e2 + 5, MOD = 998244353;
const ll INF = (1LL << 62LL);
int N, del[MAXN], cnt[MAXN];
ll x[MAXN], y[MAXN], minDist[MAXN], fact[MAXN], inv[MAXN];
vi minim[MAXN];

ll binexp(int b, int e)
{
	if(e == 0)
		return 1;
	if(e&1)
		return b*binexp(b, e-1)%MOD;
	else
	{
		ll aux = binexp(b, e/2);
		return aux*aux%MOD;
	}
}

ll dist(int i, int j)
{
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

ll choose(int n, int k)
{
	return fact[n]*inv[n-k]%MOD*inv[k]%MOD;
}

int main()
{
	optimizeIO();
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
		
	for(int i = 0; i < N; i++)
	{
		minDist[i] = INF;
		for(int j = 0; j < N; j++)
		{
			if(j == i)
				continue;
			minDist[i] = min(minDist[i], dist(i, j));
		}
		
		minim[i].pb(i);
		for(int j = 0; j < N; j++)
			if(dist(i, j) == minDist[i])
				minim[i].pb(j);
		sort(all(minim[i]));
	}
	
	for(int i = 0; i < N; i++)
		for(auto j : minim[i])
			if(!(minim[j] == minim[i]))
				del[i] = 1;
	
	for(int i = 0; i < N; i++)
	{
		if(del[i])
			minim[i].clear();
		dbg(minim[i]);
		cnt[minim[i].size()]++;
	}
	
	
	fact[0] = 1;
	inv[0] = 1;
	for(int i = 1; i <= N; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = binexp(fact[i], MOD - 2);
	}
	
	ll ans = 0;
	int tw = cnt[2]/2, th = cnt[3]/3, fo = cnt[4]/4;
	for(int i = 0; i <= tw; i++)
	for(int j = 0; j <= th; j++)
	for(int k = 0; k <= fo; k++)
	{
		ans += choose(N, N - i - 2*j - 3*k) * fact[N - i - 2*j - 3*k] % MOD * choose(tw, i) % MOD * choose(th, j) % MOD * choose(fo, k) % MOD;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}
