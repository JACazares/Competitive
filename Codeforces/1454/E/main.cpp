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

#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define pb push_back
#define fst first
#define snd second

int pct(int x) { return __builtin_popcount(x); }

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
#define openFiles() 0
#else
#define dbg(...) 0
#define optimizeIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define openFiles() freopen("file.in", "r", stdin); freopen("file.out", "w", stdout)
#endif

const int MAXN = 2e5 + 5;
int N, vis[MAXN], in_cyc[MAXN];
vi Graph[MAXN], cyc;

int cycle(int node, int p = 0)
{
    if(vis[node])
        return node;
    vis[node] = 1;

    int res = -1;
    for(auto i : Graph[node])
        if(i != p)
        {
            res = cycle(i, node);
            if(res != -1)
                break;
        }
    
    if(res > -1)
    {
        cyc.pb(node);
        in_cyc[node] = 1;
    }

    if(node == res)
        return -1;
    return res;
}

int dfs(int node, int p = 0)
{
    int ret = 1;
    for(auto i : Graph[node])
        if(i != p && !in_cyc[i])
            ret += dfs(i, node);
    return ret;
}

void solve()
{
    cin >> N;
    cyc.clear();
    for(int i = 1; i <= N; i++)
    {
        Graph[i].clear();
        vis[i] = 0;
        in_cyc[i] = 0;
    }
    for(int i = 0; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].pb(v);
        Graph[v].pb(u);
    }
    cycle(1);
    vl legs;
    for(auto i : cyc)
        legs.pb(dfs(i));
    
    dbg(cyc, legs);
    
    ll ans = 0, sum = 0;
    for(auto i : legs)
        sum += i - 1;
    for(auto i : legs)
    {
        //same leg
        ans += i*(i - 1)/2;
        
        //leg to somewhere (not cycle)
        ans += (i - 1) * (N - i - sz(cyc) + 1);
        
        //leg to cycle
        ans += 2 * (i - 1) * (sz(cyc) - 1);
    }

    ans += (sz(cyc) * (sz(cyc) - 1));
    cout << ans << "\n";
}

int main ()
{
    optimizeIO();
    //openFiles();
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/
