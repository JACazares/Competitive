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
int N, f[MAXN], fib[MAXN], sz[MAXN], p[MAXN], dead[MAXN];
vi Graph[MAXN];

void pre(int node, int _p = 0)
{
	p[node] = _p;
	sz[node] = 1;
	for(auto i : Graph[node])
	{
		if(i == _p)
			continue;
		pre(i, node);
		sz[node] += sz[i];
	}
}

void dfs(int node)
{
	sz[node] = 1;
	for(auto i : Graph[node])
	{
		if(i == p[node] || dead[i])
			continue;
			
		dfs(i);
		sz[node] += sz[i];
	}
}

int look(int node, int x)
{
	if(sz[node] == x)
		return node;
	
	int ret = 0;
	for(auto i : Graph[node])
	{
		if(i == p[node] || dead[i])
			continue;
		ret = max(ret, look(i, x));
	}
	return ret;
}

bool solve(int node)
{
	if(sz[node] <= 3)
		return true;
	
		
	int fibo = fib[sz[node]];
	dbg(node, sz[node], fibo);
	if(fibo)
	{
		int ans1 = look(node, f[fibo - 1]);
		int ans2 = look(node, f[fibo - 2]);
		
		dbg(ans1, ans2);
		
		if(ans1)
		{
			dead[ans1] = 1;
			dfs(node);
			dfs(ans1);
			return min(solve(node), solve(ans1));
		}
		else if(ans2)
		{
			dead[ans2] = 1;
			dfs(node);
			dfs(ans2);
			return min(solve(node), solve(ans2));
		}
		else
			return false;
	}
	else
		return false;
}

int main()
{
	optimizeIO();
	cin >> N;
	for(int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}

	f[0] = 1;
	f[1] = 1;
	for(int i = 2; true; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		dbg(f[i]);
		if(f[i] > N)
			break;
		fib[f[i]] = i;
	}
	pre(1);
	cout << (solve(1) ? "YES" : "NO") << "\n";
	return 0;
}
