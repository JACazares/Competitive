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

const int MAXN = 2e5 + 5;
int N, K, deg[MAXN], leaves[MAXN];
vi Graph[MAXN];

void solve()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        deg[i] = 0;
        leaves[i] = 0;
        Graph[i].clear();
    }
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].pb(v);
        Graph[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    
    if(K == 1)
    {
        cout << N - 1 << "\n";
        return;
    }
    
    queue<int> s;
    for(int i = 1; i <= N; i++)
    {
        if(deg[i] == 1)
            continue;
        for(auto j : Graph[i])
            if(deg[j] == 1)
                leaves[i]++;
        if(leaves[i] == deg[i] - 1 && leaves[i] % K == 0)
            s.push(i);
    }
    
    int ans = 0;
    while(!s.empty())
    {
        int aux = s.front();
        s.pop();

        if(leaves[aux] == deg[aux])
            continue;

        for(auto i : Graph[aux])
            if(deg[i] != 1)
            {
                leaves[i]++;
                if(deg[i] - 1 == leaves[i] && leaves[i] % K == 0)
                    s.push(i);
            }
            
        dbg(aux, leaves[aux], deg[aux]);

        ans += leaves[aux] / K;
        leaves[aux] = 0;
    }
    
    for(int i = 1; i <= N; i++)
    {
        ans += leaves[i] / K;
        leaves[i] %= K;
    }
    
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

