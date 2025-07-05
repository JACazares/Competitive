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
int N, a[2][MAXN], p[MAXN], sz[MAXN], vis[MAXN], c[MAXN], used[MAXN];
vi row[MAXN], col[MAXN], black, white, res;
vpi edges, Graph[MAXN];

int look(int node)
{
    if(p[node] == node)
        return node;
    return p[node] = look(p[node]);
}

void join(int _a, int _b)
{
    sz[look(_b)] += sz[look(_a)];
    p[look(_a)] = look(_b);
}

int bipartite(int node, int color)
{
    dbg(node, color);
    if(vis[node])
    {
        if(c[node] != color)
            return 0;
        return 1;
    }
    c[node] = color;
    vis[node] = 1;

    if(color == 0)
        white.pb(node);
    else
        black.pb(node);
    
    int aux = 1;
    for(auto i : Graph[node])
        aux = min(aux, bipartite(i.first, color ^ 1));
    return aux;
}

void solve()
{
    edges.clear();
    res.clear();
    cin >> N;
    for(int i = 0; i <= N; i++)
    {
        row[i].clear();
        col[i].clear();
        p[i] = i;
        sz[i] = 1;
        vis[i] = 0;
        c[i] = 0;
        used[i] = 0;
        Graph[i].clear();
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < N; j++)
        {
            cin >> a[i][j];
            row[a[i][j]].pb(i);
            col[a[i][j]].pb(j);
        }

    bool ans = 1;
    for(int i = 1; i <= N; i++)
    {
        if(row[i].size() != 2)
        {
            ans = 0;
            break;
        }

        if(row[i][0] == row[i][1])
            edges.pb({col[i][0], col[i][1]});
        else
            join(col[i][0], col[i][1]);
    }

    for(int i = 0; i < N; i++)
        dbg(look(i));
    
    if(!ans)
    {
        cout << "-1\n";
        return;
    }
    
    for(auto i : edges)
    {
        Graph[look(i.first)].pb({look(i.second), i.second});
        Graph[look(i.second)].pb({look(i.first), i.first});
    }

    for(auto i : edges)
    {
        if(!vis[look(i.first)])
        {
            black.clear();
            white.clear();
            if(!bipartite(look(i.first), 0))
            {
                ans = 0;
                break;
            }

            int bz = 0, wz = 0;
            for(auto j : black)
                bz += sz[j];
            for(auto j : white)
                wz += sz[j];

            if(bz < wz)
            {
                for(auto j : black)
                    res.pb(j);
            }
            else
            {
                for(auto j : white)
                    res.pb(j);
            }
        }
    }
    
    if(!ans)
    {
        cout << "-1\n";
        return;
    }
    for(auto i : res)
    {
        dbg(i);
        used[i] = 1;
    }
    
    vi res2;
    for(int i = 0; i < N; i++)
        if(used[look(i)])
            res2.pb(i);

    cout << res2.size() << "\n";
    for(auto i : res2)
        cout << i + 1 << " ";
    cout << "\n";
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

