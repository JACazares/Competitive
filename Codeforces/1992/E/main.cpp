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

const int MAXN = 105;
vpi ans[MAXN];

void solve()
{
    int N;
    cin >> N;
    
    cout << ans[N].size() << "\n";
    for(auto [a, b] : ans[N])
        cout << a << " " << b << "\n";
}

int main()
{
	optimizeIO();
    for(int i = 2; i <= 10000; i++)
        ans[1].pb({i, i-1});
    ans[2].pb({20,18});
    ans[2].pb({219,216});
    ans[2].pb({2218,2214});
    ans[3].pb({165,162});
    ans[4].pb({14,12});
    ans[4].pb({147,144});
    ans[4].pb({1480,1476});
    ans[5].pb({138,135});
    ans[7].pb({129,126});
    ans[10].pb({1262,2519});
    ans[11].pb({12,21});
    ans[11].pb({123,242});
    ans[11].pb({1234,2463});
    ans[13].pb({119,234});
    ans[14].pb({1178,2351});
    ans[16].pb({1154,2303});
    ans[18].pb({1136,2267});
    ans[20].pb({112,220});
    ans[21].pb({11,19});
    ans[24].pb({110,216});
    ans[35].pb({107,210});
    ans[68].pb({104,204});
    ans[90].pb({1033,2061});
    ans[94].pb({1032,2059});
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}