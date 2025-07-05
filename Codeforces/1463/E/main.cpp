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
#define sz(x) (int)x.size()
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

const int MAXN = 3e5 + 5;
int N, K, p[MAXN], par[MAXN], in[MAXN], in_deg[MAXN], ind[MAXN];
int ans = 1;
vi Graph[MAXN], G[MAXN], regions, out[MAXN], toposort;
map<pii, int> edge;

int look(int node)
{
    if(p[node] == node)
        return node;
    return p[node] = look(p[node]);
}

void join(int nodeA, int nodeB)
{
    p[look(nodeA)] = look(nodeB);
}

bool topo()
{
    queue<int> Q;
    for(auto i : regions)
        if(in_deg[i] == 0)
            Q.push(i);
    
    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        
        toposort.pb(node);

        for(auto i : Graph[node])
        {
            in_deg[i]--;
            if(in_deg[i] == 0)
                Q.push(i);
        }
    }
    
    return (toposort.size() == regions.size());
}

void dfs(int node)
{
    ind[node] = out[look(node)].size();
    out[look(node)].pb(node);
    if(G[node].size())
        dfs(G[node][0]);
}

int main ()
{
    optimizeIO();
    //openFiles();
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        cin >> par[i];
        p[i] = i;
    }
    for(int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        in[y]++;
        if(look(x) == look(y))
            ans = 0;
        join(x, y);
    }
    
    if(ans == 0)
    {
        cout << "0\n";
        return 0;
    }
    
    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            dfs(i);
    
    vi vis(N + 1, 0);
    for(int i = 1; i <= N; i++)
        if(!vis[look(i)])
        {
            vis[look(i)] = 1;
            regions.pb(look(i));
        }
    
    for(int i = 1; i <= N; i++)
    {
        if(par[i] != 0 && !edge[{look(par[i]), look(i)}])
        {
            if(look(par[i]) == look(i))
            {
                if(ind[par[i]] > ind[i])
                {
                    cout << "0\n";
                    return 0;
                }
            }
            else
            {
                Graph[look(par[i])].pb(look(i));
                edge[{look(par[i]), look(i)}] = 1;
                in_deg[look(i)]++;
            }
        }
    }
    
    if(topo())
    {
        for(auto i : toposort)
            for(auto j : out[i])
                cout << j << " ";
        cout << "\n";
    }
    else
        cout << "0\n";
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/
