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

struct Node
{
    int a, b, c, idx;
    
    bool operator <(const Node& _x) const
    {
        if(a == _x.a)
            return idx < _x.idx;
        return a < _x.a;
    }
};

const int MAXN = 2e5 + 5;
int N, tim, bitZ[MAXN], bitO[MAXN], bit[MAXN], in[MAXN], out[MAXN];
Node dat[MAXN];
vi Graph[MAXN], zero, one;

void pre(int node, int p = -1)
{
    in[node] = ++tim;
    for(auto i : Graph[node])
        if(i != p)
            pre(i, node);
    out[node] = tim;
}

void updZ(int pos, int x)
{
    for(; pos <= N + 1; pos += pos&(-pos))
        bitZ[pos] += x;
}

void updO(int pos, int x)
{
    for(; pos <= N + 1; pos += pos&(-pos))
        bitO[pos] += x;
}

void upd(int pos, int x)
{
    for(; pos <= N + 1; pos += pos&(-pos))
        bit[pos] += x;
}

int qryZ(int pos)
{
    int ret = 0;
    for(; pos; pos -= pos&(-pos))
        ret += bitZ[pos];
    return ret;
}

int qryO(int pos)
{
    int ret = 0;
    for(; pos; pos -= pos&(-pos))
        ret += bitO[pos];
    return ret;
}

int qry(int pos)
{
    int ret = 0;
    for(; pos; pos -= pos&(-pos))
        ret += bit[pos];
    return ret;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; 
    for(int i = 1; i <= N; i++)
    {
        cin >> dat[i].a >> dat[i].b >> dat[i].c;
        dat[i].idx = i;
        if(dat[i].b == 0 && dat[i].c == 1)
            zero.pb(i);
        if(dat[i].b == 1 && dat[i].c == 0)
            one.pb(i);
    }
    sort(dat + 1, dat + N + 1);
    for(int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].pb(v);
        Graph[v].pb(u);
    }
    pre(1);
    for(auto i : zero)
    {
        dbg(i, in[i]);
        updZ(in[i], 1);
    }
    dbg("");
    for(auto i : one)
    {
        dbg(i, in[i]);
        updO(in[i], 1);
    }
    
    ll ans = 0;
    for(int i = 1; i <= N; i++)
    {
        int node = dat[i].idx;
        if(qry(in[dat[i].idx]) > 0)
            continue;
        upd(in[dat[i].idx], 1);
        upd(out[dat[i].idx] + 1, -1);
        dbg(in[node], out[node]);
        int sumZ = qryZ(out[node]) - qryZ(in[node] - 1);
        int sumO = qryO(out[node]) - qryO(in[node] - 1);
        dbg(sumZ, sumO, node);
        int minim = min(sumZ, sumO);

        ans += (ll)dat[i].a * 2LL * (ll)minim;
        dbg(ans);
        updZ(in[node], -minim);
        updO(in[node], -minim);
    }
    
    if(qryZ(out[1]) != 0 || qryO(out[1]) != 0)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

