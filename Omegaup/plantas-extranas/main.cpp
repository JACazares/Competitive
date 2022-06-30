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

const int MAXN = (int)1e5 + 5;
int N, u, q, a[MAXN], b[MAXN], BIT[MAXN];
vpi updates[MAXN], queries[MAXN];

void upd(int pos, int x)
{
	for(; pos <= N; pos += pos&-pos)
		BIT[pos] += x;
}

int qry(int pos)
{
	int ans = 0;
	for(; pos; pos -= pos&-pos)
		ans += BIT[pos];
	return ans;
}

int main()
{
	optimizeIO();
	cin >> N >> u >> q;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	for(int i = 1; i < N; i++)
	{
		b[i] = abs(a[i + 1] - a[i]);
		upd(i, b[i]);
	}
	
	for(int i = 0; i < u; i++)
	{
		int id, x, t;
		cin >> id >> x >> t;
		updates[t].pb({id, x});
	}
	for(int i = 0; i < q; i++)
	{
		int l, r, t;
		cin >> l >> r >> t;
		queries[t].pb({l, r});
	}
	
	for(int t = 1; t < MAXN; t++)
	{
		for(auto i : updates[t])
		{
			a[i.first] += i.second;
			if(i.first > 1)
			{
				upd(i.first - 1, -b[i.first - 1]);
				b[i.first - 1] = abs(a[i.first] - a[i.first - 1]);
				upd(i.first - 1, b[i.first - 1]);
			}
			if(i.first < N)
			{
				upd(i.first, -b[i.first]);
				b[i.first] = abs(a[i.first + 1] - a[i.first]);
				upd(i.first, b[i.first]);
			}
		}
		for(auto i : queries[t])
			cout << qry(i.second - 1) - qry(i.first - 1) << "\n";
	}
	return 0;
}
