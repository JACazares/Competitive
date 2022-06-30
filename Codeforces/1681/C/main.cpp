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

struct arr
{
	int f, s, idx;
	
	bool operator <(const arr& _x) const
	{
		if(f == _x.f)
			return s < _x.s;
		return f < _x.f;
	}
};

const int MAXN = 105;
int N, curr[MAXN];
arr a[MAXN];

void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> a[i].f;
	for(int i = 1; i <= N; i++)
		cin >> a[i].s;
		
	for(int i = 1; i <= N; i++)
	{
		a[i].idx = i;
		curr[i] = i;
	}
	
	sort(a + 1, a + N + 1);
	
	for(int i = 1; i <= N - 1; i++)
		if(a[i].s > a[i + 1].s)
		{
			cout << "-1\n";
			return;
		}
	
	vpi ans;
	ans.clear();
	for(int i = 1; i <= N; i++)
	{
		int id = a[i].idx;
		while(curr[id] != id)
			id = curr[id];
		if(id != i)
		{
			ans.pb({id, i});
			curr[i] = id;
		}
	}
		
	cout << sz(ans) << "\n";
	for(auto i : ans)
		cout << i.first << " " << i.second << "\n";
}

int main()
{
	optimizeIO();
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}
