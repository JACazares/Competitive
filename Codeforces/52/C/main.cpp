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
int N, a[MAXN], M;
ll ST[4*MAXN], lazy[4*MAXN];

void build(int node = 0, int l = 0, int r = N - 1)
{
    if(l == r)
    {
        ST[node] = a[l];
        return;
    }
    
    int mid = (l+r)/2, lchild = 2*node + 1, rchild = 2*node + 2;
    build(lchild, l, mid);
    build(rchild, mid + 1, r);
    ST[node] = min(ST[lchild], ST[rchild]);
}

void propagate(int node, int l, int r)
{
    ST[node] += lazy[node];
    if(l < r)
    {
        int lchild = 2*node + 1, rchild = 2*node + 2;
        lazy[lchild] += lazy[node];
        lazy[rchild] += lazy[node];
    }
    lazy[node] = 0;
}

void upd(int L, int R, int x, int node = 0, int l = 0, int r = N - 1)
{
    propagate(node, l, r);
    if(L <= l && r <= R)
    {
        lazy[node] = x;
        propagate(node, l, r);
        return;
    }
    if(r < L || R < l)
        return;
    
    int mid = (l+r)/2, lchild = 2*node + 1, rchild = 2*node + 2;
    upd(L, R, x, lchild, l, mid);
    upd(L, R, x, rchild, mid + 1, r);
    ST[node] = min(ST[lchild], ST[rchild]);
}

ll qry(int L, int R, int node = 0, int l = 0, int r = N - 1)
{
    propagate(node, l, r);
    if(L <= l && r <= R)
        return ST[node];
    if(r < L || R < l)
        return (1 << 30);
    
    int mid = (l+r)/2, lchild = 2*node + 1, rchild = 2*node + 2;
    return min(qry(L, R, lchild, l, mid), qry(L, R, rchild, mid + 1, r));
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    build();
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int l, r, x;
        char c;
        cin >> l;
        cin.get(c);
        cin >> r;
        cin.get(c);
        if(c == '\n')
        {
            if(l <= r)
                cout << qry(l, r) << "\n";
            else
                cout << min(qry(0, r), qry(l, N - 1)) << "\n";
        }
        else
        {
            cin >> x;
            cin.get(c);
            if(l <= r)
                upd(l, r, x);
            else
            {
                upd(0, r, x);
                upd(l, N - 1, x);
            }
        }
    }
    return 0;
}

/*
- if use ceil/floor, cast to int.
*/

