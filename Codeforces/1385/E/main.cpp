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
int N, M, vis[MAXN], used[MAXN], in[MAXN];
pii edges[MAXN];
vi Graph[MAXN], toposort;
vpi undir[MAXN], ans;

void topo()
{
    queue<int> Q;
    for(int i = 1; i <= N; i++)
        if(vis[i] && in[i] == 0)
            Q.push(i);
    
    while(!Q.empty())
    {
        int aux = Q.front();
        Q.pop();
        
        toposort.pb(aux);
        
        for(auto i : Graph[aux])
        {
            in[i]--;
            if(in[i] == 0)
                Q.push(i);
        }
    }
}

void solve()
{
    ans.clear();
    toposort.clear();
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        undir[i].clear();
        Graph[i].clear();
        vis[i] = 0;
        in[i] = 0;
    }
    for(int i = 0; i < M; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        used[i] = 0;
        if(t == 1)
        {
            Graph[x].pb(y);
            ans.pb({x, y});
            vis[x] = vis[y] = 1;
            in[y]++;
        }
        else
        {
            undir[x].pb({y, i});
            undir[y].pb({x, i});
            edges[i] = {x, y};
        }
    }
    topo();
    
    int nodes = 0;
    for(int i = 1; i <= N; i++)
        nodes += vis[i];
    if(toposort.size() != nodes)
    {
        cout << "NO\n";
        return;
    }
    
    for(auto i : toposort)
    {
        for(auto v : undir[i])
            if(!used[v.second])
            {
                used[v.second] = 1;
                ans.pb({i, v.first});
            }
    }
    for(int i = 1; i <= N; i++)
        if(!vis[i])
            for(auto v : undir[i])
                if(!used[v.second])
                {
                    used[v.second] = 1;
                    ans.pb({i, v.first});
                }
    cout << "YES\n";
    for(auto i : ans)
        cout << i.first << " " << i.second << "\n";
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

