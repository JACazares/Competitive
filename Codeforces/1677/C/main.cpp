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

const int MAXN = (int)2e5 + 5;
int N, a[MAXN], b[MAXN], posa[MAXN], posb[MAXN], vis[MAXN];
vi G[MAXN];

int dfs(int node)
{
	if(vis[node])
		return 0;
	vis[node] = 1;
	
	int ret = 1;
	for(auto i : G[node])
		ret += dfs(i);
	return ret;
}

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		G[i].clear();
		vis[i] = 0;
	}
		
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		posa[a[i]] = i;
	}
	for(int i = 1; i <= N; i++)
	{
		cin >> b[i];
		posb[b[i]] = i;
	}
	
	for(int i = 1; i <= N; i++)
	{
		G[i].pb(posb[a[i]]);
		G[i].pb(posa[b[i]]);
	}
	
	int tot = N;
	for(int i = 1; i <= N; i++)
		if(!vis[i])
			tot -= (dfs(i) % 2);
	
	ll ans = 0;
	for(int i = 1, j = N; i < j && tot > 0; i++, j--, tot -= 2)
		ans += 2*(j - i);
	cout << ans << "\n";
}

int main()
{
	optimizeIO();
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
