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

const int MAXN = 2e3 + 5;
int N, DP[MAXN][MAXN], p_a[MAXN][MAXN], p_b[MAXN][MAXN];
vi Graph[MAXN];
vpi parejas[MAXN];
string S;

void dfs(int node, int root, int p = 0, int d = 0)
{
	// (root, node)
	if(root == node)
	{
		DP[root][node] = 1;
	}
	else if(root < node)
	{
		parejas[d].pb({root, node});
		p_b[root][node] = p;
	}
	else if(root > node)
	{
		p_a[node][root] = p;
	}
	
	for(auto i : Graph[node])
		if(i != p)
			dfs(i, root, node, d+1);
}

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		Graph[i].clear();
		parejas[i].clear();
		for(int j = 1; j <= N; j++)
		{
			DP[i][j] = 0;
			p_a[i][j] = 0;
			p_b[i][j] = 0;
		}
	}
	
	cin >> S;
	S = " " + S;
	for(int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	
	for(int i = 1; i <= N; i++)
		dfs(i, i);
	
	int ans = 1;
	for(int d = 1; d <= N; d++)
	{
		for(auto i : parejas[d])
		{
			int a = i.first, b = i.second;
			int pa = p_a[a][b], pb = p_b[a][b];
			DP[a][b] = max(DP[min(pa, b)][max(pa, b)], DP[min(a, pb)][max(a, pb)]);
			if(S[a] == S[b])
			{
				if(p_a[a][b] == b)
					DP[a][b] = max(DP[a][b], 2);
				else
					DP[a][b] = max(DP[a][b], DP[min(pa, pb)][max(pa, pb)] + 2);
			}
			
			ans = max(ans, DP[a][b]);
		}
	}
	cout << ans << "\n";
}

int main()
{
	optimizeIO();
	int T = 1;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
