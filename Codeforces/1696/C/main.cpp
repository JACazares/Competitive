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

const int MAXN = 5e4 + 5;
int N, K;
ll m;
pll a[MAXN], b[MAXN], c[MAXN], d[MAXN];

void solve()
{
	cin >> N >> m;
	for(int i = 0; i < N; i++)
	{
		ll x, cnt = 1;
		cin >> x;
		while(x % m == 0)
		{
			x /= m;
			cnt *= m;
		}
		a[i] = {x, cnt};
	}

	cin >> K;
	for(int i = 0; i < K; i++)
	{
		ll x, cnt = 1;
		cin >> x;
		while(x % m == 0)
		{
			x /= m;
			cnt *= m;
		}
		b[i] = {x, cnt};
	}
	
	int lpnt = 0;
	c[0] = a[0];
	for(int i = 1; i < N; i++)
	{
		if(c[lpnt].first == a[i].first)
			c[lpnt].second += a[i].second;
		else
			c[++lpnt] = a[i];
		dbg(lpnt, c[lpnt]);
	}
	
	int rpnt = 0;
	d[0] = b[0];
	for(int i = 1; i < K; i++)
	{
		if(d[rpnt].first == b[i].first)
			d[rpnt].second += b[i].second;
		else
			d[++rpnt] = b[i];
		dbg(rpnt, d[rpnt]);
	}
	
	if(lpnt != rpnt)
	{
		cout << "No\n";
		return;
	}
	for(int i = 0; i <= lpnt; i++)
		if(c[i] != d[i])
		{
			cout << "No\n";
			return;
		}
	cout << "Yes\n";
}

int main()
{
	optimizeIO();
	int T = 1;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
