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

struct Node
{
    ll maxim, tot_c, fill;
};

const int MAXN = 2e5 + 5;
int N;
ll a[MAXN];
vi Graph[MAXN];

Node dfs(int node, int p = 0)
{
    vector<Node> child;
    ll maxim = 0;
    for(auto i : Graph[node])
        if(i != p)
        {
            child.pb(dfs(i, node));
            maxim = max(maxim, child[sz(child) - 1].maxim);
        }
    
    int c = child.size();
    if(!c)
        return Node{a[node], 1, 0};
    
    ll fill = 0, tot_c = 0;
    for(auto i : child)
    {
        fill += i.fill + ((maxim - i.maxim) * i.tot_c);
        tot_c += i.tot_c;
    }
    
    if(fill >= a[node])
        return Node{maxim, tot_c, fill - a[node]};
    else
    {
        ll res = a[node] - fill;
        return Node{maxim + res/c + (res%c ? 1 : 0), tot_c, (tot_c - res%c) % tot_c};
    }
}

int main ()
{
    optimizeIO();
    //openFiles();
    cin >> N;
    for(int i = 2; i <= N; i++)
    {
        int v;
        cin >> v;
        Graph[i].pb(v);
        Graph[v].pb(i);
    }
    for(int i = 1; i <= N; i++)
        cin >> a[i];
    
    cout << dfs(1).maxim << "\n";
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/
