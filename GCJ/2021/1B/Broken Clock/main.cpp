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

ll A, B, C;

bool solve(ll h, ll m, ll s)
{
	m += (ll)(h/3600)*43200;
	s += (ll)(m/720)*43200;
	
	if(12*h == m && h*720 == s)
		return 1;
	return 0;
}

void solve()
{
	cin >> A >> B >> C;
	A /= (ll)1e9;
	B /= (ll)1e9;
	C /= (ll)1e9;
	
	for(int i = 0; i < 3600*12; i++)
	{
		if(solve(A, B, C))
		{
			cout << A/3600 << " " << B/720 << " " << C/720 << " 0\n";
			return;
		}
		if(solve(A, C, B))
		{
			cout << A/3600 << " " << C/720 << " " << B/720 << " 0\n";
			return;
		}
		if(solve(B, A, C))
		{
			cout << B/3600 << " " << A/720 << " " << C/720 << " 0\n";
			return;
		}
		if(solve(B, C, A))
		{
			cout << B/3600 << " " << C/720 << " " << A/720 << " 0\n";
			return;
		}
		if(solve(C, A, B))
		{
			cout << C/3600 << " " << A/720 << " " << B/720 << " 0\n";
			return;
		}
		if(solve(C, B, A))
		{
			cout << C/3600 << " " << B/720 << " " << A/720 << " 0\n";
			return;
		}
		A++; B++, C++;
		A %= 43200;
		B %= 43200;
		C %= 43200;
	}
	cout << "IMPOSSIBLE\n";
	return;
}

int main()
{
	optimizeIO();
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
