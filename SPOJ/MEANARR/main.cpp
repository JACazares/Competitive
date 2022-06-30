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

const int MAXN = (int)2e5 + 5;
ll N, K, a[MAXN], pre[MAXN], BIT[MAXN];
vl b;
map<ll, int> MP;

void upd(int x)
{
	for(; x <= N + 1; x += x&-x)
		BIT[x]++;
}

ll qry(int x)
{
	ll ans = 0;
	for(; x; x -= x&-x)
		ans += BIT[x];
	return ans;
}

int main()
{
	optimizeIO();
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
	{
		cin >> a[i];
		a[i] -= K;
		pre[i] = pre[i - 1] + a[i];
		b.pb(pre[i]);
	}
	b.pb(0);
	sort(all(b));
	for(int i = 0; i < sz(b); i++)
		MP[b[i]] = i + 1;
	for(int i = 0; i <= N; i++)
		pre[i] = MP[pre[i]];
	upd(pre[0]);
	ll ans = 0;
	for(int i = 1; i <= N; i++)
	{
		ans += qry(pre[i]);
		upd(pre[i]);
	}
	cout << ans << "\n";
	return 0;
}
