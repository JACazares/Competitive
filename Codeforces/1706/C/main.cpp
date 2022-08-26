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
int N;
ll a[MAXN], lft[MAXN], rgt[MAXN];

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i];
	for(int i = 0; i <= N + 1; i++)
		lft[i] = rgt[i] = 0;
	
	ll ans = 0;
	if(N%2 == 0)
	{
		// the partition can be anywhere
		for(int i = 2; i <= N; i += 2)
			lft[i] = lft[i - 2] + max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0LL);
		for(int i = N - 1; i >= 1; i -= 2)
			rgt[i] = rgt[i + 2] + max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0LL);
		
		ans = min(rgt[3], lft[N - 2]);
		for(int i = 2; i <= N - 4; i += 2)
			ans = min(ans, lft[i] + rgt[i + 3]);
	}
	else
	{
		for(int i = 2; i <= N; i += 2)
			ans += max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0LL);
	}
	cout << ans << "\n";
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
