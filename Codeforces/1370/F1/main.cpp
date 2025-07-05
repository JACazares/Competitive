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

const int MAXN = 1e3 + 5;
int N, par[MAXN], ancestor[MAXN], maxD, maxDe[MAXN];
vi Graph[MAXN], dist[MAXN], qry;

void pre(int node, int p = 0, int d = 0, int anc = 0)
{
    par[node] = p;
    if(d == 1)
        anc = node;
    dist[d].pb(node);
    ancestor[node] = anc;
    maxD = max(maxD, d);
    maxDe[anc] = max(maxDe[anc], d);
    for(auto i : Graph[node])
        if(i != p)
            pre(i, node, d + 1, anc);

    dbg(node, ancestor[node], d);
}

pii mkqry()
{
    if(qry.size() == 0)
        return {0, 0};
    cout << "? " << qry.size() << " ";
    for(auto i : qry)
        cout << i << " ";
    cout << endl;
    fflush(stdout);
    int node, distance;
    cin >> node >> distance;
    if(node == -1)
        exit(0);
    return {node, distance};
}

void solve()
{
    cin >> N;
    for(int i = 0; i <= N; i++)
    {
        Graph[i].clear();
        dist[i].clear();
        par[i] = 0;
        ancestor[i] = 0;
    }
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].pb(v);
        Graph[v].pb(u);
    }
    
    qry.clear();
    for(int i = 1; i <= N; i++)
        qry.pb(i);
    pii aux = mkqry();
    int k = aux.first;
    int minim = aux.second;
    maxD = 0;
    for(int i = 1; i <= N; i++)
        maxDe[i] = 0;
    pre(k);
    
    int s = 0, e = min(minim, maxD), mid, val, ans = 0, ansNode = k, it = 0, curr = 0;
    while(s <= e)
    {
        it++;
        mid = (s + e + 1) / 2;
        
        dbg(s, e, mid);
        
        if(it == 1)
        {
            qry.clear();
            for(auto i : dist[mid])
                qry.pb(i);
            aux = mkqry();
            curr = ancestor[aux.first];
            e = min(e, maxDe[curr]);
            val = 1;
        }
        else
        {
            qry.clear();
            for(auto i : dist[mid])
                if(ancestor[i] == curr)
                    qry.pb(i);
            aux = mkqry();
            if(aux.second == minim)
                val = 1;
            else
                val = 0;
        }
        
        if(val)
        {
            ans = mid;
            ansNode = aux.first;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    
    qry.clear();
    for(auto i : dist[minim - ans])
        if(ancestor[i] != curr)
            qry.pb(i);
    aux = mkqry();
    cout << "! " << ansNode << " " << aux.first << endl;
    fflush(stdout);
    string str;
    cin >> str;
    if(str[0] == 'I')
        exit(0);
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
