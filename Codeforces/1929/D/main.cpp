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

const ll MOD = 998244353;

void precalc_sz(int node, int p, vi& subtree_sz, const vector<vi>& Graph)
{
	subtree_sz[node] = 1;
	for(auto i : Graph[node])
	{
		if(i == p)
			continue;
		precalc_sz(i, node, subtree_sz, Graph);
		subtree_sz[node] += subtree_sz[i];
	}
}

ll dp(int node, int p, int constraint, const vector<vi>& Graph, const vi& subtree_sz, vector<vi>& vis, vector<vl>& DP)
{
	if(vis[node][constraint])
		return DP[node][constraint];
	vis[node][constraint] = 1;

	ll ans = 0;

	if(constraint == 0)
	{
		// Only root is bad
		ans += 1;
		ans %= MOD;

		// Root is bad, in exactly one subtree at most one bad to root
		for(auto i : Graph[node])
		{
			if(i == p)
				continue;
			
			ans += dp(i, node, 1, Graph, subtree_sz, vis, DP);
			ans %= MOD;
		}

		// Root is good, at most one bad in way to root per subtree
		ll aux = 1;
		for(auto i : Graph[node])
		{
			if(i == p)
				continue;
			
			aux *= dp(i, node, 1, Graph, subtree_sz, vis, DP);
			aux %= MOD;
		}
		ans += aux;
		ans %= MOD;

		// Root is good, exactly 2 bad in way to root in one subtree
		for(auto i : Graph[node])
		{
			if(i == p)
				continue;
			
			ans += dp(i, node, 2, Graph, subtree_sz, vis, DP);
			ans %= MOD;
		}
	}
	else if(constraint == 1)
	{
		// Only root is bad
		ans += 1;
		ans %= MOD;

		// Root is good, at most one bad in way to root per subtree
		ll aux = 1;
		for(auto i : Graph[node])
		{
			if(i == p)
				continue;
			
			aux *= dp(i, node, 1, Graph, subtree_sz, vis, DP);
			aux %= MOD;
		}
		ans += aux;
		ans %= MOD;
	}
	else if(constraint == 2)
	{
		// Root is bad, in exactly one subtree exactly one bad to root
		for(auto i : Graph[node])
		{
			if(i == p)
				continue;
			
			ans += dp(i, node, 1, Graph, subtree_sz, vis, DP);
			ans %= MOD;
		}
		ans--;
		ans = ((ans%MOD)+MOD)%MOD;

		// Root is good, exactly 2 bad in way to root in one subtree
		for(auto i : Graph[node])
		{
			if(i == p)
				continue;
			
			ans += dp(i, node, 2, Graph, subtree_sz, vis, DP);
			ans %= MOD;
		}
	}

	dbg(node, p, constraint, ans);
	return DP[node][constraint] = ans;
}

void solve()
{
	int N;
	cin >> N;
	vector<vi> Graph(N + 1);
	for(int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}

	vi subtree_sz(N + 1, 0);
	precalc_sz(1, -1, subtree_sz, Graph);

	vector<vl> DP(N + 1, vl(3, 0));
	vector<vi> vis(N + 1, vi(3, 0));
	cout << dp(1, -1, 0, Graph, subtree_sz, vis, DP) << "\n";
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


